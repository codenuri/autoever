#include <iostream>
#include <thread>
#include <string>

int next3times()
{
	//	int n = 0;		 // 
	static int n = 0;
	n = n + 3;
	return n;
}
void foo(const std::string& name)
{
	std::cout << name << " : " << next3times() << std::endl;
	std::cout << name << " : " << next3times() << std::endl;
	std::cout << name << " : " << next3times() << std::endl;
}
int main()
{
	std::thread t1(foo, "A");
	std::thread t2(foo, "\tB");

	t1.join();
	t2.join();
}
// 결과 예측해 보세요..


