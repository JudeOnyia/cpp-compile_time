#ifndef BiquadFilter
#define BiquadFilter
#include"ra/cexpr_math.hpp"

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

	// Returns the coefficients for a biquad lowpass filter with normalized
	// cutoff frequency f and Q factor q, where f in [0,1] and q > 0.
	// The filter coefficients are always normalized such that the
	// coefficient b0 is 1.
	// The type Real is a floating-point type.
	// All real arithmetic should be performed with the Real type.
	template<class Real>
	constexpr biquad_filter_coefs<Real> lowpass(Real f, Real q){
		Real pi_ = ra::cexpr_math::pi<Real>;
		Real sig_ = ra::cexpr_math::tan<Real>(f*pi_/2.0);
		Real a0 = ra::cexpr_math::sqr<Real>(sig_);
		Real a1 = 2.0 * a0;
		Real a2 = a0;
		Real b0 = a0 + (sig_ / q) + 1.0;
		Real b1 = 2.0 * (a0 - 1.0);
		Real b2 = a0 - (sig_ / q) + 1.0;

		a0=a0/b0; a1=a1/b0; a2=a2/b0; b1=b1/b0; b2=b2/b0;
		biquad_filter_coefs<Real> obj(a0,a1,a2,1.0,b1,b2);
		return obj;
	}

	// Returns the coefficients for a biquad highpass filter with
	// normalized cutoff frequency f and Q factor q, where f in [0,1]
	// and q > 0.
	// The filter coefficients are always normalized such that the
	// coefficient b0 is 1.
	// The type Real is a floating-point type.
	// All real arithmetic should be performed with the Real type.
	template<class Real>
	constexpr biquad_filter_coefs<Real> highpass(Real f, Real q){
		Real pi_ = ra::cexpr_math::pi<Real>;
		Real sig_ = ra::cexpr_math::tan<Real>(f*pi_/2.0);
		Real sig_sqr = ra::cexpr_math::sqr<Real>(sig_);
		Real a0 = 1.0;
		Real a1 = -2.0;
		Real a2 = 1.0;
		Real b0 = sig_sqr + (sig_/q) + 1.0;
		Real b1 = 2.0 * (sig_sqr - 1.0);
		Real b2 = sig_sqr - (sig_/q) + 1.0;

		a0=a0/b0; a1=a1/b0; a2=a2/b0; b1=b1/b0; b2=b2/b0;
		biquad_filter_coefs<Real> obj(a0,a1,a2,1.0,b1,b2);
		return obj;
	}

	// Returns the coefficients for a biquad bandpass filter with
	// normalized cutoff frequency f and Q factor q, where f in [0,1]
	// and q > 0.
	// The filter coefficients are always normalized such that the
	// coefficient b0 is 1.
	// The type Real is a floating-point type.
	// All real arithmetic should be performed with the Real type.
	template<class Real>
	constexpr biquad_filter_coefs<Real> bandpass(Real f, Real q){
		Real pi_ = ra::cexpr_math::pi<Real>;
		Real sig_ = ra::cexpr_math::tan<Real>(f*pi_/2.0);
		Real sig_sqr = ra::cexpr_math::sqr<Real>(sig_);
		Real a0 = sig_ / q;
		Real a1 = 0.0;
		Real a2 = -a0;
		Real b0 = sig_sqr + (sig_/q) + 1.0;
		Real b1 = 2.0 * (sig_sqr - 1.0);
		Real b2 = sig_sqr - (sig_/q) + 1.0;

		a0=a0/b0; a1=a1/b0; a2=a2/b0; b1=b1/b0; b2=b2/b0;
		biquad_filter_coefs<Real> obj(a0,a1,a2,1.0,b1,b2);
		return obj;
	}

	// Returns the coefficients for a biquad low-frequency shelving
	// boost filter with normalized cutoff frequency f and gain-control
	// parameter a, where f in [0,1] and a >= 0.
	// For a gain in dB of G (where G > 0), choose a = 10 ˆ (G / 20).
	// The filter coefficients are always normalized such that the
	// coefficient b0 is 1.
	// The type Real is a floating-point type.
	// All real arithmetic should be performed with the Real type.
	template<class Real>
	constexpr biquad_filter_coefs<Real> lowshelf_boost(Real f, Real a){
		Real pi_ = ra::cexpr_math::pi<Real>;
		Real sig_ = ra::cexpr_math::tan<Real>(f*pi_/2.0);
		Real sig_sqr = ra::cexpr_math::sqr<Real>(sig_);
		Real sqrt_2a = ra::cexpr_math::sqrt<Real>(2.0 * a);
		Real sqrt_2 = ra::cexpr_math::sqrt<Real>(2.0);
		Real a0 = (a * sig_sqr) + (sqrt_2a * sig_) + 1.0;
		Real a1 = 2.0 * ((a*sig_sqr) - 1.0);
		Real a2 = (a * sig_sqr) - (sqrt_2a * sig_) + 1.0;
		Real b0 = sig_sqr + (sqrt_2 * sig_) + 1.0;
		Real b1 = 2.0 * (sig_sqr - 1.0);
		Real b2 = sig_sqr - (sqrt_2 * sig_) + 1.0;

		a0=a0/b0; a1=a1/b0; a2=a2/b0; b1=b1/b0; b2=b2/b0;
		biquad_filter_coefs<Real> obj(a0,a1,a2,1.0,b1,b2);
		return obj;
	}

	// Returns the coefficients for a biquad low-frequency shelving
	// cut filter with normalized cutoff frequency f and gain-control
	// parameter a, where f in [0,1] and a >= 0.
	// For a gain in dB of G (where G < 0), choose a = 10 ˆ (-G / 20).
	// The filter coefficients are always normalized such that the
	// coefficient b0 is 1.
	// The type Real is a floating-point type.
	// All real arithmetic should be performed with the Real type.
	template<class Real>
	constexpr biquad_filter_coefs<Real> lowshelf_cut(Real f, Real a){
		Real pi_ = ra::cexpr_math::pi<Real>;
		Real sig_ = ra::cexpr_math::tan<Real>(f*pi_/2.0);
		Real sig_sqr = ra::cexpr_math::sqr<Real>(sig_);
		Real sqrt_2a = ra::cexpr_math::sqrt<Real>(2.0 * a);
		Real sqrt_2 = ra::cexpr_math::sqrt<Real>(2.0);
		Real a0 = sig_sqr + (sqrt_2 * sig_) + 1.0;
		Real a1 = 2.0 * (sig_sqr - 1.0);
		Real a2 = sig_sqr - (sqrt_2 * sig_) + 1.0;
		Real b0 = (a * sig_sqr) + (sqrt_2a * sig_) + 1.0;
		Real b1 = 2.0 * ((a*sig_sqr) - 1.0);
		Real b2 = (a * sig_sqr) - (sqrt_2a * sig_) + 1.0;

		a0=a0/b0; a1=a1/b0; a2=a2/b0; b1=b1/b0; b2=b2/b0;
		biquad_filter_coefs<Real> obj(a0,a1,a2,1.0,b1,b2);
		return obj;
	}

}
#endif

