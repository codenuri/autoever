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

	CloseHandle(h);
}