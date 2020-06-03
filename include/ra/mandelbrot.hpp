#ifndef Mymandelbrot
#define Mymandelbrot
#include "ra/cexpr_basic_string.hpp"
#include <cstddef>

namespace ra::fractal {
	// Function to compute mandelbrot
	constexpr ra::cexpr::cexpr_string<1100000> mandelbrotComputation(const std::size_t W, const std::size_t H){
		ra::cexpr::cexpr_string<1100000> obj;
		char W_str[10] = {0};
		std::size_t W_str_size = 0;
		char H_str[10] = {0};
		std::size_t H_str_size = 0;

		double c0 = 0.0;
		double c1 = 0.0;
		double zn_c0 = 0.0;
		double zn_c0_next = 0.0;
		double zn_c1 = 0.0;
		double zn_c1_next = 0.0;
		std::size_t n = 0;
		bool outOfBound = false;

		double a0 = -1.6;
		double a1 = -1.1;
		double b0 = 0.6;
		double b1 = 1.1;
		double mult_c0 = (b0-a0)/(W-1);
		double mult_c1 = (b1-a1)/(H-1);

		obj.push_back('P');
		obj.push_back('1');
		obj.push_back(' ');
		W_str_size = ra::cexpr::to_string(W,W_str,10,nullptr);
		for(std::size_t i=0; i<W_str_size; ++i){
			obj.push_back(W_str[i]);
		}
		obj.push_back(' ');
		H_str_size = ra::cexpr::to_string(H,H_str,10,nullptr);
		for(std::size_t i=0; i<H_str_size; ++i){
			obj.push_back(H_str[i]);
		}
		obj.push_back('\n');
		

		for(std::size_t l=0; l<H; ++l){
			c1 = a1 + ( (double)(H-1-l) * mult_c1 );
			for(std::size_t k=0; k<W; ++k){
				c0 = a0 + ( (double)k * mult_c0 );
				while(n < 16){
					zn_c0_next = (zn_c0*zn_c0)-(zn_c1*zn_c1) + c0;
					zn_c1_next = (2.0*zn_c0*zn_c1) + c1;
					zn_c0 = zn_c0_next;
					zn_c1 = zn_c1_next;
					if( ((zn_c0*zn_c0)+(zn_c1*zn_c1)) > 4.0 ){
						outOfBound = true;
						break;
					}
					++n;
				}
				if(outOfBound == false){
					obj.push_back('1');
				}
				else{
					obj.push_back('0');
				}
				outOfBound = false;
				n = 0;
				zn_c0 = 0.0;
				zn_c1 = 0.0;
			}
			obj.push_back('\n');
		}

		return obj;
		
	}

	// A variable template for a string that represents an image depicting
	// the Mandelbrot set. The image has width W and height H.
	// This object must be of type cexpr_string<M> for some appropriate M.
	// The string is a binary image encoded in the text-based bitmap PNM
	// format.
	// The values of W and H must be such that W >= 2 and H >= 2.
	template<std::size_t W, std::size_t H>
	constexpr auto mandelbrot = mandelbrotComputation(W,H);
}
#endif
