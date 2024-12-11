#pragma once
#include "Pixel.h"
#include "ImageDataStructure.h"


class Image
{
public:
	Image();
	Image(int height, int width);
	Image(int height, int width, Pixel pixel);

	//getters
	int GetHeight() const;
	int GetWidth() const;


	//operator==
	bool operator==(const Image& other) const;
	//operator!=
	bool operator!=(const Image& other) const;
	//operator|
	Image operator|(const Image& other) const;
	//operator&
	Image operator&(const Image& other) const;
	//operator|=, return reference to *this because lhs is modified
	Image& operator|=(const Image& other);
	//operator&=, return reference to *this because lhs is modified
	Image& operator&=(const Image& other);
	//operator+
	Image operator+(const Image& other) const;
	//operator+=, return reference to *this because lhs is modified
	Image& operator+=(const Image& other);
	//operatorA*n
	Image operator*(const int n) const;
	//operator*=, return reference to *this because lhs is modified
	Image& operator*=(const int n);
	//operator~
	Image operator~() const;
	//operatorA(x,y), can writh or read
	Image operator()(unsigned int x, unsigned int y);
	//operatorA(x,y)=, only read
	Image operator()(unsigned int x, unsigned int y) const ;
	//operator<<
	friend std::ostream& operator<<(std::ostream& os, const Image& image);

private:
	ImageDataStructure m_data;

};

//operator<<
std::ostream& operator<<(std::ostream& os, const Image& image);