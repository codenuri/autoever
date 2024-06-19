#include <iostream>
#include <vector>
#include <string>

// File �� Folder �� ������ ��� Ŭ����
class Component
{
	std::string name;
public:
	Component(const std::string& name) : name(name) {}

	virtual ~Component() {}

	// File   : �ڽŸ��� ũ�� ����.
	// Folder : �ڽŸ��� ũ�� ����. ������ ũ�⸦ ���Ҽ��� ����.
	virtual int getSize() = 0;
};

// File �� "������ü(Leaf)"
class File  : public Component
{
	int size;
public:
	File(const std::string& name, int size) : Component(name), size(size) {}

	int getSize() override { return size; }
};


// Folder �� "���հ�ü(Composite)". 
class Folder : public Component
{
	std::vector<Component*> v; // �ٽ� 
public:
	Folder(const std::string& name) : Component(name) {}

	void addItem(Component* c) { v.push_back(c); }

	int getSize() override
	{
		int sz = 0;

		for (auto c : v)
			sz += c->getSize();

		return sz;
	}
};


int main()
{
	Folder* root = new Folder("ROOT");
	Folder* fo1  = new Folder("A");
	Folder* fo2  = new Folder("B");
	
	root->addItem(fo1);
	root->addItem(fo2);

	File* f1 = new File("a.txt", 10);
	File* f2 = new File("b.txt", 20);

	fo1->addItem(f1);
	root->addItem(f2);

	// ������ �ڽŸ��� ũ��� �ֽ��ϴ�.
	// ������ �ڽŸ��� ũ��� ������ ũ�⸦ ���Ҽ� �ֽ��ϴ�.
	std::cout << f2->getSize() << std::endl; // 20
	std::cout << fo1->getSize() << std::endl; // 10
	std::cout << root->getSize() << std::endl; // 30
}

// �� ������ �ᱹ "�޴� ����" �� ���� ���� ������ �Ǿ� �ֽ��ϴ�.
// => ��ó�� ���� ������ "�޴��� ������ ����" �� ����� ���� �ִµ�..
// => �� ������ "COMPOSITE ����" �̶�� �̸��� �ο� �߽��ϴ�.