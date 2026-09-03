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
    public void UseCamera(Camera c) {  c.Take(); }
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

