// Edit ���� ���� - ���� 33 ~ 

// Edit2.cpp
// => ���ϴ� ��(validation ��å) �� �����Լ��� �и�
// => ����� ����ϴ� ����!!
// => template method ����.
// Ư¡ : Validation ��å�� NumEdit �� �����ϰ� �ȴ�.

// 1. �ٸ� �Է���Ʈ�ѿ��� Validation ��å ����ϱ� ��ƴ�.
//    ��å�� NumEdit �� ����(��� �Լ�)�ϹǷ�
// 
// 2. Edit �� ����ð��� Validation ��å�� ��ü �Ҽ� ����.

// 3. Valiation ��å NumEdit �� ��� �Լ� �̹Ƿ�
//    Edit �� ����� �����ϱ� ����.





// Edit3.cpp
// => ���ϴ� ��(validation ��å) �� �ٸ� Ŭ������ �и�
// => Strategy(����) ����
// Ư¡ : Validation ��å�� �ٸ� Ŭ������ �и��Ǿ� �ִ�
// 
// 1. �ٸ� �Է���Ʈ�ѿ����� �پ��� Validation ��å ��밡��
//    Validation ��å�� Edit �ʹ� ������ Ŭ������ �Ǿ� �����Ƿ�!!
// 
// 2. Edit �� ����ð��� Validation ��å�� ��ü �Ҽ� �ִ�.

// 3. Valiation ��å�� �ٸ� Ŭ������ �и��Ǿ� �����Ƿ� 
//    Edit �� ��� ����Ÿ ������ ��ƴ�.!!

// MFC ���̺귯���� CEdit : Edit2.cpp �� �����εǾ� �ֽ��ϴ�.
// QT  ���̺귯���� QEdit : Edit3.cpp �� �����εǾ� �ֽ��ϴ�. (QValidator �ֽ��ϴ�)

// ���������⸦ ������ ���ô�.
// => draw/draw_imp
class Shape
{
protected:
	virtual void draw_imp() = 0;
public:
	void draw()
	{
		std::cout << "mutex lock\n";
		draw_imp();
		std::cout << "mutex unlock\n";
	}
};

class Rect : public Shape
{
public:
	void draw_imp() { std::cout << "draw Rect\n"; }
};
// ������ �׸��� ��å��
// 1. ����ð��� ������ �ʿ䰡 ����..
// 2. �簢���� �׸��� ��å�� �ٸ� Ŭ������ ����� �ʿ䵵 ����
// 3. �׸��� �׸����� ��� ����Ÿ�� �����ؾ� �մϴ�.
// 
// �� ���� ������ ������ : strategy ���� template method �� �����ϴ�.
// Edit ������          : template method ���� strategy �� �����ϴ�.