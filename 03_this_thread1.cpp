#include <iostream>
#include <thread>
#include <vector>
#include <unordered_set>

// std::this_thread namespace 안에 4개의 도움 함수가 있습니다.

int main()
{
    // 1. std::this_thread::get_id() : 현재 스레드 ID 얻기
    std::cout << std::this_thread::get_id() << std::endl;

    // 2. 스레드 ID 타입 알아 두세요
    std::thread::id tid1 = std::this_thread::get_id();

    // 특징 1
    int n = tid1; // error. 정수 변환 안됩니다.

    // 특징 2. 컨테이너에 보관 가능하고, hash 도 가능
    std::vector< std::thread::id> v; // ok..
    std::hash< std::thread::id> h;   // ok

    // 특징 3.  == , != 연산 가능합니다.
    tid1 == tid1; 

}