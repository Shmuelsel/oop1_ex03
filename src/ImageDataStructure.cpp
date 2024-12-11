#include "ImageDataStructure.h"
#include "Pixel.h"
#include "Image.h"


ImageDataStructure::ImageDataStructure(int h, int w) : m_height(h), m_width(w) {
	allocateMemory(h, w);
}


ImageDataStructure::ImageDataStructure(const ImageDataStructure& other)
	: m_height(other.m_height), m_width(other.m_width) {
	allocateMemory(m_height, m_width);
	for (int i = 0; i < m_height; ++i) {
		for (int j = 0; j < m_width; ++j) {
			m_data[i][j] = other.m_data[i][j];
		}
	}
}


void ImageDataStructure::allocateMemory(int h, int w) {
	
	m_data = new Pixel*[h];
	for (int i = 0; i < h; i++) {
		m_data[i] = new Pixel[w];
	}
}

void ImageDataStructure::freeMemory() {
	for (int i = 0; i < m_height; i++) {
		delete[] m_data[i];
	}
	delete[] m_data;
}
//destructor
ImageDataStructure::~ImageDataStructure() {
	freeMemory();
}