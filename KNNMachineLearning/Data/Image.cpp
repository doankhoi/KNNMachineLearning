#include "stdafx.h"
#include "Image.h"


Image::Image() 
{

}

Image::Image(vector<unsigned int> attributes, unsigned int label, float distance)
{
	this->setAttributes(attributes);
	this->setLabel(label);
	this->setDistance(distance);
}

Image::~Image()
{

}

void Image::setLabel(unsigned int label)
{
	this->__label = label;
}

unsigned int Image::getLabel()
{
	return this->__label;
}

void Image::setDistance(float distance) 
{
	this->__distance = distance;
}

float Image::getDistance()
{
	return this->__distance;
}

void Image::setAttributes(vector<unsigned int> attributes)
{
	vector<unsigned int>::iterator aitBegin = attributes.begin();
	vector<unsigned int>::iterator aitEnd = attributes.end();
	while (aitBegin != aitEnd) 
	{
		this->__attributes.push_back(*aitBegin);
		aitBegin++;
	}
}

vector<unsigned int> Image::getAttributes()
{
	return this->__attributes;
}
