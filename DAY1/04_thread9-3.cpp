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
    auto cnt_element = std::distance(first, last);
    if (cnt_element == 0) return 0;

    std::size_t cnt_hw_thread = std::thread::hardware_concurrency();

    if (cnt_hw_thread == 0) // 정보를 구할수 없다면
        cnt_hw_thread = 2;

    std::cout << cnt_hw_thread << std::endl;

    const std::size_t cnt_per_thread = 25;
    const std::size_t max_cnt_thread =
        (cnt_element + cnt_per_thread - 1) / cnt_per_thread;

    const std::size_t cnt_thread =
        std::min(cnt_hw_thread, max_cnt_thread);

    std::cout << "최종 갯수 : " << cnt_thread << std::endl;
    //--------------------------------------




    return 0;

}







int main()
{
    init();

    int s = parallel_sum(v.begin(), v.end(), 0);


    std::cout << s << std::endl;
}
