
// Console.ReadLine()
// Console.Read()
// 
// 위 2개는 결국 입력 버퍼에서 가지고 오는 것
// => 입력 버퍼가 비었을때는 "사용자-> 입력 버퍼"에 담아야 하고
// => enter 를 해야 종료

ConsoleKeyInfo key = Console.ReadKey();

Console.WriteLine("입력된 키보드 {0}", key.KeyChar);


