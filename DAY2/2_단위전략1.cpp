// vector 는 생성자에서 메모리 할당, 소멸자에서 메모리 해지를해야 합니다.
// 
// 그런데, C++에서는 메모리를 할당하는 방법이 아주 많이 있습니다.
// new / malloc / system call / windows api/ 풀링 

template<typename T>
class vector
{
	T* buff;
public:
	vector(int sz)
	{
		buff = new int[sz];
	}
	~vector()
	{
		delete[] buff;
	}
};

