
using System.IO.Compression;

byte[] data = new byte[1024 * 1024]; // 1M 크기의 데이타

FileStream fs = new FileStream("a.dat", FileMode.Create);

//fs.Write(data); // 데이타는 그냥 파일에 쓰기. 파일 크기가 1M 가 됩니다.


GZipStream gs = new GZipStream(fs, CompressionLevel.Optimal);

gs.Write(data); // 1. 압축기능 수행후 
                // 2. fs.Write 로 쓰기


fs.Close();

// 실행후 "a.dat" 파일의 크기를 확인하세요
// bin/debug/net8.0/a.dat 있습니다.