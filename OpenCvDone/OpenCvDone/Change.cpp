#include "Change.h"
using namespace std;
Change::Change()
{
}

Change::Change(Image img)
{
	this->rows = img.rows;
	this->cols = img.cols;
	this->a = new int** [rows];
	this->b = new int** [rows];
	for (int i = 0; i < rows; i++) {
		this->a[i] = new int* [cols];
		this->b[i] = new int* [cols];
		for (int j = 0; j < cols; j++) {
			this->a[i][j] = new int[CHANNEL_RGB_COLOR];
			this->b[i][j] = new int[CHANNEL_RGB_COLOR];
		}
	}
	for (int indexRow = 0; indexRow < img.rows; indexRow++) {
		for (int indexCol = 0; indexCol < img.cols; indexCol++) {
			for (int channel = 0; channel < CHANNEL_RGB_COLOR; channel++) {
				a[indexRow][indexCol][channel] = (int)img.imageDst.at<Vec3b>(indexRow, indexCol)[channel];
			}
		}
	}
}

Change::Change(const Change& change)
{

}

void Change::output()
{
	// PRINT PIXEL OF RED COLOR 
	cout << "------------" << endl;
	cout << "Before" << endl;
	cout << "------------" << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
			cout << setw(4) << a[i][j][CHANNEL_R_COLOR];
		cout << endl;
	}
	cout << "------------" << endl;
	cout << "After" << endl;
	cout << "------------" << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
			cout << setw(4) << b[i][j][CHANNEL_R_COLOR];
		cout << endl;
	}
}

void Change::set(Image& img)
{
	int* temp = new int[9];
	for (int channel = 0; channel < CHANNEL_RGB_COLOR; channel++) {
		for (int i = 0; i < this->rows; i++) {
			for (int j = 0; j < this->cols; j++) {
				int k = 0;
				for (int ii = i - 1; ii <= i + 1; ii++) {
					if (ii < 0 || ii>this->rows - 1) continue;
					for (int jj = j - 1; jj <= j + 1; jj++) {
						if (jj < 0 || jj>this->cols - 1) continue;
						temp[k] = a[ii][jj][channel];
						k++;
					}
				}
				this->b[i][j][channel] = trungvi(temp, k);
				img.imageDst.at<Vec3b>(i, j)[channel] = saturate_cast<uchar>(b[i][j][channel]);
			}
		}
	}
}
void Change::hoanvi(int& a, int& b) {
	a ^= b ^= a ^= b;
}
int Change::trungvi(int* a, int k) {
	for (int i = 0; i < k - 1; i++) {
		for (int j = i + 1; j < k; j++)
			if (a[i] > a[j]) hoanvi(a[i], a[j]);
	}
	return a[(k - 1) / 2];
}

Change::~Change()
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < rows; j++) {
			delete[] a[i][j];
			delete[] b[i][j];
		}
		for (int i = 0; i < rows; i++) {
			delete[] a[i];
			delete[] a[i];
		}
		delete[] a;
		delete[] b;
	}
}