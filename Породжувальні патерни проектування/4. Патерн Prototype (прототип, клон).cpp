//Патерн Prototype (прототип, клон)
//Дає змогу копіювати об'єкти, не вдаючись у подробиці їхньої реалізації.
#include <iostream>

class Human;

class Copyable
{
public:
	virtual Human* Copy() = 0;
};

class Human : public Copyable
{
	int age;
	char* name;

public:
	Human(int age, char* name)
		: age(age), name(name)
	{}

	Human* Copy() override {
		Human* copy = new Human(age, name);
		return copy;
	}

	void Info() {
		std::cerr << name << " " << age << std::endl;
	}
};

//ADD Factory
class HumanFactory
{
	Human* human;

public:
	HumanFactory(Human* human) {
		setPrototipe(human);
	}

	void setPrototipe(Human* human) {
		this->human = human;
	}

	Human* makeCopy() {
		return human->Copy();
	}
};

int main()
{
	//оригінал
	Human* original = new Human(18, "Ivan");
	original->Info();
	//копія
	Human* copy = original->Copy();
	copy->Info();

	//створюємо фабрику, передавши туди "copy"
	HumanFactory *factory = new HumanFactory(copy);
	Human* h1 = factory->makeCopy(); //робимо копію
	h1->Info(); //Ivan 18

	//перезаписуємо новий елемент у фабрику
	factory->setPrototipe(new Human(20, "Petr"));
	Human* h2 = factory->makeCopy(); //робимо копію
	h2->Info(); //Petr 20

	delete original;
	delete copy;

	delete factory;
	delete h1;
	delete h2;

	system("pause");
}
