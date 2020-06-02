#include <iostream>
#include "ra/mandelbrot.hpp"

#if !defined(MANDELBROT_WIDTH) && !defined(MANDELBROT_HEIGHT)
#define MANDELBROT_WIDTH 256
#define MANDELBROT_HEIGHT 256
#endif

int main()
{
	constexpr auto s = ra::fractal::mandelbrot<MANDELBROT_WIDTH,
	  MANDELBROT_HEIGHT>;
	std::cout << s.begin() << '\n';

	return (std::cout) ? 0 : 1;
}
