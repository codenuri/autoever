#include <iostream>
#include <thread>
#include <future>
#include <chrono>
using namespace std::literals;

void add(int a, int b, int& s)
{
	s = a + b;

	std::this_thread::sleep_for(3s);
}

int main()
{
	int s = 0;
	std::thread t(add, 10, 20, std::ref(s));

	t.join();

	std::cout << s << std::endl;
}



