import cv2

img = cv2.imread("calen.png",0)
img = cv2.resize(img,(400,400))

cv2.imshow("Image",img)
cv2.waitKey(0)
cv2.destroyAllWindows()