#include <iostream>
#include <thread>
#include <future>
#include <vector>
#include <numeric>

void work3(std::promise<int>& pr, std::vector<int>& v2)
{
    int s = std::accumulate(v2.begin(), v2.end(), 0);

    pr.set_value(s);
}

int main()
{
    std::vector<int> v1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    std::vector<int> v2(10);

    // 작업 1. 
    std::partial_sum(v1.begin(), v1.end(), v2.begin());



    // 스레드를 생성해서 작업3을 수행
    std::promise<int> pr;
    std::future<int> ft = pr.get_future();

    std::thread t(work3, std::ref(pr), std::ref(v2) );


    // 작업 2. 
    for (auto n : v2)
        std::cout << n << ", ";

    // 작업 3. 
    // int s = std::accumulate(v2.begin(), v2.end(), 0);
    int s = ft.get(); // 스레드 결과 대기


    // 작업 4. 
    std::cout << "\n" << s << std::endl;
}



