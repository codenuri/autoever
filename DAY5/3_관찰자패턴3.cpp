//1_����������1 - 94 page
#include <iostream>
#include <vector>


class Subject;

struct IGraph
{
	virtual void update(int data) = 0;
	virtual ~IGraph() {}

	// ������(Graph) �� �ڽ��� � ��ü(Table)�� 
	// �����ϴ��� �˾ƾ� �Ѵ�.
	// �׷���, ������ ��� �����ؼ� Data �� ������ �ִ�.
	Subject* subject = nullptr;
};


class Subject
{
	std::vector<IGraph*> v;
public:
	void attach(IGraph* p) { v.push_back(p); p->subject = this; }
	void detach(IGraph* p) {}
	void notify(int data)
	{
		for (auto p : v)
			p->update(data);
	}
};

class Table : public Subject
{
	int value;

	int data[32];
public:
	int* get_data() { return data; }

	void edit()
	{
		while (1)
		{
			std::cout << "Data >>";
			std::cin >> value;
			notify(value);
		}
	}
};
//----------------------
class BarGraph : public IGraph
{
public:
	void update(int n) override
	{
		// Table �� ����Ǿ��ٰ� �뺸�� �����Ƿ�,
		// Table �� �����ؼ� ����Ÿ�� ��, ȭ���� update �Ѵ�.
	//	int* data = subject->get_data(); // error. subject �� Subject* �̹Ƿ�
										 // Table* �� ĳ������ ����ؾ� �Ѵ�.

		int* data = static_cast<Table*>(subject)->get_data();


		// QT �� Model/View ����, MFC �� Doc/View ������ ������ �����Դϴ�.
		// => �׷���, �̷� ���̺귯�� ���� �׻� ��ó�� ĳ������ �ϰ� �˴ϴ�.


		std::cout << "Bar Graph : ";

		for (int i = 0; i < n; i++)
			std::cout << "*";

		std::cout << std::endl;
	}
};

class PieGraph : public IGraph
{
public:
	void update(int n) override
	{
		std::cout << "Pie Graph : ";

		for (int i = 0; i < n; i++)
			std::cout << ")";

		std::cout << std::endl;
	}
};


int main()
{
	Table t;

	PieGraph pg; t.attach(&pg);
	BarGraph bg; t.attach(&bg);

	t.edit();
}





