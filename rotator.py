import os
import argparse
import cv2
import numpy as np
import scipy
from scipy import ndimage



# load each of the images from disk one by one
img = cv2.imread('sloth_comp_read.cpp/squishedsloths/out.jpg',0)
img1 = cv2.imread('sloth_comp_read.cpp/squishedsloths/out1.jpg',0)
img2 = cv2.imread('sloth_comp_read.cpp/squishedsloths/out2.jpg',0)
img3 = cv2.imread('sloth_comp_read.cpp/squishedsloths/out3.jpg',0)

#rows and cols defined by shape that was gathered by the images through cv2 and numpy
rows,cols = img.shape
rows,cols = img1.shape
rows,cols = img2.shape
rows,cols = img3.shape



#actual rotation matrix in opencv, 0-->360, for out purposes i used 90
M = cv2.getRotationMatrix2D((cols/2,rows/2),90,1)
dst = cv2.warpAffine(img,M,(cols,rows))

M = cv2.getRotationMatrix2D((cols/2,rows/2),90,1)
dst1 = cv2.warpAffine(img1,M,(cols,rows))

M = cv2.getRotationMatrix2D((cols/2,rows/2),90,1)
dst2 = cv2.warpAffine(img2,M,(cols,rows))

M = cv2.getRotationMatrix2D((cols/2,rows/2),90,1)
dst3 = cv2.warpAffine(img3,M,(cols,rows))


"""cv2.imshow('img',dst)
cv2.waitKey(0)
cv2.destroyAllWindows()"""

#saves the image after it's gone through the rotation matrix.
save = cv2.imwrite('sloth_comp_read.cpp/rotated/rotated.jpg', dst)
save1 = cv2.imwrite('sloth_comp_read.cpp/rotated/rotated1.jpg', dst1)
save2 = cv2.imwrite('sloth_comp_read.cpp/rotated/rotated2.jpg', dst2)
save3 = cv2.imwrite('sloth_comp_read.cpp/rotated/rotated3.jpg', dst3)
