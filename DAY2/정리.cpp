/// ����.cpp

// ��ü���� ������ ������ �ٽ� #1. ���뼺�� �������� �и�
// => �������� ���Ǵ� �ڵ�(������ �ʴ°�) �� ����ڰ� �����Ҽ� �ְ��ϴ� �ڵ带 �и�

// 1. ���ϴ� ���� �����Լ���    : template method
// 2. ���ϴ� ���� �ٸ� Ŭ������ : strategy, policy base design ( C++ IDioms)

// ���ϴ� ��(��å Ŭ����) �� ��ü �ϴ� 2���� ���

//					interface ��� ��ü			template ���ڷ� ��ü
// ����				Edit/IValidator				vector/debug_alloc
// 
// ����				�����Լ��̹Ƿ� ������.		�����Լ��� �ƴ� inline. ������.
// 
// ����ð� ��ü		����.						�ȵ�.
//					e.set_validator(��å1)		vector<int, debug_alloc<int>> v;
//					e.set_validator(��å2)		����ð��� v�� ��å�� ��ü �Ҽ� ����

// ��åŬ������		�������̽��� ��ӵǾ� �ִ�		����ȭ �Ǿ� �ִ�.
// �Լ��̸�			(�Լ��̸��� �ڵ�� ���)		cppreference.com �� "Named Requirement"
//												C++20 ���ʹ� �ڵ�ε� ���� "concept"