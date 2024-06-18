// Edit 예제 정리 - 교재 33 ~ 

// Edit2.cpp
// => 변하는 것(validation 정책) 을 가상함수로 분리
// => 상속을 사용하는 패턴!!
// => template method 패턴.
// 특징 : Validation 정책을 NumEdit 가 소유하게 된다.

// 1. 다른 입력컨트롤에서 Validation 정책 사용하기 어렵다.
//    정책을 NumEdit 가 소유(멤버 함수)하므로
// 
// 2. Edit 가 실행시간에 Validation 정책을 교체 할수 없다.

// 3. Valiation 정책 NumEdit 의 멤버 함수 이므로
//    Edit 의 멤버에 접근하기 쉽다.





// Edit3.cpp
// => 변하는 것(validation 정책) 을 다른 클래스로 분리
// => Strategy(전략) 패턴
// 특징 : Validation 정책이 다른 클래스로 분리되어 있다
// 
// 1. 다른 입력컨트롤에서도 다양한 Validation 정책 사용가능
//    Validation 정책에 Edit 와는 별개의 클래스로 되어 있으므로!!
// 
// 2. Edit 가 실행시간에 Validation 정책을 교체 할수 있다.

// 3. Valiation 정책이 다른 클래스로 분리되어 있으므로 
//    Edit 의 멤버 데이타 접근이 어렵다.!!