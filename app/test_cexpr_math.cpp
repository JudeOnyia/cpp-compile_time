#include<iostream>
#include"ra/cexpr_math.hpp"

int main (){
	using std::cout;
	using std::endl;
	constexpr long double pi_ = ra::cexpr_math::pi<long double>;
	cout <<"Pi= "<<pi_<<endl;
	constexpr float var_A = 23.75;
	constexpr float var_B = -98.22;
	cout <<"abs(23.75)= "<<ra::cexpr_math::abs<float>(var_A)<<endl;
	cout <<"abs(-98.22)= "<<ra::cexpr_math::abs<float>(var_B)<<endl;
	cout <<"sqr(23.75)= "<<ra::cexpr_math::sqr<float>(var_A)<<endl;
	cout <<"cube(-98.22)= "<<ra::cexpr_math::cube<float>(var_B)<<endl;
	cout <<"mod(-6.8*pi_,2*pi_)= "<<ra::cexpr_math::mod<long double>(-6.8*pi_,2*pi_)<<endl;
	cout <<"sin(-5000*pi_/26)= "<<ra::cexpr_math::sin<long double>(-5000*pi_/26)<<endl;
	cout <<"sin(4*pi_/3)= "<<ra::cexpr_math::sin<long double>(4*pi_/3)<<endl;
	cout <<"cos(-5000*pi_/26)= "<<ra::cexpr_math::cos<long double>(-5000*pi_/26)<<endl;
	cout <<"cos(4*pi_/3)= "<<ra::cexpr_math::cos<long double>(4*pi_/3)<<endl;
	cout <<"tan(-5000*pi_/26)= "<<ra::cexpr_math::tan<long double>(-5000*pi_/26)<<endl;
	cout <<"tan(4*pi_/3)= "<<ra::cexpr_math::tan<long double>(4*pi_/3)<<endl;
	cout <<"srqt(1377)= "<<ra::cexpr_math::sqrt<long double>(1377)<<endl;
	
	return 0;
}
