#include<iostream>
#include"ra/mandelbrot.hpp"

int main(){
	// Force the image (in PNM format) to be computed at compile time.
	constexpr auto s = ra::fractal::mandelbrot<256, 256>;

	// Output the image (in PNM format).
	std::cout << s.begin() << std::endl;
}
