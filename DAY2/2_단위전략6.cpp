// 2_단위전략6.cpp
#include <iostream>
#include <string>

int main()
{
	std::cout << std::boolalpha; // bool 변수값은 0, 1이 아닌 true, false로 출력해달라

	std::string s1 = "ABCD";
	std::string s2 = "abcd";

	bool b = (s1 == s2);

	std::cout << b << std::endl; // false 
}