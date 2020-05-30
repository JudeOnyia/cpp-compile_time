#include "ra/cexpr_basic_string.hpp"
#include <iostream>
#include <cstddef>

int main(){

	using std::cout;
	using std::endl;
	constexpr ra::cexpr::cexpr_basic_string<char,10> obj_A();
	const char s[] = {'j','u','d','e','\0'};
	constexpr ra::cexpr::cexpr_basic_string<char,6> obj_B(s);
	cout << "obj_B = " << obj_B[0] << obj_B[1] << obj_B[2] << obj_B[3] << endl;
	cout << "max size: " << obj_B.max_size() << endl;
	cout << "capacity: " << obj_B.capacity() << endl;
	cout << "size: " << obj_B.size() << endl;
	const unsigned char j[] = {'o', 'n', 'y', 'i', 'a', '\0'};
	//constexpr const unsigned char* j_first = &(j[0]);
	//constexpr const unsigned char* j_last = &(j[5]);
	constexpr ra::cexpr::cexpr_basic_string<unsigned char,6> obj_C(&j[0], &j[5]);
	const unsigned char* t = obj_C.data();
	for(std::size_t i=0; i<obj_C.size(); ++i){
		cout<< *t;
		++t;
	}
	cout << endl;
	ra::cexpr::cexpr_basic_string<unsigned char,6> obj_D(obj_C);
	unsigned char* tt = obj_D.data();
	for(std::size_t i=0; i<=obj_D.size(); ++i){
		cout<< *tt;
		++tt;
	}
	cout << endl;
	tt = obj_D.end();
	*tt = 'w';
	--tt;
	*tt = 'g';
	tt = obj_D.begin();
	for(std::size_t i=0; i<=obj_D.size(); ++i){
		cout<< *tt;
		++tt;
	}
	cout << endl;
	return 0;
}

