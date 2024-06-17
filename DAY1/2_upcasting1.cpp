class Animal
{
public:
	int age;
};
class Dog : public Animal
{
public:
	int color;
};
int main()
{
	Dog d;

	Dog* p1 = &d;		// ok
	
//	int* p2 = &d;		// error. ���� ���� Ÿ���� ������!!
	
	// �ٽ� #1. ��� Ŭ���� Ÿ���� �����Ϳ� �Ļ� Ŭ���� ��ü�� �ּҸ�
	//		    ������ �ִ�.
	// => "upcasting" �̶�� �մϴ�.
	// => ������ ������ "Dog ��ü �ȿ��� Animal�� ����" �մϴ�.

	Animal* p3 = &d;  // ok


	// �ٽ� #2. "Animal*" �� p3 �δ� Animal �� ����� ���� �Ҽ� �ִ�.
	// => "Dog �� �߰�" �� ����� ���� �ȵ�.

	p3->age   = 10; // ok
//	p3->color = 10; // error


	// �ٽ� #3. "Animal* p3" �� Dog ���� ����� �����Ϸ���
	//          ĳ���� �ؾ� �մϴ�.
	// => static_cast �Ǵ� dynamic_cast ���

	static_cast<Dog*>(p3)->color = 10;
					// => ��, �̰�� p3 �� ����Ű�� ��ü�� Dog���
					//	  ������ �־�� �մϴ�.
					//    Dog �� �ƴϸ� "������ ���� �߻�"

	// p3 �� ����Ű�� ���� Dog ���� �����Ҽ� ������ ??
	// => dynamic_cast ���

}











