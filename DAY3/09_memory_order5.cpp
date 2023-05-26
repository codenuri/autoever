#include <thread>
#include <atomic>
#include <cassert>

std::atomic<int> data1 = 0;
std::atomic<int> data2 = 0;

int main()
{
    // memory_order_seq_cst : 동시접근 보호 + 순차적 실행 보장
    //                      => 가장 오버헤드가 큰 모델

    data1.store(100, std::memory_order_seq_cst);
    data2.store(200, std::memory_order_seq_cst);
    data2.store(300); // 옵션 생략시 디폴트 값이 memory_order_seq_cst

    data2 = 300; // 이 코드도 memory_order_seq_cst 입니다.
                 // 순차실행은 필요 없고, 동시접근만 막으려면
                 // data2.store(300, std::memory_order_relaxed)
                 // 가 좀더 효율적입니다.

    // 단, CPU 에 따라 memory_order_seq_cst 만 제공될수도 있습니다.
}

// std::atomic_thread_fence() : 특정한 연산 (대입, + 등) 없이
//                              펜스만 설치(플래그 변수 없이)
// 하지만 대부분 atomic<> 변수를 사용하고, 옵션전달하면 됩니다.
// => atomic_thread_fence 를 사용하는 경우는 많지 않습니다.

// 