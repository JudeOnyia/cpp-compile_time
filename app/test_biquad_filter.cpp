#include<iostream>
#include"ra/biquad_filter.hpp"

int main () {
	using std::cout;
	using std::endl;
	constexpr ra::biquad::biquad_filter_coefs<long double> obj_A(23.6,12.0,2.9,19.0,34.8,134.5);
	constexpr ra::biquad::biquad_filter_coefs<float> obj_B(obj_A);
	cout<<"obj_A(23.6,12.0,2.9,19.0,34.8,134.5): "<<obj_A.a0<<" "<<obj_A.a1<<" "<<obj_A.a2<<" "<<obj_A.b0<<" "<<obj_A.b1<<" "<<obj_A.b2<<endl;
	cout<<"obj_B(obj_A): "<<obj_B.a0<<" "<<obj_B.a1<<" "<<obj_B.a2<<" "<<obj_B.b0<<" "<<obj_B.b1<<" "<<obj_B.b2<<endl;
	
	return 0;
}
