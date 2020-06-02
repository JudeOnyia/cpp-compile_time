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
	template<class T>
	constexpr T sin(T x){
		if(x >= (2.0*pi<T>)){
			x = mod<T>(x, 2.0*pi<T>);
		}
		T result = 0.0;
		T base = T(0.000001);
		if(x < 0.0){
			result = -1.0 * sin<T>(abs<T>(x));
		}
		else{
			if(x <= base){
				result = x;
			}
			else{
				result = (3.0*sin<T>(x/3.0)) - (4.0*cube<T>(sin<T>(x/3.0)));
			}
		}
		return result;
	}

	// Returns the cosine of x.
	// Note that a particular algorithm must be used to implement this
	// function.
	// The type T is a floating-point type.
	template<class T>
	constexpr T cos(T x){
		return (sin<T>( x + (pi<T>/2.0) ));
	}

	// Returns the tangent of x.
	// Note that a particular algorithm must be used to implement this
	// function.
	// If the tangent of x is infinite, an exception of type
	// std::overflow_error is thrown.
	// The type T is a floating-point type.
	template<class T>
	constexpr T tan(T x){
		T result = 0.0;
		T a = sin<T>(x);
		T b = cos<T>(x);
		if(b == 0){
			throw std::overflow_error("infinite tangent");
		}
		else{
			result = a / b;
		}
		return result;
	}

	// Returns the square root of x.
	// If x is negative, an exception of type std::domain_error is thrown.
	// Note that a particular algorithm must be used to implement this
	// function.
	// The type T is a floating-point type.
	template<class T>
	constexpr T sqrt(T x){
		T ep = std::numeric_limits<T>::epsilon();
		T result = x;
		T result_next = x;
		if(x < 0){
			throw std::domain_error("square root of negative number");
		}
		else{
			do{
				result = result_next;
				result_next = result - ( (sqr<T>(result)-x) / (2*result) );
			} while(abs<T>(result_next - result) > ep);
		}
		return result;
	}
}
#endif
