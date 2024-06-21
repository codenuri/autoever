// 2_Builder
#include <iostream>
#include <string>

// �౸���� ĳ���͸� ������ ���ô�.
// ����, ������, �Źߵ��� �����Ҽ� �ֽ��ϴ�.
typedef std::string Hat;			// class Hat{}
typedef std::string Uniform;	    // class Uniform{}
typedef std::string Shoes;			// class Shoes{}
typedef std::string Character;		// class Character{}��� ����


// ���� ���ÿ� ���� "����", "������", "�Ź�"�� ����Ǿ�� �մϴ�.
struct IBuilder
{
	virtual Hat     makeHat() = 0;
	virtual Uniform makeUniform() = 0;
	virtual Shoes   makeShoes() = 0;

	virtual ~IBuilder() {}
};

class Director
{
	IBuilder* builder = nullptr;
public:
	void set_builder(IBuilder* b) { builder = b; }

	Character construct()
	{
		// ĳ���͸� ����� ������ ���� �մϴ�.
		// => ������, �� ������ ������� "builder" �� ���� �޶����� �ֽ��ϴ�.
		// 
		Character c;
		c = c + builder->makeHat();
		c = c + builder->makeUniform();
		c = c + builder->makeShoes();
		return c;
	}
};
// ���� �������� "����", "������", "�Ź�"�� ����� ������ �����ϸ� �˴ϴ�.
class Korean : public IBuilder
{
public:
	Hat     makeHat()     override { return "�� "; }
	Uniform makeUniform() override { return "�Ѻ� "; }
	Shoes   makeShoes()   override { return "¤�� "; }
};

class American : public IBuilder
{
public:
	Hat     makeHat()     override { return "�߱����� "; }
	Uniform makeUniform() override { return "�纹 "; }
	Shoes   makeShoes()   override { return "���� "; }
};

int main()
{
	American a;
	Korean k;
	Director d;
	
//	d.set_builder(&k); // <==  ������ �����Ҷ� ���� ������ �����ϸ� �˴ϴ�.
	d.set_builder(&a);

	Character c = d.construct();
	std::cout << c << std::endl;
}

// ������ ���Ͽ��� "�������̽���� ��ü" �� ����ϴ�
// �Ʒ� 3���� ������ "Ŭ���� ���̾�׷��� ����" �մϴ�.
// �׷���, �ǵ��� ���� ������ �̸��� �ٸ��ϴ�.

// strategy : ��ü�� ����ϴ� "�˰���"�� ��ü

// state    : ��ü�� ���λ��¿� ���� "���(��κ�) ���� ��ü" 

// builder  : ������ ������ ��ü�� ����µ�..
//		      ������ �����ѵ�, �� ������ ǥ���� �ٸ� ��ü!