//Патерн State (стан)
//Дає змогу об’єктам змінювати поведінку в залежності від їхнього стану.
#include <iostream>

//**************************************************************
//example 1
//**************************************************************
class Station {
public:
	virtual void play() = 0;
};

//state
class Radio1 : public Station {
public:
	void play() override { std::cerr << "radio 1" << std::endl; }
};

class Radio2 : public Station {
public:
	void play() override { std::cerr << "radio 2" << std::endl; }
};

class Radio3 : public Station {
public:
	void play() override { std::cerr << "radio 3" << std::endl; }
};

//context
class Radio { //може при різних станах міняти свою поведінку
	Station* station;
public:
	void setStation(Station* station) {
		this->station = station;
	}

	//перехід між станами відбувається в середині контексту
	void nextStation() {
		if (typeid(*station).name() == typeid(Radio1).name()) {
			delete station; setStation(new Radio2());
		}
		else if (typeid(*station).name() == typeid(Radio2).name()) {
			delete station; setStation(new Radio3());
		}
		else if (typeid(*station).name() == typeid(Radio3).name()) {
			delete station; setStation(new Radio1());
		}
	}

	//поведінка
	void play() { station->play(); }
};

int main()
{
	Radio radio;

	Station* r = new Radio1();
	radio.setStation(r);

	for (int i(0); i < 9; ++i) {
		radio.play();
		radio.nextStation();
	}
	delete r;

	system("pause");
}

//**************************************************************
//example 2
//**************************************************************
class Human;

class Activity {
public:
	virtual void doSomething(Human* human) = 0;
} *state; // на цей вказівник виділяємо та удаляємо пам'ять

//context
class Human {
	Activity* state;
public:
	void setState(Activity* state) {
		this->state = state;
	}
	void doSomething() {
		state->doSomething(this);
	}

	Activity* takeState() { return state; }
};

//state
class Work : public Activity {
public:
	void doSomething(Human* ) override;
};

class WeekEnd : public Activity {
	int count{ 0 };
public:
	void doSomething(Human* ) override;
};

//перехід між станами відбувається в самих станах

void Work::doSomething(Human* context)  {
	std::cerr << "Work!!!" << std::endl;

	delete state;
	context->setState(state = new WeekEnd());
}

void WeekEnd::doSomething(Human* context) {
	if (count < 3) {
		std::cerr << "Relax!!!" << std::endl;
		count++;
	}
	else {
		delete state;
		context->setState(state = new Work());
	}
}

int main()
{
	Human *objHuman = new Human();
	objHuman->setState(state = new Work());
	for (int i(0); i < 9; i++)
		objHuman->doSomething();

	delete state;
	delete objHuman;
	system("pause");
}
