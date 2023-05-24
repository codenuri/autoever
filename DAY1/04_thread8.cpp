#include <vector>
#include <thread>
#include <algorithm>
#include <functional>

void do_work(unsigned id)
{}

int main()
{
    // 1. 스레드를 만들면 반드시 join 또는 detach 해야 합니다
    // => 반드시 객체(t)를 보관하고 있어야 합니다.
    std::thread t(&do_work, 1);
    t.join();


    // 2. create.. 10 thread
    std::vector<std::thread> v1;  // 초기 크기 0

    for (int i = 0; i < 10; i++)
    {
        std::thread t1(&do_work, 1);
        v1.push_back(t1); // ??


    }
}
