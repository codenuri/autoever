#include <iostream>
#include <mutex>

// ���� �Ѱ��� ��ü�� "�� �� ����" �ϴ� ��!
// => ����ȭ �߰�
// => RAII ��� ���� - std::lock_guard !!


// RAII ����� �ٽ�
// => �ڿ��� �ݳ��� "�Լ��� ������ �κ�" ���� �ϴ� ���� �ƴ϶�!!
// => ������/�Ҹ��ڿ� �����ؼ� �����Ǿ�� �Ѵٴ� ��

template<typename T>
class lock_guard
{
	T& mtx;
public:
	inline lock_guard(T& m) : mtx(m) { mtx.lock(); }
	inline ~lock_guard()             { mtx.unlock(); }
};


class Cursor
{
private:
	Cursor() {}

	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;


	static Cursor* sinstance;
	static std::mutex mtx;
public:


	static Cursor& get_instance()
	{
		lock_guard<std::mutex> g(mtx);
//		mtx.lock();

		if (sinstance == nullptr)
			sinstance = new Cursor;

//		mtx.unlock();

		return *sinstance;
	}


};
Cursor* Cursor::sinstance = nullptr;
std::mutex Cursor::mtx;





int main()
{
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();

	std::cout << &c1 << std::endl;
	std::cout << &c2 << std::endl;

}




