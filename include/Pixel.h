#pragma once

#include <iostream>
#include <iosfwd>

class Pixel {
private:
	unsigned char m_color;

public:
	Pixel(unsigned char pixel = ' ');

	bool operator==(const Pixel& other) const;
	Pixel operator|(const Pixel& other) const;
	Pixel operator&(const Pixel& other) const;
	Pixel& operator=(const Pixel&);

	friend std::ostream& operator<<(std::ostream& os, const Pixel& pixel);
};

std::ostream& operator<<(std::ostream& os, const Pixel& pixel);

bool operator!=(const Pixel&, const Pixel&);
Pixel& operator|=(Pixel& ,const Pixel&);
Pixel& operator&=(Pixel& ,const Pixel&);

