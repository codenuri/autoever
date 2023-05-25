// threadpool1
#include <iostream>
#include <string>
#include <mutex>
#include <condition_variable>
#include <future>
#include <vector>
#include <queue>
#include <chrono>
using namespace std::literals;

void foo()
{
	for (int i = 0; i < 10; i++)
	{
		std::cout << std::this_thread::get_id() << " : " << i
			<< std::endl;

		std::this_thread::sleep_for(400ms);
	}
}

//-----------------------------------------------------
std::vector<std::thread> v;

using TASK = void(*)();

std::queue<TASK> task_q;

std::mutex m;
std::condition_variable cv;

bool stop_pool = false;




int main()
{

}
