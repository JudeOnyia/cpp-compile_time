#include<iostream>
#include"ra/cexpr_math.hpp"

int main (){
	using std::cout;
	using std::endl;
	constexpr double pi_ = ra::cexpr_math::pi<double>;
	cout <<"Pi= "<<pi_<<endl;
	constexpr float var_A = 23.75;
	constexpr float var_B = -98.22;
	cout <<"abs(23.75)= "<<ra::cexpr_math::abs<float>(var_A)<<endl;
	cout <<"abs(-98.22)= "<<ra::cexpr_math::abs<float>(var_B)<<endl;
	cout <<"sqr(23.75)= "<<ra::cexpr_math::sqr<float>(var_A)<<endl;
	cout <<"cube(-98.22)= "<<ra::cexpr_math::cube<float>(var_B)<<endl;
	cout <<"mod(6.8*pi_,2*pi_)= "<<ra::cexpr_math::mod<double>(6.8*pi_,2*pi_)<<endl;
	
	return 0;
}
