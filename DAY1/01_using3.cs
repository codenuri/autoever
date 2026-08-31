// 01_using3.cs

System.Console.WriteLine("hello"); // ok. 관련이름을 모두 표기 코드

Console.WriteLine("hello"); // ?  using System 을 사용한적이없다

// visual stdio 2018 버전 부터 콘솔 프로젝트를 만들면 아래 코드가
// 자동생성됩니다.
// => DAY1/obj/debug/net10.0/DAY1.GlobalUsings.g.cs 소스 열어 보세요

// 그리고 빌드할때
// 사용자 소스와 DAY1.GlobalUsings.g.cs 가 같이 빌드 됩니다.
// => 그래서 사용자 코드에서는 using System 필요 없습니다
// => 단, "global using static" 없으므로 사용하고 싶으면 직접 표기