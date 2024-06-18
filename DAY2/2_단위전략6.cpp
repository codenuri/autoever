// 2_단위전략6.cpp
#include <iostream>
#include <string>

int main()
{
	std::cout << std::boolalpha;

	std::string s1 = "ABCD";
	std::string s2 = "abcd";

	bool b = (s1 == s2);

	std::cout << b << std::endl;
}