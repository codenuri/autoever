#include <iostream>
#include <mutex>

// CRTP ( Curiously Recuring Template Pattern )
// => "�ű��ϰԵ� ��޵Ǵ� ���ø� ����" �̶�� �ǹ� !!

// => ��� Ŭ���� ���鶧 �̷��� ������� �Ļ� Ŭ������ �̸��� ����Ҽ� �ְ��ϴ� ���
// 
// => ��� Ŭ������ ���ø� ���� �����, �Ļ� Ŭ���� �����ڰ� ���ø� ���ڷ� 
//    �ڽ��� �̸��� �����ϰ� �ϴ� ���

// �������� "������ ��ũ�� ���", ������ ������ �ٽ� ����� ����!!
// C++20 �� range ���̺귯���� �� ����� �����..


template<typename T>
class Singleton
{
protected:
	Singleton() {}

	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;

	static T* sinstance;    // <===== !!!
	static std::mutex mtx;
public:
	static T& get_instance()// <===== !!!
	{
		std::lock_guard<std::mutex> g(mtx); 

		if (sinstance == nullptr)
			sinstance = new T;   // <===== !!!

		return *sinstance;
	}
};
template<typename T> T* Singleton<T>::sinstance = nullptr;
template<typename T> std::mutex Singleton<T>::mtx;


// Mouse Ŭ������ "���� ���� ���� ����� �̱���" ���� �ϰ� �ʹ�!!
class Mouse : public Singleton< Mouse >
{

};


int main()
{
	Mouse& c1 = Mouse::get_instance();

}




