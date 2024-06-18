#include <iostream>
#include <string>


/*
template<typename T, 
	typename Traits = std::char_traits<T>,
	typename Alloc = std::allocator<T>>   
	class basic_string
{
	T* buff;
	Alloc ax; 
public:
	bool operator==(const std::basic_string& s)
	{
		return Traits::compare(buff, s.buff, strlen(buff));
	}
};
using string = std::basic_string<char>;
using wstring = std::basic_string<wchar_t>;
*/
//-----------------------------------------------

// 문자열 비교 정책을 가진 정책 클래스
struct MyCharTraits
{
};

using   ci_string = std::basic_string<char, MyCharTraits>;
//using ci_string = std::basic_string<char, MyCharTraits, std::allocator<char>>;



int main()
{
	std::cout << std::boolalpha;

	std::string s1 = "ABCD";
	std::string s2 = "abcd";

	bool b = (s1 == s2);

	std::cout << b << std::endl;
}