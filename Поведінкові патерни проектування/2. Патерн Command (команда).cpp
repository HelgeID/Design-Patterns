//Патерн Command (команда)
//Перетворює запити на об’єкти, дозволяючи передавати їх як аргументи під час виклику методів.
#include <iostream>

//Receiver 
struct Comp {
	void start() { std::cerr << "Start" << std::endl; }
	void stop() { std::cerr << "Stop" << std::endl; }
	void reset() { std::cerr << "Reset" << std::endl; }
};

class Command {
public:
	Comp* computer;
	virtual void execute() = 0;
};
//ConcreteCommand
class StartCommand : public Command {
public:
	StartCommand(Comp* comuter) { this->computer = comuter; }
	~StartCommand() { delete this; }
	void execute() override { computer->start(); }
};
//ConcreteCommand
class StopCommand : public Command {
public:
	StopCommand(Comp* comuter) { this->computer = comuter; }
	~StopCommand() { delete this; }
	void execute() override { computer->stop(); }
};
//ConcreteCommand
class ResetCommand : public Command {
public:
	ResetCommand(Comp* comuter) { this->computer = comuter; }
	~ResetCommand() { delete this; }
	void execute() override { computer->reset(); }
};

//Invoker
class User {
	Command *start, *stop, *reset; //вказівники на команду

public:
	User(Command *start, Command *stop, Command *reset)
		:start(start), stop(stop), reset(reset)
	{}

	void startCommand() { start->execute(); }
	void stopCommand() { stop->execute(); }
	void resetCommand() { reset->execute(); }
};

int main()
{
	Comp* comp = new Comp();
	User* u = new User(
		new StartCommand(comp),
		new StopCommand(comp),
		new ResetCommand(comp)
	);

	u->startCommand();
	u->stopCommand();
	u->resetCommand();

	delete comp;
	system("pause");
}
