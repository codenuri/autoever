// ���ڷ����� ���ϰ�  (��ü)����� ������ �ڵ�� �ſ� ������ ���Դϴ�.
// �Ʒ� 2���� Ŭ���� �ڵ带 ���� ������

// Decorator
class ZipDecorator : public Stream
{
	Stream* stream;
public:
	ZipDecorator(Stream* s) : stream(s) {}

	void write(const std::string& data) override
	{
		auto s2 = "[ " + data + " ] �����";
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

// ������ ������ ��� �н��ϴٰ� ����, ���ϵ��� ����� ���϶��� �ֽ��ϴ�.
// �̶��� �׻� �ش� ������ "�ǵ�" �� ������ ������

// Adapter ����  : ����� ����(����߰��ƴ�), �Լ� �̸��� ����(show->draw����)
// Decorator���� : ����� �߰�!            , �Լ� �̸��� ����

// Adapter   : �������̽��� ������ ����
// Decorator : ����� �߰��� ����
