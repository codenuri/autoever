#include <iostream>


int main()
{
	int n = 0;

	while (1)
	{
		std::cin >> n;	// 'a' 입력하세요

		if (std::cin.fail())
		{
			std::cout << "입력 실패\n";
			continue;
		}

		break;
	}

	std::cout << n << std::endl; 
}
