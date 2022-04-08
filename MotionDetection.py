import cv2 as cv

reference_frame = None
cap = cv.VideoCapture(0)

while True:
    # Capture frame-by-frame
    ret, frame = cap.read()

    # Operations
    grayscale = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)
    blur = cv.GaussianBlur(grayscale, (5, 5), 0)

    # Set the reference frame
    if reference_frame is None:
        reference_frame = blur
        continue

    absDiff = cv.absdiff(reference_frame, blur)
    binaryThreshold = cv.threshold(absDiff, 25, 255, cv.THRESH_BINARY)[1]
    dilated = cv.dilate(binaryThreshold, None, iterations=2)

    # Find all contours in the frame
    contours, hierarchy = cv.findContours(dilated.copy(), cv.RETR_EXTERNAL, cv.CHAIN_APPROX_SIMPLE)
    for contour in contours:
        if cv.contourArea(contour) < 2000:
            continue
        (x, y, w, h) = cv.boundingRect(contour)

        # Draw rectangles to indicate the contours
        cv.rectangle(frame, (x, y), (x + w, y + h), (0, 0, 255), 1)

    # Outputs of processed frames. The motion detection window
    # shows the final result of this program.
    cv.imshow("Grayscale", grayscale)
    cv.imshow("Absolute Difference", absDiff)
    cv.imshow("Binary Threshold", binaryThreshold)
    cv.imshow("Motion Detection", frame)

    key = cv.waitKey(1)

cap.release()
cv.destroyAllWindows()


# Legacy Code
'''
firstImage = cv.imread('image1.jpg')
secondImage = cv.imread('image2.jpg')
detectedMotion = cv.imread('image2.jpg')

firstgrayscale = cv.cvtColor(firstImage, cv.COLOR_BGR2GRAY)
secondgrayscale = cv.cvtColor(secondImage, cv.COLOR_BGR2GRAY)
cv.imwrite('grayscaleImage1.png', firstgrayscale)
cv.imwrite('grayscaleImage2.png', secondgrayscale)

firstBlur = cv.GaussianBlur(firstgrayscale,(5,5),0)
secondBlur = cv.GaussianBlur(secondgrayscale,(5,5),0)
cv.imwrite('blurImage1.png', firstBlur)
cv.imwrite('blurImage2.png', secondBlur)

absDiff = cv.absdiff(firstBlur, secondBlur)
cv.imwrite('absDiff.png', absDiff)

binaryThreshold = cv.threshold(absDiff, 25, 255, cv.THRESH_BINARY)[1]
cv.imwrite('BinaryThreshold.png', binaryThreshold)

dilated = cv.dilate(binaryThreshold, None, iterations = 2)
contours, hierarchy = cv.findContours(dilated.copy(), cv.RETR_EXTERNAL, cv.CHAIN_APPROX_SIMPLE)

for contour in contours:
  if cv.contourArea(contour) < 2000:
    continue
  (x, y, w, h) = cv.boundingRect(contour)

  cv.rectangle(detectedMotion, (x, y), (x + w, y + h), (0, 0, 255), 1)

cv.imwrite('detectedMotion.jpg', detectedMotion)


There are three arguments in cv.findContours() function, first one is source
image, second is contour retrieval mode, third is contour approximation method.
And it outputs a modified image, the contours and hierarchy. contours is a 
Python list of all the contours in the image. Each individual contour is a 
Numpy array of (x,y) coordinates of boundary points of the object.


def findContours(image):
  contours = cv.findContours(image, cv.RETR_TREE, cv.CHAIN_APPROX_SIMPLE)
  def filt(cont):
    (_, _, w, h) = cv.boundingRect(cont)
    return w * h >= 500
  return filter(filt, contours)

def drawContours(dest, contours):
  for contour in contours:
    (x, y, w, h) = cv.boundingRect(contour)
    # draw a blue rectangle for each contour area
    cv.rectangle(dest, (x, y), (x + w, y + h), (0, 0, 255), 1)

contours = findContours(dilated)
# replace firstImage with inframe1 for video/camera if needed
#out = cv.cvtColor(firstImage, cv.COLOR_GRAY2BGR)
drawContours(firstImage, contours)


for i in controus:
  if cv.contoursArea(i) < 2000:
    continue
  (x, y, w, h) = cv.boundingRect(i)

  cv.rectangle(vga.))
'''
