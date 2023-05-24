#include <thread>

// copy, move

void foo() {}
void goo() {}

int main()
{
    std::thread t1(&foo);
    std::thread t2(&goo);

    // 1. swap
    t1.swap(t2); // ok

    // 2. copy 는 안되고 move 는 가능
//  std::thread t3 = t1; // error. 복사 생성자가 삭제됨
    std::thread t4 = std::move(t1); // ok
                // 이제, t1은 자원이 없으므로 join 안됨.

    // 3. 스레드 객체만 먼저 만들고 스레드 자체는 나중에 생성하려면
    std::thread t5; // 아직 스레드 생성 안됨


    t5 = std::thread(&foo); // ok. 이순간 스레드 생성
        // ^ 위 객체는 임시객체 이므로 rvalue
        //   move 로 대입.

    t5.join();


    t2.join();
    t4.join();
}

