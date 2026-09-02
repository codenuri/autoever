// inheritance (상속 )
// => 기존의 타입을 확장해서 새로운 타입을 만드는 문법

// 용어
// Person : Base class,    Parent class, Super class
// Student: Derived class, Child class,  Sub class


// 1. 모든 사람의 공통의 특징을 먼저 타입으로 설계
class Person
{
    private string name;
    private int age;
}

// 2. Person 타입을 확장해서 새로운 타입을 설계
class Professor : Person 
{
    private string major;
}

class Student : Person
{
    private string id;
}

class Program
{
    public static void Main()
    {
        Student s = new Student();

    }
}
