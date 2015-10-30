#include "stdafx.h"
#include "ReadDataTest.h"

ReadDataTest::ReadDataTest(string filePath, int numberAttribute, int numberImage)
{
	this->_filePath = filePath;
}
	void readFile();
	void ReadLineOfFile(string line);
	void setFilePath(string filePath);
	string getFilePath();
	vector<Image*> getDataTraining();