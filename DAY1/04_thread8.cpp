#include <vector>
#include <thread>
#include <algorithm>
#include <functional>

void do_work(unsigned id)
{}

int main()
{
    // 1. 스레드를 만들면 반드시 join 또는 detach 해야 합니다
    // => 반드시 객체(t)를 보관하고 있어야 합니다.
    std::thread t(&do_work, 1);
    t.join();


    // 2. create.. 10 thread
    std::vector<std::thread> v1;  // 초기 크기 0

    for (int i = 0; i < 10; i++)
    {
        // 참고..
//      std::thread t1(&do_work, 1);
//      v1.push_back(t1);   // error.  복사 생성자가 필요한데..
                            // std::thread 는 복사 될수 없는타입

        // 방법 1. 임시객체 형태로 넣기
        // v1.push_back( std::thread(&do_work, 1) );

        // 방법 2. push_back 대신에 emplace_back 으로 넣기
        // => push_back    : 대상타입의 객체를 만들어서 전달
        // => emplace_back : 대상타입을 만들기 위한 생성자 인자전달
        v1.emplace_back(&do_work, 1);
    }

    // 모두 join
//  for (auto& t : v1)
//      t.join();

    // 또는 아래 처럼
    std::for_each(v1.begin(), v1.end(),
                        [](auto& t) { t.join(); } );

}
