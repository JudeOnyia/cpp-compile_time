#ifndef CexprMath
#define CexprMath
#include<boost/math/constants/constants.hpp>

namespace ra::cexpr_math {
	// The math constant pi.
	// The type T is a floating-point type.
	template<class T>
	constexpr T pi = boost::math::constants::pi<T>();

	// Returns the absolute value of x.
	// The type T is a floating-point type.
	template<class T>
	constexpr T abs(T x){
		return (x < 0)? (-x) : x;
	}

	// Returns the square of x.
	// The type T is a floating-point type.
	template<class T>
	constexpr T sqr(T x){
		return (x * x);
	}

	// Returns the cube of x.
	// The type T is a floating-point type.
	template<class T>
	constexpr T cube(T x){
		return (x * x * x);
	}

	// Returns the remainder after division when x is divided by y.
	// In particular, x - n y is returned where n is the result obtained by
	// dividing x by y and then rounding (to an integer value) toward zero.
	// If y is zero, an exception of type std::overflow_error is thrown.
	// The type T is a floating-point type.
	template<class T>
	constexpr T mod(T x, T y){
		long long n = 0;
		T remainder = 0;
		if(y == 0){
			throw std::overflow_error("zero modulus");
		}
		n = (long long)(x / y);
		remainder = x - ( ((T)n) * y );
		return remainder;
	}

	// Returns the sine of x.
	// Note that a particular algorithm must be used to implement this
	// function.
	// The type T is a floating-point type.
	/*template<class T>
	constexpr T sin(T x){
		cd
	}*/
}
#endif
