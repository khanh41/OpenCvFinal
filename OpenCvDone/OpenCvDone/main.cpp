#include <iostream>
#include<iomanip>
#include"Change.h"
#include"Image.h"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
using namespace std;
using namespace cv;

#define DefaultSize 250
#define PositionUp DefaultSize+50
#define FirstPositionX 50
#define FirstPositionY 50
void ListImage();
int main()
{
	// Read image
	Image image;
	string fileName = "test.png";
	ListImage();
	waitKey(25);//25ms
	do {
		cout << "Nhap ten anh can chinh hoac URL(VD: C:/Users/TechCare/Desktop/test3.png)" << endl;
		cin >> fileName;
		Image image2(fileName);
		image = image2;
	} while (fileName == "-1");
	Change change(image);
	change.set(image);
	change.output();
	image.showImage();
	waitKey(0);

	return 0;
}
void ListImage() {
	std::string fileName[] = { "fire.png","gray.jfif","green.png","red.png","test.png","thuxem.png" };
	float positionX = FirstPositionX, positionY = FirstPositionY;
	Mat image;
	int i = 6;
	int size = sizeof(fileName) / sizeof(fileName[0]);
	for (int i = 0; i < size; i++) {
		image = imread(fileName[i]);
		cv::namedWindow(fileName[i]);
		cv::moveWindow(fileName[i], positionX, positionY);
		cv::resize(image, image, cv::Size(DefaultSize, DefaultSize));
		imshow(fileName[i], image);
		if (positionX >= 750) {
			positionX = FirstPositionX;
			positionY += PositionUp;
		}
		else {
			positionX += PositionUp;
		}
	}
}