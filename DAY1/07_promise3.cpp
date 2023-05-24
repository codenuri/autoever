#include <iostream>
#include <thread>
#include <future>
#include <vector>
#include <numeric>

int main()
{
    std::vector<int> v1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    std::vector<int> v2(10);

    // 작업 1. v1의 부분합을 구해서 v2에 넣기
    std::partial_sum(v1.begin(), v1.end(), v2.begin()); 

    // 작업 2. v2의 모든 요소 출력
    for (auto n : v2)
        std::cout << n << ", ";

    // 작업 3. v2의 모든 요소의 합을 구하기
    int s = std::accumulate(v2.begin(), v2.end(), 0);
    
    // 작업 4. 작업3의 결과를 출력
    std::cout << "\n" << s << std::endl;
}
// 작업 2, 작업 3 : 반드시 작업1이 종료된후에 해야 합니다.

// 핵심 : 작업2 와 작업3은 독립된 작업입니다.
// => 2개의 독립된 작업이 시간이 오래 소요된다면 한개는 다른 스레드로
//    수행하면 빨라집니다.


