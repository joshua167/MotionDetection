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
