//Патерн Factory Method (фабричний метод)
//Визначає загальний інтерфейс для створення об'єктів у суперкласі, дозволяючи підкласам змінювати тип створюваних об'єктів.
#include <iostream>
#include <vector>

////////////////////////////////////////
class Product {
public:
	virtual void Info() = 0;
};

class Chocolate : public Product {
public:
	void Info() { std::cerr << "Chocolate" << std::endl; }
};

class Cake : public Product {
public:
	void Info() { std::cerr << "Cake" << std::endl; }
};

class Pie : public Product {
public:
	void Info() { std::cerr << "Pie" << std::endl; }
};

////////////////////////////////////////
class Factory {
public:
	virtual Product* createProduct() = 0;
};

class ChocolateFactory : public Factory {
public:
	Product* createProduct() { return new Chocolate; }
};

class CakeFactory : public Factory {
public:
	Product* createProduct() { return new Cake; }
};

class PieFactory : public Factory {
public:
	Product* createProduct() { return new Pie; }
};

int main()
{
	ChocolateFactory* chocolate = new ChocolateFactory;
	CakeFactory* cake = new CakeFactory;
	PieFactory* pie = new PieFactory;

	std::vector<Product*> vec;
	vec.push_back(chocolate->createProduct());
	vec.push_back(cake->createProduct());
	vec.push_back(pie->createProduct());

	for (int i = 0; i<vec.size(); i++)
		vec[i]->Info();

	// ...

	system("pause");
	return 0;
}
