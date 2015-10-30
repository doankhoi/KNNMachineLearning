#pragma once
#include <vector>
#include <iostream>
#include "IReadFile.h"
#include "Image.h"
#include <fstream>
#include <exception>
#include <assert.h>

using namespace std;

class ReadDataTraining : public IReadFile
{
public:
	ReadDataTraining(string filePath, int numberAttribute, int numberImage);
	void readFile();
	void ReadLineOfFile(string line);
	void setFilePath(string filePath);
	string getFilePath();
	vector<Image*> getDataTraining();
};