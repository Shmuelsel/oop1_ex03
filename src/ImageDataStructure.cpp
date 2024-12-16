#include "ImageDataStructure.h"

const unsigned char BLACK = (unsigned char)219;
const unsigned char WHITE = (unsigned char)32;

ImageDataStructure::ImageDataStructure(int h, int w, Pixel pixel) : m_height(h), m_width(w) {
	allocateMemory(h, w);
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			m_data[i][j] = pixel;
		}
	}
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
	m_data = new Pixel * [h];
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

int ImageDataStructure::getHeight() const {
	return m_height;
}

int ImageDataStructure::getWidth() const {
	return m_width;
}

ImageDataStructure::~ImageDataStructure() {
	freeMemory();
}

ImageDataStructure& ImageDataStructure::operator=(const ImageDataStructure& other)
{
	ImageDataStructure temp = other;
	std::ranges::swap(temp.m_height, this->m_height);
	std::ranges::swap(temp.m_width, this->m_width);
	std::ranges::swap(temp.m_data, this->m_data);
	return *this;
}

bool ImageDataStructure::operator==(const ImageDataStructure& other) const {
	if (m_height != other.m_height || m_width != other.m_width) {
		return false;
	}
	for (int i = 0; i < m_height; ++i) {
		for (int j = 0; j < m_width; ++j) {
			if (m_data[i][j] != other.m_data[i][j]) {
				return false;
			}
		}
	}
	return true;
}


bool ImageDataStructure::operator!=(const ImageDataStructure& other) const {
	return !(*this == other);
}

ImageDataStructure ImageDataStructure::operator+(const ImageDataStructure& other) const {
	int newHeight = std::max(getHeight(), other.getHeight());
	int newWidth = getWidth() + other.getWidth();

	ImageDataStructure result(newHeight, newWidth);

	for (int i = 0; i < getHeight(); i++) {
		for (int j = 0; j < getWidth(); j++) {
			result.m_data[i][j] = m_data[i][j]; 
		}
	}

	for (int i = 0; i < other.getHeight(); i++) {
		for (int j = 0; j < other.getWidth(); j++) {
			result.m_data[i][j + getWidth()] = other.m_data[i][j];
		}
	}

	return result;
}

ImageDataStructure ImageDataStructure::operator|(const ImageDataStructure& other) const
{
	// Calculate the dimensions of the resulting matrix
	int newHeight = std::max(m_height, other.m_height);
	int newWidth = std::max(m_width, other.m_width);

	// Initialize a new ImageDataStructure to hold the result
	ImageDataStructure newMatrix(newHeight, newWidth);

	// Iterate through each pixel of the new matrix
	for (int i = 0; i < newHeight; i++)
	{
		for (int j = 0; j < newWidth; j++)
		{
			// Retrieve pixel values for both matrices, defaulting to Pixel() if out of bounds
			Pixel pixelThis = (i < m_height && j < m_width) ? m_data[i][j] : Pixel();
			Pixel pixelOther = (i < other.m_height && j < other.m_width) ? other.m_data[i][j] : Pixel();

			// Perform bitwise OR and assign to the new matrix
			newMatrix.m_data[i][j] = pixelThis | pixelOther;
		}
	}
	return newMatrix;
}

ImageDataStructure ImageDataStructure::operator&(const ImageDataStructure& other) const
{
	int newHeight = std::min(m_height, other.m_height);
	int newWidth = std::min(m_width, other.m_width);

	ImageDataStructure result(newHeight, newWidth);

	//i dont need to check the size of both matrix
	for (int i = 0; i < newHeight; i++)
		for (int j = 0; j < newWidth; j++){
			result.m_data[i][j] = m_data[i][j] & other.m_data[i][j];
		}

	return result;
}

Pixel& ImageDataStructure::operator()(unsigned int y, unsigned int x) {
	if (y >= (unsigned int)m_height || x >= (unsigned int)m_width) {
		throw std::out_of_range("Index out of range");
	}
	return m_data[y][x];
}

const Pixel& ImageDataStructure::operator()(unsigned int y, unsigned int x) const {
	if (y >= (unsigned int)m_height || x >= (unsigned int)m_width) {
		throw std::out_of_range("Index out of range");
	}
	return m_data[y][x];
}

ImageDataStructure ImageDataStructure::operator~()const {
	ImageDataStructure result(*this);

	for (int i = 0; i < result.m_height; i++) {
		for (int j = 0; j < result.m_width; j++) {
			result.m_data[i][j] = (result.m_data[i][j] == BLACK) ? WHITE :
								  (result.m_data[i][j] == WHITE) ? BLACK : result.m_data[i][j];
		}
	}
	return result;
}

std::ostream& operator<<(std::ostream& os, const ImageDataStructure& image)
{
	if (!image.m_data)
		return os;

	for (int i = 0; i < image.m_height; i++)
	{
		for (int j = 0; j < image.m_width; j++)
		{
			os << image.m_data[i][j];
		}
		os << std::endl;
	}
	return os;
}