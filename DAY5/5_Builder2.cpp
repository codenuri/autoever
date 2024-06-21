// 2_Builder
#include <iostream>
#include <string>

// 축구게임 캐릭터를 생각해 봅시다.
// 모자, 유니폼, 신발등을 변경할수 있습니다.
typedef std::string Hat;			// class Hat{}
typedef std::string Uniform;	    // class Uniform{}
typedef std::string Shoes;			// class Shoes{}
typedef std::string Character;		// class Character{}라고 가정


// 국가 선택에 따라 "모자", "유니폼", "신발"은 변경되어야 합니다.
struct IBuilder
{
	virtual Hat     makeHat() = 0;
	virtual Uniform makeUniform() = 0;
	virtual Shoes   makeShoes() = 0;

	virtual ~IBuilder() {}
};

class Director
{
	IBuilder* builder = nullptr;
public:
	void set_builder(IBuilder* b) { builder = b; }

	Character construct()
	{
		// 캐릭터를 만드는 공정은 동일 합니다.
		// => 하지만, 각 공정의 결과물은 "builder" 에 따라 달라질수 있습니다.
		// 
		Character c;
		c = c + builder->makeHat();
		c = c + builder->makeUniform();
		c = c + builder->makeShoes();
		return c;
	}
};
// 이제 국가별로 "모자", "유니폼", "신발"을 만드는 빌더를 제공하면 됩니다.
class Korean : public IBuilder
{
public:
	Hat     makeHat()     override { return "갓 "; }
	Uniform makeUniform() override { return "한복 "; }
	Shoes   makeShoes()   override { return "짚신 "; }
};

class American : public IBuilder
{
public:
	Hat     makeHat()     override { return "야구모자 "; }
	Uniform makeUniform() override { return "양복 "; }
	Shoes   makeShoes()   override { return "구두 "; }
};

int main()
{
	American a;
	Korean k;
	Director d;
	
	d.set_builder(&k); // <==  국가를 변경할때 마다 빌더를 변경하면 됩니다.

	Character c = d.construct();
	std::cout << c << std::endl;

}