// 8_�޸��� - 178
#include <iostream>
#include <vector>
#include <map>

class Graphics
{
	int penWidth = 1;
	int penColor = 0;
	int temporary_data;

	// ��� ����Ÿ�� ����Ǿ�� �ϴ� �͸� ������ Ÿ������ ����
	struct Memento
	{
		int penWidth;
		int penColor;
	};
	std::map<int, Memento*> memento_map;
public:
	int Save()
	{
		static int key = 0;
		++key;

		Memento* m = new Memento;
		m->penColor = penColor;
		m->penWidth = penWidth;

		memento_map[key] = m;

		return key;
	}
	void Restore(int key)
	{
		Memento* m = memento_map[key];

		penWidth = m->penWidth;
		penColor = m->penColor;
	}



	void DrawLine(int x1, int y1, int x2, int y2)
	{
	}
	void SetStrokeColor(int c) { penColor = c; }
	void SetStrokeWidth(int w) { penWidth = w; }
};



int main()
{
	Graphics g;

	// ���� ��������  "���#2"�� ����ϴ� �ڵ��Դϴ�.

	g.SetStrokeColor(0);
	g.SetStrokeWidth(10);
	g.DrawLine(0, 0, 100, 100);
	g.DrawLine(0, 0, 200, 200); 

	int token = g.Save(); // Memento ����
			 			 // => ��ü�� �ڽ��� ���¸� ������ �����ϰ� �Ѵ�.
			 			 // => �ʿ��Ҷ� �ٽ� ���� �����ϰ� �Ѵ�.
					     // => ĸ��ȭ�� �������� �ʰ� ��ü�� ����/���� ���
						 //    (��ü�� ����� �ܺο��� ������ �ʿ� ���ٴ°�)


	g.SetStrokeColor(1);
	g.SetStrokeWidth(20);
	g.DrawLine(0, 0, 300, 300);
	g.DrawLine(0, 0, 400, 400);

	// ó���� �׷ȴ� ���� �����ϰ� �׸��� �ʹ�.
	g.Restore(token);


}









