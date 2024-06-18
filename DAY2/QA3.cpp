#include <iostream>


int main()
{
	int n = 0;

	std::cin >> n;	// 'a' 입력하세요
	
	if (std::cin.fail())
	{
		std::cout << "입력 실패\n";
	}

	std::cout << n << std::endl; 
}
