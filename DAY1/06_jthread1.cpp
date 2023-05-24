#include <iostream>
#include <thread>

// join_thread 

void foo(int a, int b)
{
	std::cout << "foo : " << a << ", " << b << std::endl;
}

// 소멸자에서 자동으로 join 되는 클래스
class scoped_thread
{
	std::thread impl;
public:
	scoped_thread(std::thread&& t) : impl(std::move(t)) {}

	~scoped_thread()
	{
		if (impl.joinable())
			impl.join();
	}
};

int main()
{
	// 1. std::thread 사용시 항상 join()/detach()필요
    std::thread t1(&foo, 10, 20);
	t1.join();

	scoped_thread sc1(std::thread(&foo, 10, 20)); 

	std::thread t2(&foo, 10, 20);
	scoped_thread sc2(std::move(t2));
}

