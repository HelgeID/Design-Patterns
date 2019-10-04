//Патерн Builder (будівельник)
//Дає змогу створювати складні об'єкти крок за кроком. Будівельник дає можливість використовувати 
//один і той самий код будівництва для отримання різних відображень об'єктів.
#include <iostream>

class BuildWalls { public: void Info() { std::cerr << "walls built" << std::endl; } };
class BuildDoors { public: void Info() { std::cerr << "doors built" << std::endl; } };
class BuildWindows { public: void Info() { std::cerr << "windows built" << std::endl; } };
class BuildRoof { public: void Info() { std::cerr << "roof built" << std::endl; } };
class BuildGarage { public: void Info() { std::cerr << "garage built" << std::endl; } };
class BuildSwimmingPool { public: void Info() { std::cerr << "swimming pool built" << std::endl; } };
class BuildGarden { public: void Info() { std::cerr << "garden built" << std::endl; } };
class BuildStatues { public: void Info() { std::cerr << "statues built" << std::endl; } };


class House
{
public:
	BuildWalls* bWalls;
	BuildDoors* bDoors;
	BuildWindows* bWindows;
	BuildRoof* bRoof;
	BuildGarage* bGarage;
	BuildSwimmingPool* bSwimmingPool;
	BuildGarden* bGarden;
	BuildStatues* bStatues;

	void Info()
	{
		bWalls != nullptr ? bWalls->Info() : 0;
		bDoors != nullptr ? bDoors->Info() : 0;
		bWindows != nullptr ? bWindows->Info() : 0;
		bRoof != nullptr ? bRoof->Info() : 0;
		bGarage != nullptr ? bGarage->Info() : 0;
		bSwimmingPool != nullptr ? bSwimmingPool->Info() : 0;
		bGarden != nullptr ? bGarden->Info() : 0;
		bStatues != nullptr ? bStatues->Info() : 0;
	}
};

class HouseBuilder
{
protected:
	House* ptrHouse;
public:
	HouseBuilder() : ptrHouse(nullptr) {}
	virtual ~HouseBuilder() {}

	virtual void createHouse() {};
	virtual void buildWalls() { ptrHouse->bWalls = nullptr; };
	virtual void buildDoors() { ptrHouse->bDoors = nullptr; };
	virtual void buildWindows() { ptrHouse->bWindows = nullptr; };
	virtual void buildRoof() { ptrHouse->bRoof = nullptr; };
	virtual void buildGarage() { ptrHouse->bGarage = nullptr; };
	virtual void buildSwimmingPool() { ptrHouse->bSwimmingPool = nullptr; };
	virtual void buildGarden() { ptrHouse->bGarden = nullptr; };
	virtual void buildStatues() { ptrHouse->bStatues = nullptr; };

	virtual House* getHouse() { return ptrHouse; }
};

class HouseWithRoofBuilder : public HouseBuilder
{
public:
	void createHouse() { ptrHouse = new House; }
	void buildWalls() { ptrHouse->bWalls = new BuildWalls; };
	void buildDoors() { ptrHouse->bDoors = new BuildDoors; };
	void buildWindows() { ptrHouse->bWindows = new BuildWindows; };
	void buildRoof() { ptrHouse->bRoof = new BuildRoof; };
};

class HouseWithGarageBuilder : public HouseBuilder
{
public:
	void createHouse() { ptrHouse = new House; }
	void buildWalls() { ptrHouse->bWalls = new BuildWalls; };
	void buildDoors() { ptrHouse->bDoors = new BuildDoors; };
	void buildWindows() { ptrHouse->bWindows = new BuildWindows; };
	void buildGarage() { ptrHouse->bGarage = new BuildGarage; };
};

class HouseWithSwimmingPoolBuilder : public HouseBuilder
{
public:
	void createHouse() { ptrHouse = new House; }
	void buildWalls() { ptrHouse->bWalls = new BuildWalls; };
	void buildDoors() { ptrHouse->bDoors = new BuildDoors; };
	void buildWindows() { ptrHouse->bWindows = new BuildWindows; };
	void buildSwimmingPool() { ptrHouse->bSwimmingPool = new BuildSwimmingPool; };
};

class HouseWithGardenBuilder : public HouseBuilder
{
public:
	void createHouse() { ptrHouse = new House; }
	void buildWalls() { ptrHouse->bWalls = new BuildWalls; };
	void buildDoors() { ptrHouse->bDoors = new BuildDoors; };
	void buildWindows() { ptrHouse->bWindows = new BuildWindows; };
	void buildGarden() { ptrHouse->bGarden = new BuildGarden; };
};

class HouseWithStatuesBuilder : public HouseBuilder
{
public:
	void createHouse() { ptrHouse = new House; }
	void buildWalls() { ptrHouse->bWalls = new BuildWalls; };
	void buildDoors() { ptrHouse->bDoors = new BuildDoors; };
	void buildWindows() { ptrHouse->bWindows = new BuildWindows; };
	void buildStatues() { ptrHouse->bStatues = new BuildStatues; };
};

class Director
{
public:
	House* createHouse(HouseBuilder & builder)
	{
		builder.createHouse();
		builder.buildWalls();
		builder.buildDoors();
		builder.buildWindows();
		builder.buildRoof();
		builder.buildGarage();
		builder.buildSwimmingPool();
		builder.buildGarden();
		builder.buildStatues();

		return builder.getHouse();
	}
};

int main()
{
	Director director;
	HouseWithRoofBuilder objHouseWithRoofBuilder;
	HouseWithGarageBuilder objHouseWithGarageBuilder;
	HouseWithSwimmingPoolBuilder objHouseWithSwimmingPoolBuilder;
	HouseWithGardenBuilder objHouseWithGardenBuilder;
	HouseWithStatuesBuilder objHouseWithStatuesBuilder;

	House* ptrHouseWithRoofBuilder = director.createHouse(objHouseWithRoofBuilder);
	ptrHouseWithRoofBuilder->Info();
	std::cerr << std::endl;

	House* ptrHouseWithGarageBuilder = director.createHouse(objHouseWithGarageBuilder);
	ptrHouseWithGarageBuilder->Info();
	std::cerr << std::endl;

	House* ptrHouseWithSwimmingPoolBuilder = director.createHouse(objHouseWithSwimmingPoolBuilder);
	ptrHouseWithSwimmingPoolBuilder->Info();
	std::cerr << std::endl;

	House* ptrHouseWithGardenBuilder = director.createHouse(objHouseWithGardenBuilder);
	ptrHouseWithGardenBuilder->Info();
	std::cerr << std::endl;

	House* ptrHouseWithStatuesBuilder = director.createHouse(objHouseWithStatuesBuilder);
	ptrHouseWithStatuesBuilder->Info();
	std::cerr << std::endl;

	// ...
	system("pause");
}
