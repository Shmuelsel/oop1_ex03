#pragma once

#include <iostream>
#include <iosfwd>

class Pixel {
private:
	int m_color;

public:
	//need to chack if it is good
	Pixel(unsigned char pixel = ' ');

	//operator==
	bool operator==(const Pixel& other) const;

	//operator!=
	bool operator!=(const Pixel& other) const;

	//operator|
	Pixel operator|(const Pixel& other) const;

	//operator&
	Pixel operator&(const Pixel& other) const;

	//operator|=, return reference to lhs because lhs is modified
	Pixel& operator|=(const Pixel& other);

	//operator&=, return reference to lhs because lhs is modified
	Pixel& operator&=(const Pixel& other);

	friend std::ostream& operator<<(std::ostream& os, const Pixel& pixel);
};

std::ostream& operator<<(std::ostream& os, const Pixel& pixel);


