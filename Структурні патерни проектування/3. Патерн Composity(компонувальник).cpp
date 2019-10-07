//Патерн Composity(компонувальник)
//Дає змогу згрупувати декілька об'єктів у деревоподібну структуру, 
//а потім працювати з нею так, ніби це одиничний об'єкт.
#include <iostream>
#include <algorithm>
#include <list>

//Component
class Shape {
public:
	virtual void Info() = 0;
};

//Leafs
class Square : public Shape {
public:
	void Info() override { std::cerr << "Square" << std::endl; }
};

class Circle : public Shape {
public:
	void Info() override { std::cerr << "Circle" << std::endl; }
};

class Triangle : public Shape {
public:
	void Info() override { std::cerr << "Triangle" << std::endl; }
};

//Composite
class Pack : public Shape
{
private:
	std::list<Shape*> component;

public:
	void Add(Shape* shape) { component.push_back(shape); }
	void Remove(Shape* shape) { component.remove(shape); }
	Shape* GetChild(const int index)
	{
		std::list<Shape*>::iterator it = component.begin();
		std::advance(it, index);
		return *it;
	}

	void Info() override {
		std::list<Shape*>::iterator it = component.begin();
		while (it != component.end()) {
			(*it)->Info();
			it++;
		}
	}
};

int main()
{
	//group a
	Shape* figure_A1 = new Square();
	Shape* figure_A2 = new Circle();
	Shape* figure_A3 = new Circle();

	//group b
	Shape* figure_B1 = new Triangle();
	Shape* figure_B2 = new Circle();

	//packages
	Pack* package_A = new Pack(); //формуємо пакет A, де положимо Square, Circle, Circle
	Pack* package_B = new Pack(); //формуємо пакет B, де положимо Triangle, Circle
	Pack* package_ALL = new Pack(); //формуємо загальний пакет, де положимо пакет A та B
	package_A->Add(figure_A1); package_A->Add(figure_A2); package_A->Add(figure_A3);
	package_B->Add(figure_B1); package_B->Add(figure_B2);
	package_ALL->Add(package_A); package_ALL->Add(package_B);

	//package_B->Remove(figure_B1); //видаляємо фігуру B1 (Triangle) з пакета B
	//package_ALL->Info(); //що знаходиться в заг. пакеті

	//package_ALL->GetChild(0)->Info(); //що знаходиться в заг. пакеті під інд 0

	package_ALL->Remove(package_A); //видаляємо пакет A з заг. пакета
	package_ALL->Info(); //що знаходиться в заг. пакеті

	system("pause");
}
