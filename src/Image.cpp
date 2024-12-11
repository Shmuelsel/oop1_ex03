#include "Image.h"
#include "Pixel.h"
#include "ImageDataStructure.h"

Image::Image(): m_data(0,0) {};

Image::Image(int height, int width)
	:m_data(height, width) {};

Image::Image(int height, int width, Pixel pixel)
	:m_data(height, width) {

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			m_data[i][j] = pixel;
		}
	}
}

////getters
//int GetHeight()const {
//	
//} ;
//int GetWidth()const {};

