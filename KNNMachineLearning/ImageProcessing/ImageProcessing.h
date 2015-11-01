#include <iostream>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <vector>
#include "../Data/Utils.h"

using namespace cv;
using namespace std;

class ImageProcessing
{
private:
	string __imagePath;
	Mat __image;
public:
	ImageProcessing();
	ImageProcessing(String filePath);
	~ImageProcessing();
	void setImagePath(string imagePath);
	string getImagePath();
	vector<unsigned int> normalizeImage();
};