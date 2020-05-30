#ifndef CEXPR
#define CEXPR
#include <cstddef>
#include <stdexcept>
namespace ra::cexpr{
	// A basic string class template for use in constexpr contexts
	template<class T, std::size_t M>
	class cexpr_basic_string{
		public:
			// An unsigned integral type used to represent sizes
			using size_type = std::size_t;

			// The type of each character in the string (i.e., an alias for
			// the template parameter T)
			using value_type = T;

			// The type of a mutating pointer to each character in the string
			using pointer = T*;

			// The type of a non-mutating pointer to each character in the
			// string
			using const_pointer = const T*;

			// The type of a mutating reference to a character in the string
			using reference = T&;

			// The type of a non-mutating reference to a character in the
			// string
			using const_reference = const T&;

			// A mutating iterator type for the elements in the string
			using iterator = pointer;

			// A non-mutating iterator type for the elements in the string
			using const_iterator = const_pointer;

			// Creates an empty string (i.e., a string containing no
			// characters)
			constexpr cexpr_basic_string() : charArray_{0}, charSize_(0) {}

			// Explicitly default some special members
			constexpr cexpr_basic_string(const cexpr_basic_string&) = default;
			constexpr cexpr_basic_string& operator=(const cexpr_basic_string&) = default;
			~cexpr_basic_string() = default;

			// Creates a string with the contents given by the
			// null-terminated character array pointed to by s
			// If the string does not have sufficient capacity to hold
			// the character data provided, an exception of type
			// std::runtime_error is thrown
			constexpr cexpr_basic_string(const value_type* s) : charArray_{0}, charSize_(0){
				while(s[charSize_] != nullChar_){
					if(M < (charSize_+1)){ 
						throw std::runtime_error("String does not have sufficient capacity"); 
					}
					charArray_[charSize_] = s[charSize_];
					++charSize_;
				}
			}

		private:
			value_type charArray_[M+1];
			size_type charSize_;
			const value_type nullChar_ = value_type(0);
	};
}
#endif
