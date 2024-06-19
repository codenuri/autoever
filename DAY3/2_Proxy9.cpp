#include <memory>

int main()
{
	// C++ ǥ�ؿ� �̹� "std::shared_ptr" �̶�� ����Ʈ �����Ͱ� �ִµ�..
	// �̰� ����ϸ� �ȵǳ��� ??
	// �ȵ˴ϴ�. �Ʒ� �ڵ� ������ ������

	std::shared_ptr<ICalc> sp1( load_proxy() ); 
				// 1. load_proxy �� DLL ���ο� �ִ� �Լ�(CreateProxy)���� new �� �ϰ� �˴ϴ�.
				// 2. �� �ּҸ� sp1 �� �����ϴٰ�
				// 3. sp1 �� �ı� �ɶ� "delete" �ϰ� �˴ϴ�.
				//    ��, delete �� �ϴ� ���� "��������" �Դϴ�!!

	sp<ICalc> sp2(load_proxy());
				// 1. sp2 �� �ı��ɶ� "delete" �� �ƴ϶� "Release()" �� ȣ���մϴ�.
				// 2. Release() ���� "delete" �ϴµ�
				// 3. Release() �� DLL �ȿ� �ִ� �Լ� �Դϴ�.
				//    ��, delete �� dLL �ȿ��� �ϰ� �˴ϴ�.

	// ���� ���� ������ C++ ǥ�ؿ� "std::shared_ptr" �̶�� ����Ʈ �����Ͱ� ������
	// �پ��� ������ ���� ���¼ҽ��� �ڽŸ��� ����Ʈ �����͸� ����ϰ� �ֽ��ϴ�.
}