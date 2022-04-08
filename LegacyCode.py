# These code were written in the progress of making this project.
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
