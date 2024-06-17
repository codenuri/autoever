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
	Animal a;
	Dog d;

	Animal* p = &d;

	if (사용자 입력 == 1) p = &a;

	// 핵심 #1. 컴파일시간에 컴파일러는 p가 가리키는 객체의 종류는
	//          알수 없다.(조사할수 없다.)
	//          


}











