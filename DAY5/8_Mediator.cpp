// 6_Mediator - 중재자 패턴 
#include <iostream>

class CheckBox
{
	bool state;
public:
	CheckBox() : state(false) {}
	
	void SetCheck(bool b) { state = b; ChangeState(); }
	bool GetCheck()       { return state; }

	// 체크 박스의 상태가 변경될때 아래 가상함수가 호출된다고 생각해 봅시다.
	virtual void ChangeState() {}
};

class MyCheckBox : public CheckBox
{
public:
	void ChangeState() override
	{
		if (GetCheck() == true)
		{
			std::cout << "button enable\n";
		}
		else 
		{
			std::cout << "button disable\n";
		}
	}
};


int main()
{
	MyCheckBox c;
	c.SetCheck(true);
}



