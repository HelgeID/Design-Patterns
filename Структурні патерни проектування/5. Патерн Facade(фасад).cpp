//Патерн Facade(фасад)
//Надає простий інтерфейс до складної системи класів, бібліотеки або фреймворку.
#include <iostream>

class Fruit
{
public:
	virtual void Info() = 0;
};

class Apples : public Fruit { public: void Info() override { std::cerr << "Apples" << std::endl; } };
class Pears : public Fruit { public: void Info() override { std::cerr << "Pears" << std::endl; } };
class Plums : public Fruit { public: void Info() override { std::cerr << "Plums" << std::endl; } };

class Container {
public:
	void Info(Fruit* fruit) {
		std::cerr << "Container for ";
		fruit->Info();
	}
};

class Fasade {
	Container *container1, *container2;
	Fruit* apples; Fruit* pears; Fruit* plums;

public:
	Fasade()
		: container1(new Container), container2(new Container),
		apples(new Apples), pears(new Pears), plums(new Plums)
	{}

	~Fasade()
	{
		delete container1; delete container2;
		delete apples; delete pears; delete plums;
	}

	void PackagingApplesAndPears() {
		container1->Info(apples);
		container2->Info(pears);
	}

	void PackagingApplesAndPlums() {
		container1->Info(apples);
		container2->Info(plums);
	}

	void PackagingPearsAndPlums() {
		container1->Info(pears);
		container2->Info(plums);
	}
};

int main()
{
	Fasade fasade;
	//fasade.PackagingApplesAndPears();
	//fasade.PackagingApplesAndPlums();
	//fasade.PackagingPearsAndPlums();

	system("pause");
}
