#include <iostream>
#include <string>
#include <vector>

// �Ʒ� Ŭ������ �̹� �־��ٰ� ������ ���ô�.
// 
// TextView : ���ڿ��� �����ϰ� �ִٰ� ȭ�鿡 �̻ڰ� ����ϴ� ���.
class TextView
{
	// font �̸�, ũ��, ����� �پ��� ��� ����. 
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
// ���������� �ý��ۿ�, Rect, Circle �ܿ��� �߰��� "���ڿ�" �����ϴ� Ŭ������ �ʿ��ϴ�.
// �׷���, ���� ���� ������ �ִ� "TextView" �� ���⿡ ����Ҽ� ������ ?
// => �ȵȴ�. �������̽�(�Լ��̸�)�� �ٸ���.

// ���������� �䱸 ���� : Shape �� ���� �Ļ��Ǿ�� �ϰ�, draw() �Լ� �ʿ�
// TextView            : Shape �� ���� �Ļ����� �ʾҰ�, show() �Լ� ����

// TextView �� �������̽�(�Լ��̸�)�� �����ؼ� ���������⿡�� ����Ҽ� �ְ� �غ���

class Text : public TextView,   // TextView �� ���� ���ڿ� ����/��� ���
			 public Shape		// ���������� �ý��� �䱸����
{
public:
	Text(const std::string& s) : TextView(s) {}

	// �Ʒ� �ڵ尡 "show" ��� �������̽�(�Լ��̸�) �� "draw" �� �����ϴ� �ڵ��Դϴ�.
	void draw() override
	{
		TextView::show();
	}
};
// �ᱹ Text �� TextView �� ��� ����� ��밡���ѵ�.
// ���� �����⿡�� ��밡���ϵ��� "�������̽��� ����" �Ѱ� �Դϴ�.
// Adapter ���� : �������̽��� ����ġ�� �ذ��ϴ� ����.

int main()
{
	std::vector<Shape*> v;

	v.push_back(new Text("hello"));
	v[0]->draw();
}

// �� �������� "Text" ��
// "TextView" �� "����������" �ý��� ������ 
// �������̽��� ����ġ�� �ذ��ϱ� ���ؼ� ���� "Adapter" �Դϴ�.







