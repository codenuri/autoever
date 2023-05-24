// 04_thread1-1
#include <Windows.h>
#include <iostream>

// C 언어로 스레드 만들기
DWORD __stdcall foo(void* p)
{
	return 100;
}

int main()
{
	// 리눅스 : pthread_create()
	// window : CreateThread()
	HANDLE h = CreateThread(0, 0, &foo, 0, 0, 0);

	Sleep(1000); // 1초 대기

	DWORD code;
	GetExitCodeThread(h, &code);

	printf("스레드 종료 코드값 : %d\n", code);

	CloseHandle(h); // 이순간 "--스레드 커널객체.참조계수"	
					// 참조계수가 0이되면 파괴
					// C++ 의 "t.detach()" 가 하는 일..

	// 핸들을 닫지(detach()) 않으면
	// 1. 새로운 스레드가 종료되어도 주스레드가 살아 있는 동안
	//    커널 객체가 파괴되지 않습니다. 
	//   => 좀비 스레드..

	// 2. 주 스레드에서 새로운 스레드 핸들이 필요 없으면
	//    핸들 즉시 닫는 것이 좋습니다.(detach())

	// 3. 단, 대기하려면(join) 핸들을 가지고 있어야 합니다.

	// 4. 주스레드가 종료되면
	// => OS 자동으로 모든 핸들을 닫아 줍니다.
}