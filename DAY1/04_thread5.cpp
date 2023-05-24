#include <iostream>
#include <thread>
#include <windows.h>
#include <chrono>
using namespace std::literals;

// 스레드 우선 순위
// => C++ 스레드 라이브러리는 "스레드 우선순위" 지원 안함.
// => 사용하고 싶으면 "native handle" 을 얻어서 각 OS의 시스템 call 사용
void foo()
{
    auto tid = std::this_thread::get_id(); // 스레드 ID 얻기
}

int main()
{
    std::thread t(&foo);

    // auto
    std::thread::native_handle_type handle = t.native_handle();
    // windows : HANDLE
    // linux   : pthread_t

    // 이제 다양한 OS의 스레드 관련 시스템 call 사용가능
    SetThreadPriority((HANDLE)handle, THREAD_PRIORITY_HIGHEST);

    t.join();
}

