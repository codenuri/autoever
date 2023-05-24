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
	HANDLE h = CreateThread(0, 0, &foo, 0, 0, 0);

	CloseHandle(h);
}