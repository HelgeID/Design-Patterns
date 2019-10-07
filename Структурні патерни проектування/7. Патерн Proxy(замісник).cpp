//Патерн Proxy(замісник)
//Дає змогу підставляти замість реальних об’єктів спеціальні об’єкти-замінники.
#include <iostream>
#include <string>

class Image
{
public:
	virtual void Display() = 0;
};

class RealImage : public Image
{
	std::string path;
public:
	RealImage(std::string path)
		: path(path)
	{ load(); }

	void load() {
		std::cerr << "Load from " + path << std::endl;
	}

	void Display() override
	{
		std::cerr << "View " + path << std::endl;
	}
};

class ProxyImage : public Image
{
	std::string path;
	RealImage *image{ nullptr };
public:
	ProxyImage(std::string path)
		: path(path)
	{}

	void Display() override
	{
		if (image == nullptr)
			image = new RealImage(path);
		image->Display();
	}
};

int main()
{
	//Image *image1 = new RealImage("../Pictures.jpg"); //Load
	//image1->Display(); //Display

	Image *image2 = new ProxyImage("../Pictures.jpg");
	image2->Display(); //Load + Display
	
	system("pause");
}
