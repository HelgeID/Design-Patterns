//Патерн Strategy (стратегія)
//Визначає сімейство схожих алгоритмів і розміщує кожен з них у власному класі.
#include <iostream>
#include <array>
#include <algorithm>

#define SIZE 4

void Print(std::array<int, SIZE>& arr) {
	for (auto el : arr)
		std::cerr << el << " ";
	std::cerr << std::endl;
	return;
}

class Sorting {
public:
	virtual void sort(std::array<int, SIZE>& ) = 0;
};

class StrategyClient {
	Sorting *strategy;
public:
	void setStrategy(Sorting *strategy) { this->strategy = strategy; }
	void exeStrategy(std::array<int, SIZE>& arr) { strategy->sort(arr); }
};

class SortingStrategy1 : public Sorting {
public:
	void sort(std::array<int, SIZE>& arr) override {
		std::sort(arr.begin(), arr.end());
	}
};

class SortingStrategy2 : public Sorting {
public:
	void sort(std::array<int, SIZE>& arr) override {
		std::stable_sort(arr.begin(), arr.end());
	}
};

class SortingStrategy3 : public Sorting {
public:
	void sort(std::array<int, SIZE>& arr) override {
		std::partial_sort(arr.begin(), arr.end(), arr.end());
	}
};

class SortingStrategy4 : public Sorting {
public:
	void sort(std::array<int, SIZE>& arr) override {
		std::make_heap(arr.begin(), arr.end());
		std::sort_heap(arr.begin(), arr.end());
	}
};

int main()
{
	StrategyClient *client = new StrategyClient();

	//Strategy 1
	std::array<int, SIZE> arr1{ 2, 1, 4, 3 };
	client->setStrategy(new SortingStrategy1());
	client->exeStrategy(arr1);
	Print(arr1); //1 2 3 4

	//Strategy 2
	std::array<int, SIZE> arr2{ 20, 10, 40, 30 };
	client->setStrategy(new SortingStrategy2());
	client->exeStrategy(arr2);
	Print(arr2); //10 20 30 40

	//Strategy 3
	std::array<int, SIZE> arr3{ 2, 1, 4, 3 };
	client->setStrategy(new SortingStrategy3());
	client->exeStrategy(arr3);
	Print(arr3); //1 2 3 4

	//Strategy 4
	std::array<int, SIZE> arr4{ 20, 10, 40, 30 };
	client->setStrategy(new SortingStrategy4());
	client->exeStrategy(arr4);
	Print(arr4); //10 20 30 40

	//todo delete SortingStrategy

	delete client;
	system("pause");
}
