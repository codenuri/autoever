// 04_thread10
#include <algorithm>
#include <iostream>
#include <vector>
#include <thread>

void foo(int e)
{
	std::cout << std::this_thread::get_id()
		      << " : " << e << std::endl;
}

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	std::for_each(v.begin(), v.end(), foo);
}