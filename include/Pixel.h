#pragma once

#include <iostream>
#include <iosfwd>

class Pixel {
private:
	int m_color;

public:
	Pixel(unsigned char pixel = ' ');

	bool operator==(const Pixel& other) const;
	bool operator!=(const Pixel& other) const;
	Pixel operator|(const Pixel& other) const;
	Pixel operator&(const Pixel& other) const;
	Pixel& operator|=(const Pixel& other);
	Pixel& operator&=(const Pixel& other);

	friend std::ostream& operator<<(std::ostream& os, const Pixel& pixel);
};

std::ostream& operator<<(std::ostream& os, const Pixel& pixel);


