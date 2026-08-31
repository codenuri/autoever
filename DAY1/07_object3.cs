
// 변수뿐 아니라 타입도 메소드가 있습니다.

// 인스턴스 메소드 : "변수.메소드이름()" 으로 호출
//                  변수가 보관 중인 값과 관련된 연산

// 정적(static) 메소드 : "타입.메소드이름()" 으로 호출
//                  타입 자체와 관련된 연산

int n1 = 10;

string s = n1.ToString();
int   n2 = int.Max(1, 2);

int    n = int.Parse("30");
double d = double.Parse("3.3");