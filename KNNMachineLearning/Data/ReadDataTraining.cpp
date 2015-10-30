#include "stdafx.h"
#include "ReadDataTraining.h"

ReadDataTraining::ReadDataTraining(string filePath, int numberAttribute, int numberImage)
{
	this->_filePath = filePath;
	this->_numberAttribute = numberAttribute;
	this->_numberImage = numberImage;
}

void ReadDataTraining::readFile()
{
	try {
		fstream file (this->getFilePath());
		string line;
		int k = 0;
		while (std::getline(file, line)) {
			if (k == this->_numberImage) // number of image exceed limit
				break;
			ReadLineOfFile(line);
			k++;
		}
	} catch (exception e) {
		cout <<  "Note read file training" << endl;
 	}
}

void ReadDataTraining::setFilePath(string filePath) 
{
	this->_filePath = filePath;
}

string ReadDataTraining::getFilePath()
{
	return this->_filePath;
}

vector<Image*> ReadDataTraining::getDataTraining()
{
	return this->_data;
}

void ReadDataTraining::ReadLineOfFile(string line)
{
	assert(line.length() > 0);
	unsigned int lengthLine = line.length();
	int idxStart = 0;
	int idxEnd = 0;
	vector<unsigned int> attr;
	unsigned int label = -1;
	unsigned int temp;
	int count = 0;

	for(int i = 0; i < lengthLine; i++) {
		if (line.at(i) == ',') {
			int len = (idxEnd - idxStart);
			assert(len > 0);
			temp = stoi(line.substr(idxStart, len));
			attr.push_back(temp);
			count++;
			idxStart = idxEnd + 1;
			idxEnd = idxStart;
			if (count == this->_numberAttribute) {
				int lenLabel = lengthLine - idxStart;
				assert(lenLabel > 0);
				label = stoi(line.substr(idxStart, lenLabel));
				break;
			}
		} else {
			idxEnd++;
		}
	}

	assert( label != -1);
	Image* newImage = new Image(attr, label);
	this->_data.push_back(newImage);
}