#include <iostream>


int main()
{
	int n = 0;

	std::cin >> n;	// 'a' �Է��ϼ���
	
	if (std::cin.fail())
	{
		std::cout << "�Է� ����\n";
	}

	std::cout << n << std::endl; 
}
