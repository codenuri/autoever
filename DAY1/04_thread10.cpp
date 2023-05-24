// 04_thread10
#include <algorithm>
#include <iostream>
#include <vector>
#include <thread>
#include <execution> // C++17 병렬 STL 알고리즘
					 // 69 개 제공
void foo(int e)
{
	std::cout << std::this_thread::get_id()
		      << " : " << e << std::endl;
}
int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

//	std::for_each(v.begin(), v.end(), foo);

	std::for_each(std::execution::par, v.begin(), v.end(), foo);
	// => 스레드를 몇개 만들게 되나요 ???
	// => 내부적으로 "thread pool" 을 사용합니다 - 3일차 만들게 됩니다.
}