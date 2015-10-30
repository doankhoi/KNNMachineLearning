#include "stdafx.h"
#include "Image.h"


Image::Image() 
{

}

Image::Image(vector<unsigned int> attributes, unsigned int label)
{
	this->setAttributes(attributes);
	this->setLabel(label);
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
