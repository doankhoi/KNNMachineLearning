#pragma once
#include <vector>
#include <iostream>
#include "IReadFile.h"
#include "Image.h"
#include <fstream>
#include <exception>
#include <assert.h>

using namespace std;

class ReadDataTest : public IReadFile
{
public:
	ReadDataTest(string filePath, int numberAttribute, int numberImage);
	~ReadDataTest();
	void readFile();
	void ReadLineOfFile(string line);
	void setFilePath(string filePath);
	string getFilePath();
	vector<Image*> getDataTest();
};