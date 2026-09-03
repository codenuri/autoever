// generic constraint 의 다양한 표기법 예제

class List<T> where T : struct    // T 는 value type 이어야 한다.
{	
}

class Program 
{
	public static void Main()
	{
		List<int>    c1 = new List<int>();		// ok
		List<string> c2 = new List<string>();	// error

		Nullable<int> n = null;  // ok
        Nullable<string> s = null;  // error. 
    }	
}



/*
class C1<T> where T : struct           {} // value type 만 가능
class C2<T> where T : class            {} // reference  만 가능
class C3<T> where T : class?           {} // null 가능한 타입만
class C4<T> where T : notnull          {} // null 불가능 타입만
class C5<T> where T : unmanaged        {} // managed 타입이 아닌 것

class C6<T> where T : new()        // 디폴트 생성자(인자없는 생성자)
{
	public void Foo()
	{
		T a = new T(); // 제약이 없으면 안됨
	}

}


// class C7<T> where T : base_class_name  {}
// class C8<T> where T : base_class_name? {}
// class C9<T> where T : interface_name   {}
// class C10<T> where T : interface_name?  {}


class C11<T> where T : class, IComparable<T>
{ 
}

class C12<T, U> where T : struct  
			    where U : class
{ 
}
*/