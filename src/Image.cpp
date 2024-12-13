#include "Image.h"

Image::Image(): m_matrix(0,0) {};

Image::Image(int height, int width)
	:m_matrix(height, width) {};

Image::Image(int height, int width, Pixel pixel)
	:m_matrix(height, width, pixel) {}


int Image::getHeight() const {
	return m_matrix.getHeight();
}

int Image::getWidth() const {
	return m_matrix.getWidth();
}


bool Image::operator==(const Image& other) const {
	return this->m_matrix == other.m_matrix;
}

bool Image::operator!=(const Image& other) const {
	return !(this->m_matrix == other.m_matrix);
}

Image Image::operator+(const Image& other) const {
	return this->m_matrix + other.m_matrix;
}

Image& Image::operator+=(const Image& other) {
	this->m_matrix = this->m_matrix + other.m_matrix;
	return *this;
}

Image Image::operator|(const Image& other) const {
	return this->m_matrix | other.m_matrix;
}

Image& Image::operator|=(const Image& other) {
	this->m_matrix = this->m_matrix | other.m_matrix;
	return *this;
}

Image Image::operator&(const Image& other) const {
	return this->m_matrix & other.m_matrix;
}

Image& Image::operator&=(const Image& other) {
	this->m_matrix = this->m_matrix & other.m_matrix;
	return *this;
}

Image Image::operator*(const int n) const {
	if (n == 0) {
		return Image();
	}

	Image result = *this;
	for (unsigned int i = 1; i < n; ++i) {
		result = result + *this;
	}

	return result;
}

Image operator*(const int n, const Image& other) {
	return other * n;
}

Image& Image::operator*=(const int n) {
	*this = *this * n;
	return *this;
}

Pixel& Image::operator()(unsigned int y, unsigned int x) {
	return m_matrix(y, x);
}

const Pixel& Image::operator()(unsigned int y, unsigned int x) const {
	return m_matrix(y, x);
}

Image Image::operator~() const{
	return ~this->m_matrix;
}


std::ostream& operator<<(std::ostream& os, const Image& image) {
	for (unsigned int i = 0; i < image.getHeight(); ++i) {
		for (unsigned int j = 0; j < image.getWidth(); ++j) {
			os << image(i, j); 
		}
		os << '\n';
	}
	return os;
}



