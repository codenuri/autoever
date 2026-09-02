// inheritance (상속 )
// => 기존의 타입을 확장해서 새로운 타입을 만드는 문법

// 용어
// Person : Base(기반) class,    Parent class, Super class
// Student: Derived(파생) class, Child class,  Sub class

// 대부분의 언어에서 지원
// C#     : class Student : Person
// C++    : class Student : public Person
// Python : class Student ( Person )
// Java   : class Student extends Person 

// 장점
// 1. 코드 중복이 줄어들고
// 2. 공통의 특징을 한곳에서 관리
// 3. 다양한 객체 지향 디자인 기술의 활용 - 앞으로 배우는 내용


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
