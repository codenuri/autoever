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

			// 다시 시도하기 전에..
			// 아래 2개의 작업을 해야 합니다.(반드시 순서를 지켜야 합니다.)
			std::cin.clear();  // 1. cin 의 상태 비트를 모두 clear 해야합니다.
			std::cin.ignore(); // 2. 입력 버퍼를 비워야 합니다.
			
			continue;
		}

		break;
	}

	std::cout << n << std::endl; 
}
