#include <ostream>
#include "Pixel.h"

const unsigned char WHITE = (unsigned char)32;
const unsigned char BLACK = (unsigned char)219;
const unsigned char GRAY = (unsigned char)176;

Pixel::Pixel(unsigned char pixel)
	:m_color(pixel)
{};

//operator<<
std::ostream& operator<<(std::ostream& os, const Pixel& pixel) {
	return os << pixel.m_color;
}

//operator==
bool Pixel::operator==(const Pixel& other) const {
	return this->m_color == other.m_color;
}

//operator, use the operator==
bool Pixel::operator!=(const Pixel& other) const {
	return !(*this == other);
}

//operator|
Pixel Pixel::operator|(const Pixel& other) const{
	if (*this == other) {
		return *this;
	}
	else {
		return this->m_color > other.m_color ?  this->m_color :  other.m_color;
	}
}

//operator&
Pixel Pixel::operator&(const Pixel& other) const{
	if (*this == other) {
		return *this;
	}
	else {
		return this->m_color < other.m_color ? this->m_color : other.m_color;
	}
}

//oprator|=, can use with p1 = p1|p2.
Pixel& Pixel::operator|=(const Pixel& other) {
	return *this = *this | other;
}

//oprator&=, can use with p1 = p1&p2.
Pixel& Pixel::operator&=(const Pixel& other) {
	return *this = *this & other;
}