#include "Image.h"

Image::Image()
{
	image = imread("test.png");
	imageDst = image.clone(); // sao chép 2 Mat
	this->rows = image.rows;
	this->cols = image.cols;
}

Image::Image(string& imageName)
{
	image = imread(imageName);
	imageDst = image.clone(); // sao chép 2 Mat
	// Check for valid
	if (!image.data)
	{
		printf("Could not open or find the image\n");
		imageName = "-1";
	}
	this->rows = image.rows;
	this->cols = image.cols;
}

Image::Image(const Image& copy)
{
	this->image = copy.image.clone();
	this->imageDst = copy.imageDst.clone();
	this->rows = copy.rows;
	this->cols = copy.cols;
}

void Image::showImage()
{
	cv::resize(image, image, cv::Size(Size_Enlarge, Size_Enlarge));
	cv::resize(imageDst, imageDst, cv::Size(Size_Enlarge, Size_Enlarge));

	imshow("Before", image);
	imshow("After", imageDst);
	imwrite("OutputImage.png", imageDst);
}



