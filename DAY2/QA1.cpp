// QA1.cpp
#include <iostream>

// 핵심 #1. 버퍼(stream) 기반 입력을 이해 해야 합니다.
int main()
{
	int n1 = 0;
	int n2 = 0;

	std::cin >> n1;
	std::cin >> n2;

	std::cout << n1 << ", " << n2 << std::endl;
}