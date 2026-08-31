// 핵심 : switch expression

int dayofweek = 1;

// 0 => "sun", 1 => "mon" 으로 변경하는 코드

string s1 = "";

switch(dayofweek)
{
	case 0: s1 = "sun"; break;
	case 1: s1 = "mon"; break;
	case 2: s1 = "tue"; break;
	default : s1 = "unknown"; break;
}
// 위 코드는 "s1" 변수를 먼저 선언 하고, 
// case 에서 s1 에 값을 넣는  코드

// 아래 처럼도 가능합니다. - 위와 동일
string s2 = dayofweek switch
			{
				0=>"sun",
				1=>"mon",
				2=>"tue",
				_=>"unknown"
			};

// 파이썬 : 공백과 탭이 중요
// C/C++/C#/Java/Rust : 단어를 구별하기 위해서만 필요
//						자유로움