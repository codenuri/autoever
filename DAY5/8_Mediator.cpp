// 6_Mediator - ������ ���� 
#include <iostream>

class CheckBox
{
	bool state;
public:
	CheckBox() : state(false) {}
	
	void SetCheck(bool b) { state = b; ChangeState(); }
	bool GetCheck()       { return state; }

	// üũ �ڽ��� ���°� ����ɶ� �Ʒ� �����Լ��� ȣ��ȴٰ� ������ ���ô�.
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



