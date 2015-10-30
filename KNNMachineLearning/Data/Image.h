#pragma once
#include <vector>
#include <iostream>

using namespace std;

class Image
{
private:
	vector<unsigned int> __attributes;
	unsigned int __label;
public:
	Image();
	Image(vector<unsigned int> attributes, unsigned int label);
	~Image();

	void setLabel(unsigned int label);
	unsigned int getLabel();

	void setAttributes(vector<unsigned int> attributes);
	vector<unsigned int> getAttributes();
};

