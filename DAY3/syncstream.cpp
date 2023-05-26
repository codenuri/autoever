// syncstream
#include <iostream>
#include <thread>
#include <syncstream>

void foo()
{
	std::cout << "foo" << "1" << "2" << std::endl;
}

int main()
{
	std::thread t1(foo);
	std::thread t2(foo);

	t1.join();
	t2.join();
}