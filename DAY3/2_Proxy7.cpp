#define USING_GUI
#include "cppmaster.h"

#include "ICalc.h"


int main()
{
	// Proxy 사용자의 규칙

	ICalc* calc1 = load_proxy(); 

	calc1->AddRef();		// 규칙 1. Proxy 를 처음 얻으면 참조계수증가

	ICalc* calc2 = calc1;	
	calc2->AddRef();		// 규칙 2. Proxy 포인터를 복사하면 참조계수 증가


	calc2->Release();		// 규칙 3. 포인터를 더이상 사용하지 않으면 참조계수 감소

	std::cout << "---------------\n";
	
	calc1->Release();

	std::cout << "---------------\n";

}





