#include "stdafx.h"
#include "ImageProcessing.h"

ImageProcessing::ImageProcessing() 
{

}

ImageProcessing::ImageProcessing(string filePath)
{
	assert(filePath.length() > 0);
	this->__imagePath = filePath;
	this->__image = imread(filePath, CV_LOAD_IMAGE_GRAYSCALE);
	assert((__image.cols == SIZE_OF_IMAGE) && (__image.rows == SIZE_OF_IMAGE));
}

ImageProcessing::~ImageProcessing() 
{

}

void ImageProcessing::setImagePath(string imagePath)
{
	this->__imagePath = imagePath;
}

string ImageProcessing::getImagePath() 
{
	return this->__imagePath;
}
vector<unsigned int> ImageProcessing::normalizeImage()
{
	this->__image = imread(this->__imagePath, CV_LOAD_IMAGE_GRAYSCALE);
	assert(!__image.empty());
	vector<unsigned int> imgVector;

	Mat img;
	cv::threshold(__image, img, 240, 255, CV_THRESH_BINARY_INV);
	
	int idx, jdx;
	for (idx = 0; idx < 32; idx++) {
		for (jdx= 0; jdx < 32; jdx++) {
			if ( img.at<uchar>(idx, jdx) == 255 ) {
				if (img.channels() == 1) {
					img.at<uchar>(idx, jdx) = 1;
				} else if (img.channels() == 3) {
					img.at<Vec3b>(idx, jdx)[0] = 1;
					img.at<Vec3b>(idx, jdx)[1] = 1;
					img.at<Vec3b>(idx, jdx)[2] = 1;
				}
			}
		}
	}

	unsigned int totalPixel;
	for (idx = 0 ; idx < 8; idx++) {
		for (jdx = 0; jdx < 8; jdx++) {
			Rect mask(jdx*4, idx*4, 4, 4);
			Mat cell = img(mask).clone();
			totalPixel = cv::sum(cell)[0];
			imgVector.push_back(totalPixel);
		}
	}
	
	return imgVector;
}
