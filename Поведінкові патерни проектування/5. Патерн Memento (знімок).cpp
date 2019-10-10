//Патерн Memento (знімок)
//Дає змогу зберігати та відновлювати минулий стан об’єктів.
#include <iostream>
#include <string>

class Save {
	std::string level;
	int ms;
public:
	Save(std::string level, int ms) :
		level(level), ms(ms)
	{}
	std::string getLevel() { return level; }
	int getMS() { return ms; }
};

class Game {
	std::string level{ "" };
	int ms{ 0 };

public:
	void set(std::string level, int ms) {
		this->level = level;
		this->ms = ms;
	}

	void load(Save* save) {
		level = save->getLevel();
		ms = save->getMS();
	}

	std::string toString() {
		return "Game: " + level + ", " + std::to_string(ms);
	}

	Save* save() { return new Save(level, ms); }
};

class File
{
	Save* save;
public:
	Save* getSave() { return save; }
	void setSave(Save* save) { this->save = save; }
};

int main()
{
	Game *game = new Game();
	game->set("Level1", 30000);
	std::cerr << game->toString() << std::endl;

	File *file = new File();
	Save* save;
	file->setSave(save = game->save());

	game->set("Level2", 60000);
	std::cerr << game->toString() << std::endl;

	game->load(file->getSave());
	std::cerr << game->toString() << std::endl;

	delete save;
	delete game;

	system("pause");
}
