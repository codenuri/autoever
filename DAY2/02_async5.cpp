#include <chrono>
#include <iostream>
#include <future>
#include <random>
#include <vector>
#include <string>
#include <numeric>
#include <execution>
#include "chronometry.h"

// async 예제
// static const int NUM = 100000000; // 1억
// static const int NUM = 10000000; // 
static const int NUM = 1000000; // 

std::vector<int> v1, v2;

void fill_vector()
{
    std::random_device seed;
    std::mt19937 engine(seed());
    std::uniform_int_distribution<int> dist(0, 100);

    v1.reserve(NUM);
    v2.reserve(NUM);

    for (int i = 0; i < NUM; ++i)
    {
        v1.push_back(dist(engine));
        v2.push_back(dist(engine));
    }
}


// vector 내적 구하기
long long single_thread()
{
    return std::inner_product(v1.begin(), v1.end(), v2.begin(), 0LL);
}

long long multi_thread()
{
    const long long block_size = NUM / 4;

    auto v1_first = v1.begin();
    auto v2_first = v2.begin();
    auto v1_last = std::next(v1.begin(), block_size);

    // std::thread : 결과를 얻기 위해 promise/future 등의방법을 사용해야 합니다.
    // std::async  : 기존 함수의 반환값을 그대로 사용가능

    std::future<long long> ft1 = std::async( 
        [v1_first, v1_last, v2_first]()
        { 
            return std::inner_product(v1_first, v1_last, v2_first, 0LL);
        } 
    );

    std::advance(v1_first, block_size);
    std::advance(v2_first, block_size);
    std::advance(v1_last,  block_size);

    std::future<long long> ft2 = std::async(
        [v1_first, v1_last, v2_first]()
        {
            return std::inner_product(v1_first, v1_last, v2_first, 0LL);
        }
    );

    std::advance(v1_first, block_size);
    std::advance(v2_first, block_size);
    std::advance(v1_last, block_size);

    std::future<long long> ft3 = std::async(
        [v1_first, v1_last, v2_first]()
        {
            return std::inner_product(v1_first, v1_last, v2_first, 0LL);
        }
    );

    std::advance(v1_first, block_size);
    std::advance(v2_first, block_size);
    v1_last = v1.end();

    std::future<long long> ft4 = std::async(
        [v1_first, v1_last, v2_first]()
        {
            return std::inner_product(v1_first, v1_last, v2_first, 0LL);
        }
    );

    // 이제 주스레드가 각각 스레드의 결과를 대기했다가 더하면 됩니다.
    return ft1.get() + ft2.get() + ft3.get() + ft4.get();
}

int main()
{
    fill_vector();
    
//    single_thread();
//    multi_thread();

    auto r1 = chronometry(single_thread);
    auto r2 = chronometry(multi_thread);

    std::cout << "result1 : " << r1 << std::endl;
    std::cout << "result2 : " << r2 << std::endl;
}

// C++ 에서 스레드를 만드는 방법은 결국 2개 입니다.

// 1. std::thread, std::jthread 사용
//                  => 스레드로 수행된 함수의 결과를 얻기위해
//                  => promise/future 등을 사용
// 
// 2. std::async() 사용
//                  => 스레드 풀에 생성
//                  => 스레드 함수의 결과를 std::future로
//                     바로 얻을수 있다.
//                  => 기존 함수를 수정할 필요 없이 결과를 얻는다