// Console.ReadLine()
// Console.Read()
// 
// 위 2개는 결국 입력 버퍼에서 가지고 오는 것
// => 입력 버퍼가 비었을때는 "사용자-> 입력 버퍼"에 담아야 하고
// => enter 를 해야 종료

// 입력 버퍼가 아닌 사용자로부터 직접 입력
// => enter 필요 없음.
// => 아무 키나 누르면 즉시 반환
//ConsoleKeyInfo key = Console.ReadKey(); // 입력 자체도 화면에 echo
ConsoleKeyInfo key = Console.ReadKey(true); //입력 자체는 echo 안함

Console.WriteLine("입력된 키보드 {0}", key.KeyChar);


