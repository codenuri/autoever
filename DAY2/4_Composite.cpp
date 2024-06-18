#include <iostream>
#include <vector>
#include <string>

// File 과 Folder 의 공통의 기반 클래스
class Component
{
	std::string name;
public:
	Component(const std::string& name) : name(name) {}

	virtual ~Component() {}

	// File   : 자신만의 크기 있음.
	// Folder : 자신만의 크기 없음. 하지만 크기를 구할수는 있음.
	virtual int getSize() = 0;
};

// File 은 "개별객체(Leaf)"
class File  : public Component
{
	int size;
public:
	File(const std::string& name, int size) : Component(name), size(size) {}
};



class Folder 
{
public:
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

	// 파일은 자신만의 크기는 있습니다.
	// 폴더는 자신만의 크기는 없지만 크기를 구할수 있습니다.
	std::cout << f2->getSize() << std::endl; // 20
	std::cout << fo1->getSize() << std::endl; // 10
	std::cout << root->getSize() << std::endl; // 30
}

