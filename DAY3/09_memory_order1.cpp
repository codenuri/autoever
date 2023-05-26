// C/C++ 코드를 어셈블리로 만들기
// 1. 컴파일러 옵션 사용
// g++ reorder1.cpp –S –masm=intel -O2
// cl reorder1.cpp /FAs /c /O2

// 2. 지금은 godbolt.org 라는 아주 훌륭한 사이트가 있습니다.

#include <atomic>

int a = 0;
int b = 0;

// thread A
void foo()
{
    a = b + 1;

    
    std::atomic_thread_fence(
        //     std::memory_order_relaxed);
        //     std::memory_order_acq_rel);
        std::memory_order_seq_cst);

    b = 1;
}

// thread B
void goo()
{
    if (b == 1)
    {
        // a == 1 을 보장할수 있을까 ?
    }
}
// 아주 어려운 문제.!!



// reordering
// => 실행속도를 향상 시키기 위해 
// => 개발자가 작성한 코드가 순차적으로 실행되지 않는 현상

// 1. 컴파일러가 reordering 할수도 있고 => 위 코드
// 2. CPU 가 실행할때 reodering 할수도 있습니다.

// 해결책
// => reordering 할수 없도록 명령을 해야 합니다.
// => std::atomic_thread_fence() 또는
// => atomic 연산에, std::memory_order 옵션으로 사용













