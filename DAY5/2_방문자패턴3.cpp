#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// list      : ���� ����, ��� ��Ұ� ���� Ÿ��
// 
// PopupMenu : Ʈ�� ����, �����ϴ� ��Ұ� �ٸ� Ÿ��.
//						 (PopupMenu, MenuItem)


// �湮�� : �湮�ϴ� ��� �Ѱ��� ���� ������ ����!!
//         �׷���, ����� Ÿ���� �ٸ��� �ִ�.
class PopupMenu;
class MenuItem;

struct IMenuVisitor
{
	virtual void visit(PopupMenu*) = 0;
	virtual void visit(MenuItem*) = 0;
	virtual ~IMenuVisitor() {}
};

// ��� �޴��� �湮�ڸ� �޾Ƶ鿩�� �մϴ�.
struct IAcceptor
{
	virtual void accept(IMenuVisitor* v) = 0;
	virtual ~IAcceptor() {}
};




class BaseMenu : public IAcceptor
{
	std::string title;
public:
	BaseMenu(const std::string& title) : title(title) {}
	virtual ~BaseMenu() {}

	std::string get_title() const { return title; }

	void set_title(const std::string& s) { title = s; }

	virtual void command() = 0;
};




class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(const std::string& title, int id) : BaseMenu(title), id(id) {}

	void command() override
	{
		std::cout << get_title() << " �޴��� ���õ�" << std::endl;
		_getch();
	}

	void accept(IMenuVisitor* visitor) override
	{
		// MenuItem �� ���� �޴��� �����Ƿ� �ڽŸ� �湮�ڿ� ������ �˴ϴ�.
		visitor->visit(this);
	}
};



class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v;
public:

	// PopupMenu �� �湮�ڰ� �����Ҷ��� �߻����� ������
	// => �� �ڵ尡 �ٽ� �Դϴ�.
	void accept(IMenuVisitor* visitor) override
	{
		// #1. �ڽ��� �湮�ڿ� ����
		visitor->visit(this);


		// #2. �ڽ��� ���� �޴��� �湮�ڿ� ���� �ϸ� �ȵǰ�!!
		//     �湮���� �ٽ� ���� �޴��� �湮���Ѿ�.
		for (auto e : v)
		{
		//	visitor->visit(e); // �̷��� �ϸ� �ȵǰ�
			e->accept(visitor);// �̷��� �ؾ� ��� �޴��� �湮�ڿ��� ����
								// �Ҽ� �ֽ��ϴ�.
		}
	}





	PopupMenu(const std::string& title) : BaseMenu(title) {}

	void add_menu(BaseMenu* p) { v.push_back(p); }

	void command() override
	{
		while (1)
		{
			system("cls");

			int sz = v.size();

			for (int i = 0; i < sz; i++)
			{
				std::cout << i + 1 << ". " << v[i]->get_title() << std::endl;
			}

			std::cout << sz + 1 << ". ����" << std::endl;

			int cmd;
			std::cout << "�޴��� �����ϼ��� >> ";
			std::cin >> cmd;

			if (cmd < 1 || cmd > sz + 1)
				continue;

			if (cmd == sz + 1)
				break;

			v[cmd - 1]->command(); 
		}

	}

};



// �Ʒ� �ڵ尡 "�˾��޴��� Ÿ��Ʋ�� �����ϴ� �湮��" �Դϴ�.
class PopupMenuTitleChangeVisitor : public IMenuVisitor
{
	std::string deco;
public:
	PopupMenuTitleChangeVisitor(const std::string& s) : deco(s) {}
	
	// �Ʒ� 2���� �Լ����� ���� "MenuItem", "PopupMenu" �� �湮������
	// �ؾ��� ������ ���� �Ͻø� �˴ϴ�.
	void visit(MenuItem* m) override
	{
		auto s = m->get_title();
		s = s + " *";
		m->set_title(s);
	}

	void visit(PopupMenu* pm) override 
	{
		auto s = pm->get_title();

		s = s + deco;

		pm->set_title(s);
	}
};






int main()
{
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1 = new PopupMenu("�ػ� ����");
	PopupMenu* pm2 = new PopupMenu("���� ����");

	root->add_menu(pm1);
	root->add_menu(pm2);


	pm1->add_menu(new MenuItem("HD", 11));
	pm1->add_menu(new MenuItem("FHD", 12));
	pm1->add_menu(new MenuItem("UHD", 13));

	pm2->add_menu(new MenuItem("RED", 21));
	pm2->add_menu(new MenuItem("GREEN", 22));
	pm2->add_menu(new MenuItem("BLUE", 23));

	// ��� �޴��� �ᱹ root �� �����մϴ�.
	// "root" �� ���հ�ü
	// ��� �޴��� �湮�ؼ�, "PopupMenu" �� ��츸 title �� �����ϴ�
	// �湮�ڸ� ����� ���ô�.
	PopupMenuTitleChangeVisitor pv(" =>");
	root->accept( &pv ); // pv �� ��� �޴��� �湮�ؼ� �־��� ���� ����



	root->command();

}




