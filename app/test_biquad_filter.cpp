#include<iostream>
#include"ra/biquad_filter.hpp"

int main () {
	using std::cout;
	using std::endl;
	constexpr ra::biquad::biquad_filter_coefs<long double> obj_A(23.6,12.0,2.9,19.0,34.8,134.5);
	constexpr ra::biquad::biquad_filter_coefs<float> obj_B(obj_A);
	cout<<"obj_A(23.6,12.0,2.9,19.0,34.8,134.5): "<<obj_A.a0<<" "<<obj_A.a1<<" "<<obj_A.a2<<" "<<obj_A.b0<<" "<<obj_A.b1<<" "<<obj_A.b2<<endl;
	cout<<"obj_B(obj_A): "<<obj_B.a0<<" "<<obj_B.a1<<" "<<obj_B.a2<<" "<<obj_B.b0<<" "<<obj_B.b1<<" "<<obj_B.b2<<endl;
	constexpr ra::biquad::biquad_filter_coefs<long double> obj_lp(ra::biquad::lowpass(0.33,0.7071));
	constexpr ra::biquad::biquad_filter_coefs<long double> obj_hp(ra::biquad::highpass(0.67,0.7071));
	constexpr ra::biquad::biquad_filter_coefs<long double> obj_bp(ra::biquad::bandpass(0.56,0.7071));
	constexpr ra::biquad::biquad_filter_coefs<long double> obj_boost(ra::biquad::lowshelf_boost(0.33,1.77827941));//Gain of 5
	constexpr ra::biquad::biquad_filter_coefs<long double> obj_cut(ra::biquad::lowshelf_cut(0.33,2.818382931));//Gain of -9
	cout<<"lp: "<<obj_lp.a0<<" "<<obj_lp.a1<<" "<<obj_lp.a2<<" "<<obj_lp.b0<<" "<<obj_lp.b1<<" "<<obj_lp.b2<<endl;
	cout<<"hp: "<<obj_hp.a0<<" "<<obj_hp.a1<<" "<<obj_hp.a2<<" "<<obj_hp.b0<<" "<<obj_hp.b1<<" "<<obj_hp.b2<<endl;
	cout<<"bp: "<<obj_bp.a0<<" "<<obj_bp.a1<<" "<<obj_bp.a2<<" "<<obj_bp.b0<<" "<<obj_bp.b1<<" "<<obj_bp.b2<<endl;
	cout<<"boost: "<<obj_boost.a0<<" "<<obj_boost.a1<<" "<<obj_boost.a2<<" "<<obj_boost.b0<<" "<<obj_boost.b1<<" "<<obj_boost.b2<<endl;
	cout<<"cut: "<<obj_cut.a0<<" "<<obj_cut.a1<<" "<<obj_cut.a2<<" "<<obj_cut.b0<<" "<<obj_cut.b1<<" "<<obj_cut.b2<<endl;


	return 0;
}
