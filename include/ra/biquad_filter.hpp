#ifndef BiquadFilter
#define BiquadFilter

namespace ra::biquad {
	// Biquad filter coefficients class.
	template<class Real>
	struct biquad_filter_coefs{
		// The real number type used to represent the filter coefficients.
		using real = Real;

		// Creates a set of filter coefficients where the coefficients
		// a0, a1, a2, b0, b1, and b2 are initialized to a0_, a1_, a2_,
		// b0_, b1_, and b2_, respectively.
		constexpr biquad_filter_coefs(real a0_, real a1_, real a2_, real b0_, real b1_, real b2_) : a0(a0_), a1(a1_), a2(a2_), b0(b0_), b1(b1_), b2(b2_){}

		// Creates a set of filter coefficients by copying from another set.
		// Since Real and OtherReal need not be the same, this constructor
		// can be used to convert between filter coefficients of different
		// types.
		template<class OtherReal>
		constexpr biquad_filter_coefs(const biquad_filter_coefs<OtherReal>& coefs) : a0(coefs.a0), a1(coefs.a1), a2(coefs.a2), b0(coefs.b0), b1(coefs.b1), b2(coefs.b2){}

		// The filter coefficients a0, a1, a2, b0, b1, and b2.
		real a0;
		real a1;
		real a2;
		real b0;
		real b1;
		real b2;
	};

}
#endif

