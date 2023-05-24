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

class join_thread
{
	std::thread impl;
public:
	// modern C++의 완벽한 전달 기술
	template<typename F, typename ... ARGS>
	join_thread(F&& f, ARGS&& ...args) 
		: impl( std::forward<F>(f), 
				std::forward<ARGS>(args)...) 
	{}

	~join_thread()
	{
		if (impl.joinable())
			impl.join();
	}
};

int main()
{
	scoped_thread sc(std::thread(&foo, 10, 20));

	join_thread jt(&foo, 10, 20);


}

