#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "../Data/ReadDataTest.h"
#include "../Data/ReadDataTraining.h"
#include "../Data/Utils.h"

using namespace std;

class KNN {
private:
	string __filePathTraining;
	string __filePathTest;
	int __k;

	vector<Image*> __dataTraining;
	vector<Image*> __dataTest;

	string __txtEstimate;
public:
	KNN(string filePathTraining, string filePathTest, int k);
	float estimate();
	int predict(Image* example); 

	void setTxtEstimate(string txt);
	string getTxtEstimate();
private:
	float __euclidDistance(Image* image1, Image* image2);
};