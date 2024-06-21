//1_관찰자패턴1 - 94 page
#include <iostream>
#include <vector>

// 모든 그래프(챠트)의 인터페이스
struct IGraph
{
	virtual void update(int data) = 0;
	virtual ~IGraph() {}
};


// 관찰의 대상
class Table
{
	std::vector<IGraph*> v;
	int value; // table 의 data 값
public:
	void attach(IGraph* p) { v.push_back(p); }
	void detach(IGraph* p) {}
	void notify(int data)
	{
		// 등록된 모든 그래프에 알려준다.
		for (auto p : v)
			p->update(data);
	}
	// 데이타를 편집하는 함수.
	void edit()
	{
		while (1)
		{
			std::cout << "Data >>";
			std::cin >> value;		// 데이타가 변경되었으므로
			notify(value);			// 등록된 모든 그래프에 통보!
		}
	}
};
//----------------------
class BarGraph : public IGraph
{
public:
	void update(int n) override
	{
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

	// 관찰의 대상인 Table(t) 에 관찰자(Graph) 를 부탁!
	PieGraph pg; t.attach(&pg);
	BarGraph bg; t.attach(&bg);

	t.edit();	// Table 편집 시작
}





