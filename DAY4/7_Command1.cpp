// 8_Command - 172 page
#include <iostream>
#include <vector>
#include <stack>

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};


class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }
};

// �޴��� ���ý� ����� �ؾ� �Ѵٸ�
// 
// C ��� : �ؾ��� ���� �Լ��� �ۼ��մϴ�.
//			=> �ؾ��� �ϸ� �����մϴ�.
// 
// Command ���� : �ؾ��� ���� Ŭ������ �ۼ� �մϴ�.
//			=> �ؾ����ϰ� 
//			=> ����Ҷ� ����
//			=> ��ҿ� �ʿ��� ����Ÿ���� ��� ���� �����մϴ�.
//			=> "�۾����ߴٴ� ����� �ڷᱸ���� ����"�� �����մϴ�.

// ��� ����� �������̽�
struct ICommand
{
	virtual void execute() = 0;
	virtual bool can_undo() { return false; }
	virtual void undo() {}
	virtual ~ICommand() {}
};

// �簢���� �߰��ϴ� ���
class AddRectCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	AddRectCommand(std::vector<Shape*>& v) : v(v) {}

	void execute() override { v.push_back(new Rect); }

	bool can_undo() override { return true; }

	void undo() override
	{
		Shape* s = v.back();
		v.pop_back();
		delete s;
	}
};






int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1) 
		{
			v.push_back(new Rect);
		}
		else if (cmd == 2) 
		{
			v.push_back(new Circle);
		}
		else if (cmd == 9)
		{
			for (auto p : v)
				p->draw();
		}

	}
}


