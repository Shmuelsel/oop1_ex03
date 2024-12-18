#pragma once

#include "ImageDataStructure.h"
#include <iosfwd>
#include <iostream>


class Image
{
private:
	ImageDataStructure m_matrix;
	
public:
	Image();
	Image(int, int);
	Image(int height, int width, Pixel pixel);
	Image(const ImageDataStructure& matrix):
		m_matrix(matrix) {};

	int getHeight() const;
	int getWidth() const;


	bool operator==(const Image& other) const;
	Image operator|(const Image& other) const;
	Image operator&(const Image& other) const;
	Image operator+(const Image& other) const;
	Image operator*(const int n) const;
	Image operator~() const;
	Pixel& operator()(unsigned int x, unsigned int y);
	const Pixel& operator()(unsigned int x, unsigned int y) const ;
	friend std::ostream& operator<<(std::ostream& os, const Image& image);
};

std::ostream& operator<<(std::ostream& os, const Image& image);

bool operator!=(const Image&, const Image&);
Image& operator+=(Image&, const Image&);
Image& operator|=(Image&, const Image&);
Image& operator&=(Image&, const Image&);
Image operator*(const int n, const Image&);
Image& operator*=(Image&, const int n);
Image& operator*=(const int n, Image&);