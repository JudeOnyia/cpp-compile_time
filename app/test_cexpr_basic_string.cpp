#include "ra/cexpr_basic_string.hpp"
#include <iostream>

int main(){

	using std::cout;
	using std::endl;
	ra::cexpr::cexpr_basic_string<char,10> obj_A();
	char s[] = {'j','u','d','e'};
	ra::cexpr::cexpr_basic_string<char,6> obj_B(s);
	//cout << "obj_B = " << obj_B[0] << obj_B[1] << obj_B[2] << obj_B[3] << endl; 
	return 0;
}

