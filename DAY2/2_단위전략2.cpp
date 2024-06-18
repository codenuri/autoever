// vector �� �޸� �Ҵ�/���� ��å�� ����ڰ� �����Ҽ� �ְ� ����� ���ô�.

// ��� #1. template method ���� ���
// => ���ϴ� ���� "�����Լ�"�� 
// => �޸� �Ҵ�/���� ����� "�����Լ���"

template<typename T>
class vector
{
	T* buff;
	int size;
public:
	// �޸� �Ҵ�/���� �� ���� �����Լ�
	virtual T* allocate(int sz)           { return new T[sz]; }
	virtual void deallocate(T* p, int sz) { delete[] p; }

	// ���� vector �� ��� ��� �Լ������� �޸� �Ҵ�/������ �ʿ��ϸ�
	// allocate/deallocate �� ����ؾ� �մϴ�.
	vector(int sz)
	{
		buff = allocate(sz); 
	}
	~vector()
	{
		deallocate(buff, size)
	}
};

// �� �������� �ǵ��� 
// �޸� �Ҵ�/������ ����� �����Ϸ��� vector �� �Ļ� Ŭ������ ������ ��!!!

template<typename T> class myvector : public vector<T>
{
public:
	T* allocate(int sz) override 
	{
		void* p = malloc(sizeof(T) * sz);
		return static_cast<T*>(p);
	}
	void deallocate(T* p, int sz) override
	{
		free(p);
	}
};

int main()
{
//	vector<int> v(10); // v�� ���������� int 10�� �Ҵ�
	myvector<int> v(10); // �޸� �Ҵ� ����� ����(new �� �ƴ� malloc)��
						 // vector 
}

// vector ��������, �� ���(template method)�� �����Ҷ��� ���� 
// => myvector �� �޸� �Ҵ� ����� �����ϰ� �ȴ�.
// => list, set, map �� �޸� �Ҵ� ����� �����Ϸ���
//    �Ļ� Ŭ������ ���� ������ �ڵ带 �ۼ��ؾ� �Ѵ�.

// "�޸� �Ҵ� ����� ���� ��å" �� ��� �����̳ʰ� ����Ҽ� �ְ� �ϴ� ���� 
// ���� ������ ??