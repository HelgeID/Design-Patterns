//Патерн Chain of Responsibility (ланцюжок обов’язків)
//Дає змогу передавати запити послідовно ланцюжком обробників.
#include <iostream>
#include <string>

enum Level
{
	ERROR = 1, DEBUG = 2, INFO = 3
};

class Logger {
	int priority;
	Logger* next{ nullptr };

	virtual void write(std::string) = 0;

public:
	Logger(int priority) : priority(priority)
	{}
	
	void setNext(Logger* next) {
		this->next = next;
	}

	void writeMessage(std::string msg, int level) {
		if (level <= priority)
			write(msg);

		if (next != nullptr)
			next->writeMessage(msg, level);
	}

};

class SMSLogger : public Logger {
private:
	void write(std::string msg) override {
		std::cerr << "SMS: " + msg << std::endl;
	}

public:
	SMSLogger(int priority) : Logger(priority)
	{}
};

class FileLogger : public Logger {
private:
	void write(std::string msg) override {
		std::cerr << "Write to file: " + msg << std::endl;
	}

public:
	FileLogger(int priority) : Logger(priority)
	{}
};

class EmailLogger : public Logger {
private:
	void write(std::string msg) override {
		std::cerr << "E-mail: " + msg << std::endl;
	}

public:
	EmailLogger(int priority) : Logger(priority)
	{}
};

int main()
{
	Logger* logger0 = new SMSLogger(Level::ERROR);
	Logger* logger1 = new FileLogger(Level::DEBUG);
	Logger* logger3 = new EmailLogger(Level::INFO);

	logger0->setNext(logger1);
	logger1->setNext(logger3);

	//logger0->writeMessage("All is good!", Level::INFO);
	//logger0->writeMessage("Debug mode!", Level::DEBUG);
	//logger0->writeMessage("System has error!", Level::ERROR);

	system("pause");
}
