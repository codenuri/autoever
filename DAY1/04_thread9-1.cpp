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

// 구간의 합을 구하는 함수.
template<typename IT, typename RT>
void sum(IT first, IT last, RT& result)
{
    result = std::accumulate(first, last, result);
}

// 구간의 합을 병렬로 구하는 함수
template<typename IT, typename RT>
RT parallel_sum(IT first, IT last, RT init)
{
    
}

int main()
{
    init();

    int s = parallel_sum(v.begin(), v.end(), 0);
    

    std::cout << s << std::endl;
}
