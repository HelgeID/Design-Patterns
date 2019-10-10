//Патерн Iterator(Ітератор)
//Дає змогу послідовно обходити елементи складових об’єктів, 
//не розкриваючи їхньої внутрішньої організації.
#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> tasks{ "read", "processing", "write" };

class Iterator {
public:
	virtual bool hasNext() = 0;
	virtual std::string next() = 0;
};

class Container {
public:
	virtual Iterator* getIterator() = 0;
};

class Tasks : public Container {
public:
	Iterator* getIterator() override {
		return new TaskIterator();
	}

private:
	//клас TaskIterator створюється для виклику в getIterator()
	class TaskIterator : public Iterator {
		int index{ 0 };

	public:
		bool hasNext() override {
			if (index < tasks.size())
				return true;
			return false;
		}
		std::string next() override {
			return tasks[index++];
		}
	};
};

int main()
{
	Tasks* tasks = new Tasks();
	Iterator* it = tasks->getIterator();

	while (it->hasNext())
		std::cerr << it->next() << std::endl;

	delete it;
	system("pause");
}
