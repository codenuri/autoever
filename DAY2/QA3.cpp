#include <iostream>


int main()
{
	int n = 0;

	while (1)
	{
		std::cin >> n;	// 'a' �Է��ϼ���

		if (std::cin.fail())
		{
			std::cout << "�Է� ����\n";
			continue;
		}

		break;
	}

	std::cout << n << std::endl; 
}
