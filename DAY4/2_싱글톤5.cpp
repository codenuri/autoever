#include <iostream>
#include <mutex>

// CRTP ( Curiously Recuring Template Pattern )
// => "신기하게도 언급되는 템플릿 패턴" 이라는 의미 !!

// => 기반 클래스 만들때 미래에 만들어질 파생 클래스의 이름을 사용할수 있게하는 기술
// 
// => 기반 클래스를 템플릿 으로 만들고, 파생 클래스 제작자가 템플릿 인자로 
//    자신의 이름을 전달하게 하는 기술

// 예전에는 "간단한 테크닉 취급", 하지만 지금은 핵심 기술로 발전!!
// C++20 의 range 라이브러리가 이 기술로 설계됨..


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


// Mouse 클래스도 "위와 같은 힙에 만드는 싱글톤" 으로 하고 싶다!!
class Mouse : public Singleton< Mouse >
{

};


int main()
{
	Mouse& c1 = Mouse::get_instance();

}




