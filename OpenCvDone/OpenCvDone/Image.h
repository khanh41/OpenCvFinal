#pragma once
#include<iostream>
#include<iomanip>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;
using namespace cv;

#define Size_Enlarge 500
class Image
{
public:
	Mat image;
	Mat imageDst; //sao chép 2 Mat
	int rows, cols;
public:
	Image();
	Image(string&);
	Image(const Image&);
	void showImage();
};