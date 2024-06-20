#include <iostream>
#include <mutex>

// ���� �Ѱ��� ��ü�� "�� �� ����" �ϴ� ��!
// => ����ȭ �߰�
// => RAII ��� ���� - std::lock_guard !!


// RAII (C++ Idioms) ����� �ٽ�
// => �ڿ��� �ݳ��� "�Լ��� ������ �κ�" ���� �ϴ� ���� �ƴ϶�!!
// => ������/�Ҹ��ڿ� �����ؼ� �����Ǿ�� �Ѵٴ� ��
// 
// => "Resource Acquision Is Initialization"
//     �ڿ��� ȹ���ϰ� �Ǵ� ���� (�ڿ����� ��ü��) �ʱ�ȭ �ɶ��̴�.
//     �����ڿ��� �ڿ��� ȹ���ϰ� �ȴٴ� ���� �ǹ�!



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
		{
			std::lock_guard<std::mutex> g(mtx); // C++ ǥ�ؿ� �̹� std::lock_guard �ֽ��ϴ�.
//			lock_guard<std::mutex> g(mtx);	// 1. g�� �����ڿ��� "mtx.lock()" ����
			//		mtx.lock();				// 2. g�� �ı��ɶ� �Ҹ��ڿ��� "mtx.unlock()"
											// 3. �Լ� ������ ���ܵ��� �߻��ص�
											//    ��������(g) �� �ı��� �����ϰ� ����˴ϴ�.
											//    g�� �Ҹ��ڴ� ȣ��ȴٴ� �ǹ�
											//    => stack unwinding �̶�� �մϴ�.
			if (sinstance == nullptr)
				sinstance = new Cursor;

			//		mtx.unlock();
		} // <== g �ı�, ��, ���⼭ unlock

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




