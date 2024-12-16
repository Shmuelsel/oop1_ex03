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

bool operator!=(const Image& left, const Image& right) {
	return !(left == right);
}

Image Image::operator+(const Image& other) const {
	return this->m_matrix + other.m_matrix;
}

Image&operator+=(Image& left, const Image& right) {
	return left = left + right;
}

Image Image::operator|(const Image& other) const {
	return this->m_matrix | other.m_matrix;
}

Image& operator|=(Image& left, const Image& right) {
	return left = left | right;
}

Image Image::operator&(const Image& other) const {
	return this->m_matrix & other.m_matrix;
}

Image& operator&=(Image& left, const Image& right) {
	return left = left & right;
}

Image Image::operator*(const int n) const {
	if (n == 0) {
		return Image();
	}

	Image result = *this;
	for (unsigned int i = 1; i < (unsigned int)n; ++i) {
		result = result + *this;
	}

	return result;
}

Image operator*(const int n, const Image& other) {
	return other * n;
}

Image& operator*=(Image& image, const int n) {
	return image = image * n;
}

Image& operator*=(const int n, Image& image) {
	return image = n * image;
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

std::ostream& operator<<(std::ostream& os, const Image& image)
{
	return os << image.m_matrix;
}



