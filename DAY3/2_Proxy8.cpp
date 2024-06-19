#define USING_GUI
#include "cppmaster.h"

#include "ICalc.h"

// 참조계수를 자동관리하기 위한 스마트 포인터
// "안드로이드 OS" 에는 "sp" 라는 스마트 포인터가 아래와 유사합니다

template<typename T> class sp
{
	T* obj;
public:
	sp(T* p = nullptr) : obj(p) { if (obj != nullptr) obj->AddRef(); }
	sp(const sp& other) : obj(other.obj) { if (obj != nullptr) obj->AddRef(); }
	~sp() { if (obj != nullptr) obj->Release(); }

	// 스마트 포인터 핵심 : 진짜 포인터는 아니지만 포인터 처럼 -> 와 * 를 사용할수 있어야 한다.

	T* operator->() { return obj; }
	T& operator*() { return *obj; }
};

int main()
{
	sp<ICalc> calc1 = load_proxy(); // sp<ICalc> calc1( load_proxy() )
	sp<ICalc> calc2 = calc1;

	// calc1 은 포인터가 아니지만 포인터 역활이므로 아래처럼 사용할수 있어야 합니다.
	int n1 = calc1->Add(1, 2);
	int n2 = calc1->Sub(1, 2);
}

/*
int main()
{	
	ICalc* calc1 = load_proxy();
	calc1->AddRef();		

	ICalc* calc2 = calc1;
	calc2->AddRef();		


	calc2->Release();		
	calc1->Release();		
}

*/



