//Патерн Template Method (шаблонний метод)
//Визначає кістяк алгоритму, перекладаючи відповідальність 
//за деякі його кроки на підкласи.
#include <iostream>

class MY {
	virtual void diff() = 0;
	virtual void diff2() = 0;
public:
	void templateMethod() {
		std::cerr << 1 << " ";
		diff(); //відмінність кода 1
		std::cerr << 3 << " ";
		diff2(); //відмінність кода 2
		std::cerr << std::endl;
	}
};

class A : public MY {
	void diff() override { std::cerr << 2 << " "; }
	void diff2() override { }
};

class B : public MY {
	void diff() override { std::cerr << "second" << " "; }
	void diff2() override { std::cerr << 4 << " "; }
};

int main()
{
	MY *aObj = new A();
	aObj->templateMethod();

	MY *bObj = new B();
	bObj->templateMethod();


	delete aObj;
	delete bObj;
	system("pause");
}
