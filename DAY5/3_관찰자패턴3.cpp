//1_관찰자패턴1 - 94 page
#include <iostream>
#include <vector>


class Subject;

struct IGraph
{
	virtual void update(int data) = 0;
	virtual ~IGraph() {}

	// 관찰자(Graph) 도 자신이 어떤 객체(Table)를 
	// 관찰하는지 알아야 한다.
	// 그래야, 관찰의 대상에 접근해서 Data 를 얻을수 있다.
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
		// Table 이 변경되었다고 통보가 왔으므로,
		// Table 에 접근해서 데이타를 얻어서, 화면을 update 한다.
	//	int* data = subject->get_data(); // error. subject 는 Subject* 이므로
										 // Table* 로 캐스팅후 사용해야 한다.

		int* data = static_cast<Table*>(subject)->get_data();


		// QT 의 Model/View 구조, MFC 의 Doc/View 구조가 관찰자 패턴입니다.
		// => 그런데, 이런 라이브러리 사용시 항상 위처럼 캐스팅을 하게 됩니다.


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





