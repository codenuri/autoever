#define USING_GUI
#include "cppmaster.h"

#include "ICalc.h"

// ��������� �ڵ������ϱ� ���� ����Ʈ ������
// "�ȵ���̵� OS" ���� "sp" ��� ����Ʈ �����Ͱ� �Ʒ��� �����մϴ�

template<typename T> class sp
{
	T* obj;
public:
	sp(T* p = nullptr) : obj(p) { if (obj != nullptr) obj->AddRef(); }
	sp(const sp& other) : obj(other.obj) { if (obj != nullptr) obj->AddRef(); }
	~sp() { if (obj != nullptr) obj->Release(); }

	// ����Ʈ ������ �ٽ� : ��¥ �����ʹ� �ƴ����� ������ ó�� -> �� * �� ����Ҽ� �־�� �Ѵ�.

	T* operator->() { return obj; }
	T& operator*() { return *obj; }
};

int main()
{
	sp<ICalc> calc1 = load_proxy(); // sp<ICalc> calc1( load_proxy() )
	sp<ICalc> calc2 = calc1;

	// calc1 �� �����Ͱ� �ƴ����� ������ ��Ȱ�̹Ƿ� �Ʒ�ó�� ����Ҽ� �־�� �մϴ�.
	int n1 = calc1->Add(1, 2);
	int n2 = calc1->Sub(1, 2);
}

/*
int main()
{	
	ICalc* calc1 = load_proxy();
	calc1->AddRef();		

	ICalc* calc2 = calc1;
	calc2->AddRef();		


	calc2->Release();		
	calc1->Release();		
}

*/



