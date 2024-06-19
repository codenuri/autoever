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

// 디자인 패턴을 계속 학습하다가 보면, 패턴들이 비슷해 보일때가 있습니다.
// 이때는 항상 해당 패턴의 "의도" 를 생각해 보세요

// Adapter 패턴  : 기능은 동일(기능추가아님), 함수 이름의 변경(show->draw변경)
// Decorator패턴 : 기능의 추가!            , 함수 이름은 동일

// Adapter   : 인터페이스의 변경이 목적
// Decorator : 기능의 추가가 목적
