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

			// �ٽ� �õ��ϱ� ����..
			// �Ʒ� 2���� �۾��� �ؾ� �մϴ�.(�ݵ�� ������ ���Ѿ� �մϴ�.)
			std::cin.clear();  // 1. cin �� ���� ��Ʈ�� ��� clear �ؾ��մϴ�.
			std::cin.ignore(); // 2. �Է� ���۸� ����� �մϴ�.
			
			continue;
		}

		break;
	}

	std::cout << n << std::endl; 
}
