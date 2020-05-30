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

			// Creates a string with the contents specified by the characters
			// in the iterator range [first, last).
			// If the string does not have sufficient capacity to hold
			// the character data provided, an exception of type
			// std::runtime_error is thrown.
			constexpr cexpr_basic_string(const_iterator first, const_iterator last) : charArray_{0}, charSize_(0){
				if(M < (last - first)){
					throw std::runtime_error("String does not have sufficient capacity");
				}
				for(const_iterator i=first; i < last; ++i){
					charArray_[charSize_] = *i;
					++charSize_;
				}
			}

			// Returns the maximum number of characters that can be held by a
			// string of this type.
			// The value returned is the template parameter M
			static constexpr size_type max_size() { return M; }

			// Returns the maximum number of characters that the string can
			// hold. The value returned is always the template parameter M
			constexpr size_type capacity() const { return M; }

			// Returns the number of characters in the string (excluding the
			// dummy null character)
			constexpr size_type size() const { return charSize_; }

			// Returns a pointer to the first character in the string
			// The pointer that is returned is guaranteed to point to a
			// null-terminated character array
			// The user of this class shall not alter the dummy null
			// character stored at data() + size().
			value_type* data(){
				return charArray_;
			}
			const value_type* data() const {
				return charArray_;
			}

			// Returns an iterator referring to the first character in the
			// string
			constexpr iterator begin() {
				return charArray_;
			}
			constexpr const_iterator begin() const {
				return charArray_;
			}

			// Returns an iterator referring to the fictitious
			// one-past-the-end character in the string
			constexpr iterator end(){
				return (&charArray_[charSize_]);
			}
			constexpr const_iterator end() const {
				return (&charArray_[charSize_]);
			}

			// Returns a reference to the i-th character in the string if i
			// is less than the string size; and returns a reference to the
			// dummy null character if i equals the string size.
			// Precondition: The index i is such that i >= 0 and i <= size().
			constexpr reference operator[](size_type i){
				if(i<0 || i>charSize_){
					throw std::domain_error("invalid array access");
				}
				if(i==charSize_){ return nullChar_; }
				else{ return charArray_[i];}
			}
			constexpr const_reference operator[](size_type i)const{
				if(i<0 || i>charSize_){
					throw std::domain_error("invalid array access");
				}
				if(i==charSize_){ return nullChar_; }
				else{ return charArray_[i];}
			}

		private:
			value_type charArray_[M+1];
			size_type charSize_;
			const value_type nullChar_ = value_type(0);
	};
}
#endif
