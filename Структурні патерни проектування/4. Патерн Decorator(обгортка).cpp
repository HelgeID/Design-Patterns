//Патерн Decorator(обгортка)
//Дає можливість надавати нову функціональність,
//загортаючи у корисні "обгортки".
#include <iostream>
#include <string>

class Printer { //інтерфейс
public:
	virtual void Print() = 0;
};

class Text: public Printer {
	std::string str;
public:
	Text(std::string str) { this->str = str; }
	void Print() override {
		std::cerr << str << std::endl;
	}
};

class Decorator : public Printer {
	Printer *component;
public:
	Decorator(Printer* component) { this->component = component; }

	void Print() override {
		std::cerr << "---------------" << std::endl;
		component->Print();
		std::cerr << "---------------" << std::endl;
	}
};

int main()
{
	Printer* text = new Text("Hello");
	text->Print(); //Hello
	std::cerr << std::endl;

	Printer *decorator = new Decorator(new Text("Hello"));
	decorator->Print(); //--Hello--

	system("pause");
}
