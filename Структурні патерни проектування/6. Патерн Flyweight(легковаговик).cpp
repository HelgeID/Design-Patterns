//Патерн Flyweight(легковаговик)
//Організовує роботу з розділяючими обєктами.
#include <iostream>
#include <map>
#include <vector>
#include <string>

class Shape {
public:
	virtual void Draw() = 0;
};

class Point : public Shape {
public:
	int x, y;
	Point(int x, int y) : x(x), y(y) {}
	void Draw() override { std::cerr << "Point, "; std::cerr << " x:" << x << " y:" << y << std::endl; }
};

class Circle : public Shape {
public:
	int radius;
	Circle(int radius) : radius(radius) {}
	void Draw() override { std::cerr << "Circle, "; std::cerr << " radius:" << radius << std::endl; }
};

class Square : public Shape {
public:
	int a;
	Square(int a) : a(a) {}
	void Draw() override { std::cerr << "Square, "; std::cerr << " side:" << a << std::endl; }
};

class ShapeFactory {
	std::map<std::string, Shape*> shapes;

public:
	Shape* getShape(std::string key)
	{
		Shape* shape(nullptr);
		const auto found = shapes.find(key);
		if (found == shapes.cend()) {
			if (key == "Point")
				shape = new Point(0, 0);
			else if (key == "Circle")
				shape = new Circle(5);
			else if (key == "Square")
				shape = new Square(10);

			shapes[key] = shape;
		}
		else
			shape = shapes.at(key);

		return shape;
	}

	ShapeFactory() {}

	~ShapeFactory() {
		for (auto v : shapes)
			delete v.second;
	}
};

int main()
{
	ShapeFactory shapeFactory;
	std::vector<Shape*> vec;
	vec.push_back(shapeFactory.getShape("Square"));
	vec.push_back(shapeFactory.getShape("Circle"));
	vec.push_back(shapeFactory.getShape("Circle"));
	vec.push_back(shapeFactory.getShape("Square"));
	vec.push_back(shapeFactory.getShape("Point"));

	for (Shape* figure : vec)
		figure->Draw();

	system("pause");
}
