#include <iostream>
#include <thread>

// join 에 대해서

void foo() {}

int main()
{    
    std::thread t1(&foo);

    // 1. 2번 join 안됨
    t1.join();  // 1. 스레드 종료 할때 까지 대기
                // 2. 종료되면 t1이 가진 내부 핸들을 close

    t1.join();  // runtime error. 이미 핸들 닫힘.
                // 즉, 2번 join 안됨.

    // 2. 스레드를 생성하지 않은 경우 join 안됨
    std::thread t2; // 함수 전달하지 않았으므로 스레드 생성안됨.
    t2.join();      // runtime error.(예외 발생)

    // 3. join 가능한가를 조사 가능
    if (t2.joinable())
    {
        t2.join();
    }

    // 4. joinable() 는 join()가능한가를 조사하는것
    //   => 스레드가 살아있는가는 조사하는 것은 아님..

    std::thread t3(&long_time_function);
    std::thread t4(&short_time_function);

    // short_time_function 종료된후..

    bool b1 = t3.joinable(); // 스레드가 살아있건
    bool b2 = t4.joinable(); // 스레드가 이미 종료 되었건
                             // 모두 join 가능하므로 true
    // join 이 불가능한 경우는
    std::thread t5; // 스레드가 생성되지 않았거나
    std::thread t6(&foo); // 스레드 생성후
//  t6.join();  
    t6.detach(); // 이미 join 했거나 detach 한경우... 


    
}
