#include "ra/cexpr_basic_string.hpp"
#include <iostream>
#include <cstddef>

int main(){

	using std::cout;
	using std::endl;
	// Test default constructor 
	ra::cexpr::cexpr_basic_string<char,10> obj_A;
	const unsigned char s[] = {'j','u','d','e','\0'};
	// Test constructor with single pointer
	ra::cexpr::cexpr_basic_string<unsigned char,20> obj_B(s);
	cout << "obj_B = " << obj_B[0] << obj_B[1] << obj_B[2] << obj_B[3] << endl;
	cout << "max size: " << obj_B.max_size() << endl;
	cout << "capacity: " << obj_B.capacity() << endl;
	cout << "size: " << obj_B.size() << endl;
	constexpr unsigned char j[] = {'o', 'n', 'y', 'i', 'a', '\0'};
	// Test constructor with pointers to first and one past last
	constexpr ra::cexpr::cexpr_basic_string<unsigned char,6> obj_C(&j[0], &j[5]);
	// Test member function data()
	const unsigned char* t = obj_C.data();
	for(std::size_t i=0; i<obj_C.size(); ++i){
		cout<< *t;
		++t;
	}
	cout << endl;
	// Test prevention of pointer (from data()) to change null terminator
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
	// Test push_back(), pop_back() and append()
	cout << "obj_B.size(): "<< obj_B.size() << endl;
	obj_B.push_back('c');
	cout << "obj_B.size(): "<< obj_B.size() << endl;
	cout << "obj_C.size(): "<< obj_C.size() << endl;
	cout << "obj_B.capacity(): "<< obj_B.capacity() << endl;
	obj_B.append(obj_C);
	cout << "obj_B.size(): "<< obj_B.size() << endl;
	for(std::size_t i=0; i<=obj_B.size(); ++i){
		cout << obj_B[i];
	}
	cout << endl;
	obj_B.pop_back();
	cout << "Pop_back: ";
	for(std::size_t i=0; i<=obj_B.size(); ++i){
		cout << obj_B[i];
	}
	cout << endl;
	obj_B.append(s);
	cout << "Append s: ";
	for(std::size_t i=0; i<=obj_B.size(); ++i){
		cout << obj_B[i];
	}
	cout << endl;
	// Test clear()
	obj_B.clear();
	cout << "obj_B.clear. Then obj_B.size(): "<< obj_B.size() << endl;	
	// Test to_string()
	//std::size_t n = 596;
	char* buffer = obj_A.begin();
	//constexpr std::size_t size = 10;
	char okay = 'a';
	char* ptr_okay = &okay;
	char** end = &ptr_okay;
	cout<<"To String"<<endl;
	cout<<"size: "<<(ra::cexpr::to_string(596,buffer,obj_A.capacity(),end))<<endl;
	cout<<"string: "<<buffer<<endl;
	cout<<"Before end: "<<(*((*end)-1))<<endl;
	cout<<"end: "<<(**end)<<endl;
	return 0;
}

