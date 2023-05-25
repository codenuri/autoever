#include <mutex>

std::mutex m;

// C++ 에서 lock 을 관리하는 도구는 4개 입니다.

// std::lock_guard : 가장 가볍다, 생성자, 소멸자만 존재

// std::unique_lock : 가장 무겁다, 기능이 가장 많다.
//					 std::condition_variable 사용시 반드시 필요

// std::shared_lock : shared_mutex 전용

// std::scoped_lock : 여러개 뮤텍스를 동시에 안전하게 lock

int main()
{
	// lock_guard 를 사용하는 2가지 방법
	// 1. 생성자에서 lock 획득
	{
		std::lock_guard<std::mutex> lg(m);
	}

	// 2. 이미 lock 획득한 상태의 뮤텍스 관리
	if (m.try_lock())
	{
		std::lock_guard<std::mutex> lg(m, std::adopt_lock);
	}

	
}



