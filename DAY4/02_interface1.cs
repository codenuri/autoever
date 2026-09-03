using static System.Console;

class Camera
{
    public void Take() { WriteLine("take picture");  }
}

class HDCamera
{
    public void Take() { WriteLine("take HD picture"); }
}


class Person
{
    public void UseCamera(Camera c)   { c.Take(); }
    public void UseCamera(HDCamera c) { c.Take(); }
}

class Program
{
    public static void Main()
    {
        Person p = new Person();
        Camera c = new Camera();

        p.UseCamera(c);

        HDCamera hc = new HDCamera();
        p.UseCamera(hc); // ??
    }
}

// 위 코드는 에러 없이 잘 실행됩니다.

// 하지만, 위코드는 OCP 를 위반한 코드 입니다.
// 기능 확장에 열려있고(Open), 
// 코드 수정에는 닫혀있어야(Close)
// 한다는 원칙(Principle)

// 위 코드는 새로운 카메라가 나올때 마다 
// Person 이 수정되어야 합니다.
// 나쁜 디자인 입니다.

