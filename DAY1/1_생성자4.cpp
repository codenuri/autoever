// protected �����ڰ� ������ �ǹ�
// => �ڽ��� ��ü�� �����Ҽ� ������(�߻����� ������ ���� Ŭ����)
// => �ڽ��� �Ļ� Ŭ������ ��ü�� �����Ҽ� �ֵ���(��ü��, concrete)
//    �Ҷ� ���!!!

class Animal
{
// public:			// A, B �� ��� ���� �ƴ�.
// private:			// A, B �� ��� ����.

protected:
	Animal() {}
};
class Dog : public Animal
{
public:
	Dog() {}	// Dog() : Animal() {}
};
int main()
{
	// ������ ������ ��� ��� ������
	Animal a;	// A. error
	Dog    d;	// B. ok 
}



