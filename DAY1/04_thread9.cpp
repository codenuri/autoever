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
int main()
{
    init();

    // sum : v의 모든 요소의 합을 구하는 함수
    int s = 0;
//  sum(v.begin(), v.end(), s); // 주스레드가 직접 호출

//  std::thread t(sum, v.begin(), v.end(), std::ref(s) );
                // error, sum 이 템플릿 인데..
                // sum을 직접 호출하는 모양이 아니므로 타입 추론이 안됩니다.

    std::thread t(sum<std::vector<int>::iterator, int> , 
                    v.begin(), v.end(), std::ref(s));

    t.join();

    std::cout << s << std::endl;
}
