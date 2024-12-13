#pragma once
#include "Pixel.h"

class Image;

class ImageDataStructure
{
private:
	Pixel** m_data;
	int m_height;
	int m_width;

	void allocateMemory(int h, int w);
	void freeMemory();

public:
	ImageDataStructure(int h = 0, int w = 0, Pixel pixel = ' ');
	ImageDataStructure(const ImageDataStructure& other);
	~ImageDataStructure();

	int getHeight() const;
	int getWidth() const;

	bool operator==(const ImageDataStructure& other) const;
	bool operator!=(const ImageDataStructure& other) const;
	ImageDataStructure operator+(const ImageDataStructure& other) const;
	ImageDataStructure operator|(const ImageDataStructure& other) const;
	ImageDataStructure operator&(const ImageDataStructure& other) const;
	Pixel& operator()(unsigned int y, unsigned int x);
	const Pixel& operator()(unsigned int y, unsigned int x) const;
	ImageDataStructure operator~() const;
};
	