# cpp-compile_time
A couple of implementations are involved in this project:

1)  A class template for representing a sequence of characters (i.e., a string) that can be used in constexpr
contexts will be developed. This class template is called cexpr_basic_string. The cexpr_basic_string class
template has two template parameters:
    (a) T. The type of each character in the string (e.g., char, unsigned char, wchar_t).
    (b) M. The maximum number of characters that can be held in the string.
The cexpr_basic_string class template always stores character string data internally in null-terminated form.
That is, an additional dummy null-character (i.e., a character with the value value_type(0)) is always stored
immediately following the last character in the string. This dummy character is always present, even in the case
of an empty string.

2)  Code is developed that can be used to compute an image representation of the Mandelbrot set at compile time.
The computed image is made available through a variable template called mandelbrot, which is of type cexpr_string.
This string variable holds the image encoded in the text-based bitmap PNM format.

3)  Numerous variable and function templates are developed that provide support for math constants (such as π)
and math functions (such as sin and square root) that can be used in constexpr contexts.

4)  Code is developed that can be used to design several types of discrete-time biquad filters. This code
consists of a class template biquad_filter_coefs that is used to represent the coefficients of a biquad filter as
well as several function templates that can be used to design various types of filters. These filter-design
function templates can be employed in constexpr contexts.
