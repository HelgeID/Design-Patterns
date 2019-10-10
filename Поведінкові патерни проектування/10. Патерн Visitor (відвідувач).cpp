//Патерн Visitor (відвідувач)
//Дає змогу додавати до програми нові операції, не змінюючи класи об'єктів.
#include <iostream>

class BodyElement;
class EngineElement;

class Visitor {
public:
	virtual void visit(BodyElement* ) = 0;
	virtual void visit(EngineElement* ) = 0;
};

class Element {
public:
	virtual void accept(Visitor*) = 0;
};

//кузов
class BodyElement : public Element {
public:
	//кузов може приймати відвідувача
	void accept(Visitor* visitor) override { visitor->visit(this); }
};

//двигун
class EngineElement : public Element {
public:
	//двигун може приймати відвідувача
	void accept(Visitor* visitor) override { visitor->visit(this); }
};

class UserVisitor : public Visitor {
public:
	void visit(BodyElement* element) override { std::cerr << "Washed the body!" << std::endl; }
	void visit(EngineElement* element) override { std::cerr << "Start the engine!" << std::endl; }
};

class MechanicVisitor : public Visitor {
public:
	void visit(BodyElement* element) override { std::cerr << "Polished the body!" << std::endl; }
	void visit(EngineElement* element) override { std::cerr << "Cleaned the engine!" << std::endl; }
};

int main()
{
	Element *body = new BodyElement();
	Element *engine = new EngineElement();
	Visitor *userVis = new UserVisitor();
	Visitor *mechanicVis = new MechanicVisitor();

	body->accept(userVis);
	engine->accept(userVis);

	body->accept(mechanicVis);
	engine->accept(mechanicVis);

	delete body;
	delete engine;
	delete userVis;
	delete mechanicVis;

	system("pause");
}
