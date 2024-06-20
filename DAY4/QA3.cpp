#include <iostream>
#include <string>

class AutoRegister
{
public:
	AutoRegister(const std::string& name) 
	{ 
		std::cout << name << " ������\n"; 
	}
};

struct A
{
	inline static AutoRegister ar{"A"};
};
struct B
{
	inline static AutoRegister ar{ "B" };
};
