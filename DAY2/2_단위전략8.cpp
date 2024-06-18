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

// ���ڿ� �� ��å�� ���� ��å Ŭ����
// => cppreference.com ���� std::basic_string �˻��ϼ���

// �Ʒ� �ڵ��� ����
// 1. ǥ���� "std::char_traits<char>"�� ���� �ʿ��� ��� �Լ��� ��ӹ����Ŀ�
// 2. ��ҹ��� ���� ����Ǿ�� �ϴ� �Լ��� �ٽ� ����� �ִ� �ڵ�

struct MyCharTraits : public std::char_traits<char>
{
    static char to_upper(char ch)
    {
        return std::toupper((unsigned char)ch);
    }

    static bool eq(char c1, char c2)
    {
        return to_upper(c1) == to_upper(c2);
    }

    static bool lt(char c1, char c2)
    {
        return to_upper(c1) < to_upper(c2);
    }

    static int compare(const char* s1, const char* s2, std::size_t n)
    {
        while (n-- != 0)
        {
            if (to_upper(*s1) < to_upper(*s2))
                return -1;
            if (to_upper(*s1) > to_upper(*s2))
                return 1;
            ++s1;
            ++s2;
        }
        return 0;
    }

    static const char* find(const char* s, std::size_t n, char a)
    {
        const auto ua{ to_upper(a) };
        while (n-- != 0)
        {
            if (to_upper(*s) == ua)
                return s;
            s++;
        }
        return nullptr;
    }
};

using   ci_string = std::basic_string<char, MyCharTraits>;
//using ci_string = std::basic_string<char, MyCharTraits, std::allocator<char>>;



int main()
{
	std::cout << std::boolalpha;

	ci_string s1 = "ABCD";
	ci_string s2 = "abcd";

	bool b = (s1 == s2);

	std::cout << b << std::endl;
}