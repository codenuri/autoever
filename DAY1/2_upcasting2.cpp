// upcasting2.cpp
#include <vector>

class Animal {};
class Dog : public Animal {};
class Cat : public Animal {};

int main()
{
	// Upcasting Ȱ�� #1. ������ �����ϴ� �����̳� �����.
	std::vector<Dog*>    v1; // Dog ��ü�� �����ϰڴٴ� �ǵ�!
	std::vector<Animal*> v2; // ����(Animal �� ���� �Ļ��� ��� Ÿ���� ��ü)
							 // �� �����ϰڴٴ� �ǵ�.
}