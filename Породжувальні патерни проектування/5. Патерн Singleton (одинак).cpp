//Патерн Singleton(одинак)
//Гарантує, що клас має лише один екземпляр, та надає глобальну точку доступу до нього.
#include <iostream>

class Singleton
{
	static Singleton* instance;
	Singleton() { counter++; }

public:
	int counter{ 0 }; //кількість викликів конструктора

	static Singleton* getInstance() {
		if (instance == 0)
			instance = new Singleton();
		return instance;
	}
};

Singleton* Singleton::instance = 0;

int main()
{
	//Singelton *singelton = new Singelton(); //не працює
	Singleton* s1 = Singleton::getInstance();
	Singleton* s2 = Singleton::getInstance();
	Singleton* s3 = Singleton::getInstance();

	std::cerr << s1->counter << std::endl;
	std::cerr << s2->counter << std::endl;
	std::cerr << s3->counter << std::endl;

	system("pause");
}
