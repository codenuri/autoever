#include <iostream>
#include <thread>
#include <chrono>
using namespace std::literals;

time_t toUTC(std::tm& timeinfo)
{
#ifdef _WIN32
    std::time_t tt = _mkgmtime(&timeinfo);
#else
    time_t tt = timegm(&timeinfo);
#endif
    return tt;
}

std::chrono::system_clock::time_point createDateTime(int year, int month, int day, int hour, int minute, int second)
{
    tm timeinfo1 = tm();
    timeinfo1.tm_year = year - 1900;
    timeinfo1.tm_mon = month - 1;
    timeinfo1.tm_mday = day;
    timeinfo1.tm_hour = hour;
    timeinfo1.tm_min = minute;
    timeinfo1.tm_sec = second;
    tm timeinfo = timeinfo1;
    time_t tt = toUTC(timeinfo);
    return std::chrono::system_clock::from_time_t(tt);
}

int main()
{
    // 1. 스레드 재우는 함수 : sleep_for
    // => 인자는 chrono 라이브러리 형태로 전달해야 합니다.
    std::this_thread::sleep_for(3); // error

    // 0.1s 이렇게도 사용가능하나요? => 안됩니다.  100ms 로 사용하세요
    std::chrono::seconds sec(3);
    std::this_thread::sleep_for(sec); // ok

//  std::this_thread::sleep_for(3us);
    std::this_thread::sleep_for(3s); // 이렇게도 사용가능
                            // "user define literal 문법"
                            // 3s 가 결국 std::chrono::seconds 반환
    
    // 2. sleep_for : 특정 시간 동안
    //    sleep_until : 특정 시간 까지
   
    auto t1 = createDateTime(2023, 5, 25, 12, 0, 0);
    std::this_thread::sleep_until(t1);
}

// chrono : 시간/날짜 관련 C++ 표준 라이브러리




