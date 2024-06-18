#include <iostream>
#include <string>


// std::string 은 "별명(alias)" 입니다.
// 실제 클래스 이름은 "std::basic_string" 입니다.

template<typename T,  // char 또는 wchar_t 즉, 유니코드인지 아닌지
	     typename Traits = std::char_traits<T>, // 비교 방법을 담은 단위 전략클래스
		 typename Alloc = std::allocator<T>>    // 메모리할당 정책
class basic_string
{
	T* buff;
	Alloc ax; // 메모리 할당기
public:
	bool operator==(const std::basic_string& s)
	{
		return ? ;
	}
};

using string = std::basic_string<char>;
using wstring = std::basic_string<wchar_t>;
//-----------------------------------------------


int main()
{
	std::cout << std::boolalpha; 

	std::string s1 = "ABCD";
	std::string s2 = "abcd";

	bool b = (s1 == s2);

	std::cout << b << std::endl; 
}