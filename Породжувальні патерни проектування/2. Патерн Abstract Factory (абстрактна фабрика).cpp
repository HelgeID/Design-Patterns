//Патерн Abstract Factory (абстрактна фабрика)
//Визначає загальний інтерфейс для створення об'єктів у суперкласі, 
//дозволяючи підкласам змінювати тип створюваних об'єктів.
#include <iostream>
#include <vector>

void Print(const char* name) {
	std::cerr << name << std::endl;
}

// Абстрактні базові класи
class Walking { //клас ходячі
public:
	virtual void info() = 0;
};

class Floating { //клас плаваючі
public:
	virtual void info() = 0;
};

class Flying { //клас літаючі
public:
	virtual void info() = 0;
};

class EuropeWalking : public Walking {
public: void info() { Print("Horse");  Print("Dog"); }
};
class EuropeFloating : public Floating {
public: void info() { Print("Fish");  Print("Frog"); }
};
class EuropeFlying : public Flying {
public: void info() { Print("Crow");  Print("Sparrow"); }
};

class AfricaWalking : public Walking {
public: void info() { Print("Elephant");  Print("Lion"); }
};
class AfricaFloating : public Floating {
public: void info() { Print("Crocodile");  Print("Hippo"); }
};
class AfricaFlying : public Flying {
public: void info() { Print("Ostrich");  Print("Flamingo"); }
};

class AustraliaWalking : public Walking {
public: void info() { Print("Kangaroo");  Print("Koala"); }
};
class AustraliaFloating : public Floating {
public: void info() { Print("Turtle");  Print("Shark"); }
};
class AustraliaFlying : public Flying {
public: void info() { Print("Parrot");  Print("Eagle"); }
};

////////////////////////////////////////////
class AnimalFactory {
public:
	virtual Walking* createWalking() = 0;
	virtual Floating* createFloating() = 0;
	virtual Flying* createFlying() = 0;
};

//фабрика створення тварин в Європі
class EuropeAnimalFactory : public AnimalFactory {
public:
	Walking* createWalking() { return new EuropeWalking; }
	Floating* createFloating() { return new EuropeFloating; }
	Flying* createFlying() { return new EuropeFlying; }
};
//фабрика створення тварин в Африці
class AfricaAnimalFactory : public AnimalFactory {
public:
	Walking* createWalking() { return new AfricaWalking; }
	Floating* createFloating() { return new AfricaFloating; }
	Flying* createFlying() { return new AfricaFlying; }
};
//фабрика створення тварин в Австралії
class AustraliaAnimalFactory : public AnimalFactory {
public:
	Walking* createWalking() { return new AustraliaWalking; }
	Floating* createFloating() { return new AustraliaFloating; }
	Flying* createFlying() { return new AustraliaFlying; }
};

//клас, що вміщує всіх тварин того чи іншого континенту
class Animal
{
public:
	Walking* pWalking;
	Floating* pFloating;
	Flying* pFlying;

	void info() {
		pWalking->info();
		pFloating->info();
		pFlying->info();
	}

	~Animal() {
		delete pWalking;
		delete pFloating;
		delete pFlying;
	}
};

Animal* createAnimal(AnimalFactory& factory) {
	Animal* animal = new Animal;
	animal->pWalking = factory.createWalking();
	animal->pFloating = factory.createFloating();
	animal->pFlying = factory.createFlying();
	return animal;
}

int main()
{
	EuropeAnimalFactory europeFact;
	AfricaAnimalFactory africaFact;
	AustraliaAnimalFactory australiaFact;

	//create
	Animal *europeAnimal(createAnimal(europeFact));
	Animal *africaAnimal(createAnimal(africaFact));
	Animal *australiaAnimal(createAnimal(australiaFact));

	europeAnimal->info();
	africaAnimal->info();
	australiaAnimal->info();

	//del
	delete europeAnimal;
	delete africaAnimal;
	delete australiaAnimal;

	std::cerr << std::endl;
	system("pause");
}
