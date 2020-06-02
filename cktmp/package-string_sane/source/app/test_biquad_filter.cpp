#include <ra/biquad_filter.hpp>

namespace rb = ra::biquad;

template <class T>
void test()
{
	using biquad_filter_coefs = typename rb::biquad_filter_coefs<T>;
	constexpr biquad_filter_coefs x(T(1.0), T(1.0), T(1.0), T(1.0), T(1.0), T(1.0));
	constexpr biquad_filter_coefs y(x);
	constexpr biquad_filter_coefs xx(1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
	constexpr auto lf = rb::lowpass(T(0.5), T(0.7));
	constexpr auto hf = rb::highpass(T(0.5), T(0.7));
	constexpr auto bf = rb::bandpass(T(0.5), T(0.7));
	constexpr auto lbf = rb::lowshelf_boost(T(0.5), T(10.0));
	constexpr auto lcf = rb::lowshelf_cut(T(0.5), T(10.0));
}

int main()
{
	test<float>();
	test<double>();
	test<long double>();
}
