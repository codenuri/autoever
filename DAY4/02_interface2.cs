using static System.Console;




// 카메라나 사람을 무조건 만들지 말고
// 모든 카메라가 지켜야 되는 규칙을 먼저 설계합니다.
// 인터페이스 : 규칙을 만드는 문법

// 규칙 : 모든 카메라는 아래 인터페이스를 구현해야 한다.
//        => 인터페이스 안에 있는 메소드를 만들라는 것

interface ICamera
{    
    void Take(); // public 등의 접근지정자 표기하지 않고,
                 // 메소드 구현도 없다. 메소드 형태(이름, 반환타입, 인자)만 표기
}

// 아직 진짜 카메라는 없지만 "규칙" 이 생겼습니다.
// 카메라 사용자는 규칙대로만 사용하면 됩니다
class Person
{
    // 핵심 : 인자로 구체적 제품의 이름이 아닌 인터페이스(규칙 이름)을 사용
    //        => 규칙을 구현한 모든 카메라 객체를 받을수 있다
    public void UseCamera(ICamera c) { c.Take(); }
}

// 실제 카메라 제작자는 규칙대로 만들어야 합니다.
// => 상속과 동일하게 ": 인터페이스이름" 으로 표기

class Camera : ICamera
{
    public void Take() { WriteLine("take picture"); }
}

class HDCamera : ICamera
{
    public void Take() { WriteLine("take HD picture"); }
}




class Program
{
    public static void Main()
    {
        Person p = new Person();
        Camera c = new Camera();

        p.UseCamera(c);

        HDCamera hc = new HDCamera();
        p.UseCamera(hc); 
    }
}


