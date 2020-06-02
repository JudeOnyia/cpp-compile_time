#include<fstream>
#include<iostream>
#include"ra/mandelbrot.hpp"

int main(){
	// Force the image (in PNM format) to be computed at compile time.
	constexpr auto s = ra::fractal::mandelbrot<256, 256>;

	std::ofstream outfile;
	outfile.open("mandelbrot.pnm");

	// Output the image (in PNM format).
	outfile << s.begin() << std::endl;
	outfile.close();
	std::cout <<"Written to mandelbrot.pnm"<<std::endl;
	return 0;
}
