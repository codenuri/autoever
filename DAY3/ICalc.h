#pragma once

// Proxy �� ������ reference counting ������� ���� �����Ѵٸ�
// ���� �Լ��� �ݵ�� �������̽����� �������־�� �մϴ�.
// => �����(Ŭ���̾�Ʈ)�� �ᱹ �������̽����� ����ϰ� �ǹǷ�...

// ������ ���������� �ְ�, ���� Proxy �� �ִٸ�
// ��� Proxy �� ������� �Լ��� �ʿ� �մϴ�
// ������� �Լ��� ������ �������̽��� ������ ���
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