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
		buff = new T[sz]; // vector 설계시 이렇게 코드를 작성했다면
						  // 사용자가 메모리 할당 정책을 변경할수 없습니다.
	}
	~vector()
	{
		delete[] buff;
	}
};
int main()
{
	vector<int> v(10); // v는 내부적으로 int 10개 할당
}
