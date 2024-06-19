
byte[] data = new byte[1024 * 1024]; // 1M 크기의 데이타

FileStream fs = new FileStream("a.dat", FileMode.Create);

fs.Write(data); // 데이타는 그냥 파일에 쓰기. 파일 크기가 1M 가 됩니다.

fs.Close();

