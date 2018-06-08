import numpy as np
import matplotlib.pyplot as plt
from PIL import Image
import os

def applyKernel(img, kernel):
	newImg = np.zeros(img.shape)
	for i in range(1, img.shape[0]-1):
		for j in range(1, img.shape[1]-1):
			newImg[i][j] = sum( sum( img[i-1:i+2,j-1:j+2] * kernel ) )
	return newImg


os.chdir('images')
image = 'me.jpg'
img = np.asarray(Image.open(image).convert('L'))

blurKernel = np.array([[0.0625, 0.125 , 0.0625],
				       [0.125 , 0.25  , 0.125 ],
				       [0.0625, 0.125 , 0.0625]])

sharpen    = np.array([[0, -1 , 0],
				       [-1, 5 , -1],
				       [0, -1 , 0]])

empose = np.array([[-2,-1,0],
				   [-1,1 ,1],
				   [0 ,1 ,2]])

newImg = applyKernel(img, empose)

f, axs = plt.subplots(1, 2)

axs[0].imshow(img, cmap='gray')
axs[1].imshow(newImg, cmap='gray')

plt.show()