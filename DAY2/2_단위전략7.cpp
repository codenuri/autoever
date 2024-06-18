#include <iostream>
#include <string>


// std::string �� "����(alias)" �Դϴ�.
// ���� Ŭ���� �̸��� "std::basic_string" �Դϴ�.

template<typename T,  // char �Ǵ� wchar_t ��, �����ڵ����� �ƴ���
	     typename Traits = std::char_traits<T>, // �� ����� ���� ���� ����Ŭ����
		 typename Alloc = std::allocator<T>>    // �޸��Ҵ� ��å
class basic_string
{
	T* buff;
	Alloc ax; // �޸� �Ҵ��
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