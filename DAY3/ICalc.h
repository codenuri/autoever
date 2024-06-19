#pragma once

// ICalc.h 에 아래 코드 복사
struct ICalc
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