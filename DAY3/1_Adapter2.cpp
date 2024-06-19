#include <iostream>
#include <string>
#include <vector>

class TextView
{

	std::string data;
public:
	TextView(const std::string& s) : data(s) {}

	void show() { std::cout << data << std::endl; }
};





class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};


class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw circle" << std::endl; }
};

// Adapter �� ����
// Ŭ���� ����� : Ŭ������ �������̽��� �����ϴ� ��
// ��ü   ����� : ��ü��   �������̽��� �����ϴ� ��


// Text : Ŭ���� �����
class Text : public TextView, public Shape		
{
public:
	Text(const std::string& s) : TextView(s) {}

	void draw() override
	{
		TextView::show();
	}
};

// ObjectAdapter : ��ü �����
class ObjectAdapter : public Shape
{
	TextView* tview; // ����� �ƴ϶�, ������(�Ǵ� ����)�� ����!!
					 // �ǵ� : �ܺο� �̹� ������ "TextView ��ü"�� ����Ű�ڴٴ°�
public:
	ObjectAdapter(TextView* tv) : tview(tv) {}

	// �Ʒ� �Լ��� �������̽��� �����Ѱ�. 
	void draw() override { tview->show(); }
};

// TextView tv("hello");
// tv.show(); // tv �� ���� ����ϸ� show() �� �׷��� ������

// ObjectAdapter oa(&tv);
// oa.draw(); // oa �� ����ϸ� draw() �� �׸��� �ִ�.

int main()
{
	std::vector<Shape*> v;

	TextView tv("hello");	// TextView : Ŭ����
							// tv       : ��ü

	// �̹� ������ TextView Ÿ���� "��ü tv" �� ���������� �ý��ۿ� ������ ������ ?
//	v.push_back( &tv );	// error. Shape �� ���� �Ļ����� �ʾҴ�
						
	// Text �� ����Ҽ��� ����!!
	// tv�� ����������(v) �� �������� "��ü �����" �ʿ�!!


	v.push_back( new ObjectAdapter(&tv) ); // ok... ��ü ����ͷ� ����!!

	v[0]->draw();
}









