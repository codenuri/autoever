#pragma once

// ICalc.h �� �Ʒ� �ڵ� ����
struct ICalc
{
	virtual int Add(int a, int b) = 0;
	virtual int Sub(int a, int b) = 0;
	virtual ~ICalc() {}
};