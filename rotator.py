import os
import argparse
import cv2
import numpy as np
import scipy
from scipy import ndimage



# load the image from disk

img = cv2.imread('out.jpg',0)
rows,cols = img.shape

M = cv2.getRotationMatrix2D((cols/2,rows/2),90,1)
dst = cv2.warpAffine(img,M,(cols,rows))


"""cv2.imshow('img',dst)
cv2.waitKey(0)
cv2.destroyAllWindows()"""

save = cv2.imwrite('rotated.jpg', dst)

print('hello')
