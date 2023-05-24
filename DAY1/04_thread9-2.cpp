#include <thread>
#include <numeric>
#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>

constexpr std::size_t sz = 1000000;

std::vector<int> v;

void init()
{
    for (int i = 0; i < sz; ++i)
    {
        v.push_back(i);
    }
}
//----------------------------------

template<typename IT, typename RT>
void sum(IT first, IT last, RT& result)
{
    result = std::accumulate(first, last, result);
}





template<typename IT, typename RT>
RT parallel_sum(IT first, IT last, RT init)
{
    // 1. 요소의 갯수 파악
    // auto cnt_element = last - first; // 임의접근 반복자만 가능
    auto cnt_element = std::distance(first, last);

    if (cnt_element == 0) return 0;

    // 2. 현재 PC 에서 동시에 실행가능한 스레드 갯수 구하기
    // => 일반적으로 CPU 갯수 * 2
    std::size_t cnt_hw_thread = std::thread::hardware_concurrency();

    if (cnt_hw_thread == 0) // 정보를 구할수 없다면
        cnt_hw_thread = 2;

    std::cout << cnt_hw_thread << std::endl;


    return 0;

}







int main()
{
    init();

    int s = parallel_sum(v.begin(), v.end(), 0);


    std::cout << s << std::endl;
}
