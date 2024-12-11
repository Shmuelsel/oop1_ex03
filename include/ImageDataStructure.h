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
	ImageDataStructure(int h, int w);

	ImageDataStructure(const ImageDataStructure& other);
	~ImageDataStructure();

	Pixel* operator[](int row) const {
		if (row < 0 || row >= m_height) {
			throw std::out_of_range("Row index out of range");
		}
		return m_data[row];
	}
};