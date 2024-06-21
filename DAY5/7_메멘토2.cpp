// 8_메멘토 - 178
#include <iostream>
#include <vector>
#include <map>

class Graphics
{
	int penWidth = 1;
	int penColor = 0;
	int temporary_data;

	// 멤버 데이타중 저장되어야 하는 것만 별도의 타입으로 설계
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

	// 이전 예제에서  "방법#2"를 사용하는 코드입니다.

	g.SetStrokeColor(0);
	g.SetStrokeWidth(10);
	g.DrawLine(0, 0, 100, 100);
	g.DrawLine(0, 0, 200, 200); 

	int token = g.Save(); // Memento 패턴
			 			 // => 객체가 자신의 상태를 스스로 저장하게 한다.
			 			 // => 필요할때 다시 복구 가능하게 한다.
					     // => 캡슐화를 위배하지 않고 객체의 저장/복구 기능
						 //    (객체의 멤버를 외부에서 접근할 필요 없다는것)


	g.SetStrokeColor(1);
	g.SetStrokeWidth(20);
	g.DrawLine(0, 0, 300, 300);
	g.DrawLine(0, 0, 400, 400);

	// 처음에 그렸던 선과 동일하게 그리고 싶다.
	g.Restore(token);


}









