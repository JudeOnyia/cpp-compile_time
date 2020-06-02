#include <iostream>
#include <utility>
#include "ra/cexpr_basic_string.hpp"

using namespace std::literals;

template <class T, std::size_t M>
void test_1()
{
	using string = typename ra::cexpr::cexpr_basic_string<T, M>;

	{
		constexpr string s;
		sizeof(string);
		sizeof(typename string::value_type);
		sizeof(typename string::pointer);
		sizeof(typename string::const_pointer);
		sizeof(typename string::reference);
		sizeof(typename string::const_reference);
		sizeof(typename string::iterator);
		sizeof(typename string::const_iterator);
		constexpr string s1 = s;
		constexpr string s2;
		string s3;
		string s4(std::move(s3));
		s3 = s;
		s4 = std::move(s3);
	}
	{
		typename string::iterator si;
		string s(si, si);
	}

	{
		constexpr string cs;
		cs.max_size();
		cs.capacity();
		cs.size();
		cs.data();
		cs.begin();
		cs.end();
		cs[0];
	}

	{
		constexpr string cs;
		string s;
		s.data();
		s.push_back('a');
		s.pop_back();
		T hello[] = {T('h'), T('e'), T('l'), T('l'), T('o'), T(0)};
		s.append(&hello[0]);
		s.append(s);
		s.append(cs);
		s.clear();
	}

	{
		using OtherString =
		  ra::cexpr::cexpr_basic_string<T, M + 1>;
		constexpr T hello[] = {T('h'), T('e'), T('l'), T('l'), T('o'), T(0)};
		string s(&hello[0]);
		constexpr OtherString os(&hello[0]);
		s.append(os);
	}

}

void test_2()
{
	{
		char buffer[1024];
		ra::cexpr::to_string(42, buffer, sizeof(buffer), nullptr);
	}
}

template <class T, std::size_t M>
constexpr typename ra::cexpr::cexpr_basic_string<T, M> test_3()
{
	using string = typename ra::cexpr::cexpr_basic_string<T, M>;
	using string2 = typename ra::cexpr::cexpr_basic_string<T, 2 * M>;
	{
		constexpr string s;
		constexpr string s2(s);
		constexpr T a[] = {T('h'), T('i'), T(0)};
		constexpr string s3(&a[0]);
		constexpr string s4(&a[0], &a[1]);
		constexpr std::size_t n1 = s3.size();
		constexpr std::size_t n2 = s3.max_size();
		constexpr std::size_t n3 = s3.capacity();
		const T* p1 = s3.data();
//		constexpr typename string::const_iterator i1 = s3.begin();
//		constexpr typename string::const_iterator i2 = s3.end();
		string s5;
		typename string::iterator j1 = s5.begin();
		typename string::iterator j2 = s5.end();
		constexpr T a1 = s3[0];
		T a2 = s5[0];
		s5.push_back(T('a'));
		s5.pop_back();
		s5.append(&a[0]);
		s5.clear();			
	}
	constexpr T a[] = {T('h'), T('i'), T(0)};
	constexpr string s(&a[0]);
	return s;	
}

int main()
{
	test_1<char, 128>();
	test_1<unsigned char, 255>();
	test_1<wchar_t, 64>();
	test_2();
	auto s1 = test_3<char, 128>();
	auto s2 = test_3<unsigned char, 255>();
	auto s3 = test_3<wchar_t, 64>();
}
