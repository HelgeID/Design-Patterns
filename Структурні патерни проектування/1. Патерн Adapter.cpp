//Патерн Adapter
//Дає змогу об’єктам із несумісними інтерфейсами працювати разом.
#include <iostream>

class Number { //interface
public:
	virtual void OutNumber(const int) = 0;
};

class Adaptee {
	int number;
public:
	Adaptee(int number)
		: number(number)
	{
	}

	void PrintNumber() { std::cerr << number << std::endl; }
	int& TakeNumber() { return number; }
};

////////////////////////////////////////////////////////////////
//реалізація адаптера через наслідування
class Adapter1 : public Adaptee, public Number {
public:
	Adapter1() : Adaptee(0) {}

	void OutNumber(const int number) override {
		TakeNumber() = number;
		PrintNumber();
	}
};

////////////////////////////////////////////////////////////////
//реалізація адаптера через композицію
class Adapter2 : public Number {
	Adaptee* adaptee{ nullptr };
public:
	Adapter2() : adaptee(new Adaptee(0)) {}
	~Adapter2() { delete adaptee; }

	void OutNumber(const int number) override {
		adaptee->TakeNumber() = number;
		adaptee->PrintNumber();
	}
};

int main()
{
	Number* number1 = new Adapter1();
	number1->OutNumber(100);
	Number* number2 = new Adapter2();
	number2->OutNumber(200);

	delete number1;
	delete number2;

	system("pause");
}
