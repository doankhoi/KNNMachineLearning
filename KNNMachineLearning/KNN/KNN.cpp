#include "stdafx.h"
#include "KNN.h"

bool compareImage(Image* image1, Image* image2)
{
	 return (image1->getDistance() < image2->getDistance()) ? true : false;
}

KNN::KNN(string filePathTraining, string filePathTest, int k)
{
	this->__filePathTraining = filePathTraining;
	this->__filePathTest = filePathTest;
	this->__k = k;

	ReadDataTraining readDataTraining(filePathTraining, NUMBER_OF_ATTRIBUTES, NUMBER_OF_IMAGES_TRAINING);
	ReadDataTest readDataTest(filePathTest, NUMBER_OF_ATTRIBUTES, NUMBER_OF_IMAGES_TEST);
	this->__dataTraining = readDataTraining.getDataTraining();
	this->__dataTest = readDataTest.getDataTest();
}

float KNN::estimate()
{
	vector<Image*>::iterator itTestBegin = this->__dataTest.begin();
	vector<Image*>::iterator itTestEnd = this->__dataTest.end();
	int countRight = 0;
	int actualValue;
	int desertValue;
	while (itTestBegin != itTestEnd)
	{
		actualValue = this->predict(*itTestBegin);
		desertValue = (*itTestBegin)->getLabel();
		if (actualValue == desertValue) {
			countRight++;
		}

		itTestBegin++;
	}

	return (1.0f*countRight)/NUMBER_OF_IMAGES_TEST;
}

int KNN::predict(Image* example)
{
	vector<Image*>::iterator dataItBegin = this->__dataTraining.begin();
	vector<Image*>::iterator dataItEnd = this->__dataTraining.end();

	while (dataItBegin != dataItEnd)
	{
		float dis = __euclidDistance(*dataItBegin, example);
		(*dataItBegin)->setDistance(dis);
		dataItBegin++;
	}

	sort(this->__dataTraining.begin(), this->__dataTraining.end(), compareImage);
	int idx = 0;
	dataItBegin = this->__dataTraining.begin();
	dataItEnd = this->__dataTraining.end();
	int countIdx[10];
	
	if (this->__k > 0) {
		while (dataItBegin != dataItEnd)
		{
			dataItBegin++;
			countIdx[(*dataItBegin)->getLabel()]++;
			idx++;
			if (idx == this->__k)
				break;
		}
	}

	int maxV = countIdx[0];
	int result = 0;
	for (idx = 0; idx < 10; idx++) {
		if (maxV < countIdx[idx]) {
			maxV = countIdx[idx];
			result = idx;
		}
	}

	return result;
}

float KNN::__euclidDistance(Image* image1, Image* image2)
{
	vector<unsigned int> attrImage1 = image1->getAttributes();
	vector<unsigned int> attrImage2 = image2->getAttributes();

	assert(attrImage1.size() == attrImage2.size());
	vector<unsigned int>::iterator aitBeginImage1 = attrImage1.begin();
	vector<unsigned int>::iterator aitBeginImage2 = attrImage2.begin();
	vector<unsigned int>::iterator aitEnd = attrImage1.end();
	float sum = 0.0f;
	while (aitBeginImage1 != aitEnd)
	{
		sum += (float)pow((*aitBeginImage1) - (*aitBeginImage2), 2);

		aitBeginImage1++;
		aitBeginImage2++;
	}
	if (sum == 0.0f) {
		return -1.0f;
	}
	return (float) sqrt(1.0f*sum);
}

void KNN::setTxtEstimate(string txt)
{
	this->__txtEstimate = txt;
}

string KNN::getTxtEstimate()
{
	return this->__txtEstimate;
}