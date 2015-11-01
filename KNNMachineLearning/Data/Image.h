#pragma once
#include <vector>
#include <iostream>

using namespace std;

class Image
{
private:
	vector<unsigned int> __attributes;
	unsigned int __label;
	float __distance;
public:
	Image();
	Image(vector<unsigned int> attributes, unsigned int label = 10, float distace = -1.0f);
	~Image();

	void setLabel(unsigned int label);
	unsigned int getLabel();
	
	void setDistance(float distance);
	float getDistance();

	void setAttributes(vector<unsigned int> attributes);
	vector<unsigned int> getAttributes();
};

