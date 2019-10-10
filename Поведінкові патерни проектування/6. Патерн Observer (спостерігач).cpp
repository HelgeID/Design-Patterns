//Патерн Observer (спостерігач)
//Дає змогу одним об’єктам стежити й реагувати на події, 
//які відбуваються в інших об’єктах.
#include <iostream>
#include <vector>
#include <algorithm>

class Observer {
public:
	virtual void handleEvent(int t, int p) = 0;
};

class Observed {
public:
	virtual void addObserver(Observer* obj) = 0;
	virtual void removeObserver(Observer* obj) = 0;
	virtual void notifyObservers() = 0;
};

//спостережуваний об'єкт
class MeteoStation : public Observed {
	int temperature;
	int pressure;

	std::vector<Observer*> observers;

public:
	void setParam(int t, int p) {
		temperature = t;
		pressure = p;

		notifyObservers();
	}

	void addObserver(Observer* obj) override {
		observers.push_back(obj);
	}
	void removeObserver(Observer* obj) override {
		observers.erase(
			std::remove(observers.begin(), observers.end(), obj), 
			observers.end()
		);
		delete obj;
	}
	void notifyObservers() override {
		for (auto o : observers)
			o->handleEvent(temperature, pressure);//..arg(t,p)
	}
};

//спостерігачі
class ConsoleObserver : public Observer {
public:
	void handleEvent(int t, int p) override {
		std::cerr << " temperature:" << t << " pressure:" << p << std::endl;
	}
};

class ChangeObserver : public Observer {
public:
	void handleEvent(int t, int p) override {
		std::cerr << " change: temperature, pressure" << std::endl;
	}
};

int main()
{
	MeteoStation* ms = new MeteoStation();
	Observer* log1; Observer* log2;

	ms->addObserver(log1 = new ConsoleObserver());
	ms->setParam(25, 760);

	ms->addObserver(log2 = new ChangeObserver());
	ms->removeObserver(log1);
	ms->setParam(20, 730);

	delete ms;
	system("pause");
}
