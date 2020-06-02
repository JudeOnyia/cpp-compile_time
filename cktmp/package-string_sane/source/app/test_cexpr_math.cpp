#include <ra/cexpr_math.hpp>
#include <iostream>

namespace rcm = ra::cexpr_math;

template <class T>
void test()
{
	constexpr T x1 = rcm::pi<T>;
	constexpr auto x2 = rcm::abs(T(5.0));
	constexpr auto x3 = rcm::sqr(T(5.0));
	constexpr auto x4 = rcm::cube(T(5.0));
	constexpr auto x5 = rcm::mod(T(5.0), T(2.0));
	constexpr auto x6 = rcm::sin(T(5.0));
	constexpr auto x7 = rcm::cos(T(5.0));
	constexpr auto x8 = rcm::tan(T(5.0));
	constexpr auto x9 = rcm::sqrt(T(5.0));
}

int main()
{
	test<float>();
	test<double>();
	test<long double>();
}
