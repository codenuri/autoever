#include <iostream>
#include <thread>
#include <mutex>
#include "chronometry.h"

constexpr unsigned int cnt = 1000000;

std::mutex m;

long x = 0; // 모든 스레드가 공유.

void foo()
{
    for (int i = 0; i < 1000000; ++i)
    {
//      x = x + 1;  

        // 위 한줄은 결국 아래 3줄의 기계어 코드 입니다.
        // VS 사용하시는 분은 "32bit(x86)" 으로 빌드하시면 됩니다.
        /*
        __asm
        {
            mov     eax, x
            add     eax, 1
            mov     x, eax
        }
        */

        // 결국 "전역변수를 1증가" 하는 것도 멀티 스레드 환경에서는
        // 동기화 필요 합니다.

        // 방법 1. mutex 등의 도구 사용
        // => 단지 1을 증가하기 위해 mutex 를 사용하는 것은 
        //    오버헤드가 크다.
        /*
        m.lock();
        x = x + 1;
        m.unlock();
        */

        // 방법 2. 멀티스레드에 안전한 기계어 코드 사용
        // => inc 명령은 "실행중에 context switch" 가 발생하지 않는다
        // => 아래 코드는 단일 CPU 일때는 안전합니다.
        // => 하지만 멀티 코어 CPU 는 안전하지 않습니다
        /*
        __asm
        {
            inc x;
        }
        */
        // 방법 3. 멀티 코어 CPU 의 경우 
        // => 멀티 코어에 안전하게 메모리 접근이 가능한 OPCODE 사용
        // => 각 CPU 제공하는 명령어 사용
        // => 인텔 호환 "lock" 접두어 : 하나의 CPU가 사용하는 메모리를
        //                          다른 CPU가 접근못하게
        __asm
        {
            lock inc x;
        }

        // 위 처럼, OS 의 lock 이 아닌 CPU 가 제공하는 
        // 기술을 사용하는 것을 "lock-free" 라고 합니다.
        // lock-free : OS 의 lock 을 사용하지 않는다는것!
        //               CPU가 제공하는 명령으로 사용
    }
}

int main()
{
    std::thread t1(foo);
    std::thread t2(foo);
    std::thread t3(foo);
    t1.join();
    t2.join();
    t3.join();
    std::cout << x << std::endl;
}
