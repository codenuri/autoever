// vector �� �����ڿ��� �޸� �Ҵ�, �Ҹ��ڿ��� �޸� �������ؾ� �մϴ�.
// 
// �׷���, C++������ �޸𸮸� �Ҵ��ϴ� ����� ���� ���� �ֽ��ϴ�.
// new / malloc / system call / windows api/ Ǯ�� 

template<typename T>
class vector
{
	T* buff;
public:
	vector(int sz)
	{
		buff = new T[sz]; // vector ����� �̷��� �ڵ带 �ۼ��ߴٸ�
						  // ����ڰ� �޸� �Ҵ� ��å�� �����Ҽ� �����ϴ�.
	}
	~vector()
	{
		delete[] buff;
	}
};
int main()
{
	vector<int> v(10); // v�� ���������� int 10�� �Ҵ�
}
