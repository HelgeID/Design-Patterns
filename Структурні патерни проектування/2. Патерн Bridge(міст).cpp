//Патерн Bridge(міст)
//Розділяє один або кілька класів на дві окремі ієрархії — абстракцію та реалізацію, 
//дозволяючи змінювати код в одній гілці класів, незалежно від іншої.

#include <iostream>
//---------------------------------------
class Color
{
public:
	virtual void info() = 0;
};

class Shape
{
public:
	Color* pColor{ nullptr };
	virtual void info() = 0;
};

//---------------------------------------
class Blue : public Color {
public:
	void info() { std::cerr << "Blue" << std::endl; }
};

class Red : public Color {
public:
	void info() { std::cerr << "Red" << std::endl; }
};

//---------------------------------------
class Circle : public Shape {
public:
	Circle(Color* pColor) { this->pColor = pColor; }
	~Circle() { delete pColor; }

	void info() {
		std::cerr << "Circle - ";
		this->pColor->info();
	}
};

class Square : public Shape {
public:
	Square(Color* pColor) { this->pColor = pColor; }
	~Square() { delete pColor; }

	void info() {
		std::cerr << "Square - ";
		this->pColor->info();
	}
};

int main()
{
	Circle objCircle(new Blue);
	objCircle.info();

	Square objSquare(new Red);
	objSquare.info();

	system("pause");
}
