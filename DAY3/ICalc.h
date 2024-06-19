#pragma once

// Proxy 의 수명을 reference counting 기반으로 으로 관리한다면
// 관련 함수는 반드시 인터페이스에서 노출해주어야 합니다.
// => 사용자(클라이언트)는 결국 인터페이스만을 사용하게 되므로...

// 서버가 여러종류가 있고, 각각 Proxy 가 있다면
// 모든 Proxy 에 참조계수 함수가 필요 합니다
// 참조계수 함수만 별도의 인터페이스로 설계후 상속
struct IRefCount
{
	virtual void AddRef() = 0;
	virtual void Release() = 0;

	virtual ~IRefCount() {}
};


struct ICalc : public IRefCount
{
	virtual int Add(int a, int b) = 0;
	virtual int Sub(int a, int b) = 0;
	virtual ~ICalc() {}
};






ICalc* load_proxy()
{
	void* addr = ec_load_module("CalcProxy.dll");
	using PF = ICalc * (*)();

	PF f = (PF)ec_get_function_address(addr, "CreateProxy");

	ICalc* calc = f();
	return calc;
}