// 데코레이터 패턴과  (객체)어답터 패턴의 코드는 매우 유사해 보입니다.
// 아래 2개의 클래스 코드를 비교해 보세요

// Decorator
class ZipDecorator : public Stream
{
	Stream* stream;
public:
	ZipDecorator(Stream* s) : stream(s) {}

	void write(const std::string& data) override
	{
		auto s2 = "[ " + data + " ] 압축됨";
		stream->write(s2);
	}
};

// Object Adapter
class ObjectAdapter : public Shape
{
	TextView* tview; 
public:
	ObjectAdapter(TextView* tv) : tview(tv) {}

	void draw() override { tview->show(); }
};