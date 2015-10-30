#include <string>
#include <iostream>
#include <vector>
#include "Image.h"
using namespace std;

class IReadFile
{
protected:
	string _filePath;
	int _numberAttribute;
	int _numberImage;
	vector<Image*> _data;

public:
	virtual void readFile() = 0;
	virtual void ReadLineOfFile(string line) = 0;
};