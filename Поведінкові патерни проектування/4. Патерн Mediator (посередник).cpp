//Патерн Mediator (посередник)
//Дає змогу зменшити зв’язаність великої кількості класів між собою,
//усе проходить через посередника.
#include <iostream>
#include <string>
#include <vector>

class User {
public:
	virtual void sendMessage(std::string msg) = 0;
	virtual void getMessage(std::string msg) = 0;
};

class Chat {
public:
	virtual void sendMessage(std::string msg, User *user) = 0;
};

class Admin : public User {
	Chat* chat;
public:
	Admin(Chat* chat) : chat(chat)
	{}

	void sendMessage(std::string msg) override { chat->sendMessage(msg, this); }
	void getMessage(std::string msg) override {
		std::cerr << "Admin get msg: <<" + msg + ">>" << std::endl;
	}
};

class SimpleUser : public User {
	Chat* chat{ nullptr };
public:
	SimpleUser(Chat* chat) : chat(chat)
	{}

	void sendMessage(std::string msg) override { chat->sendMessage(msg, this); }
	void getMessage(std::string msg) override {
		std::cerr << "User get msg: <<" + msg + ">>" << std::endl;
	}
};

//Mediator
class TextChat : public Chat {
	User* admin;
	std::vector<User*> users;

public:
	void setAdmin(User* admin) { this->admin = admin; }
	void addUser(User* user) { users.push_back(user); }

	//відправка повідомлення адміну та юзерам
	void sendMessage(std::string msg, User *user) override {
		admin->getMessage(msg);

		for (User* u : users)
			u->getMessage(msg);
	}
};

int main()
{
	//створюємо чат (посередника)
	TextChat *chat = new TextChat();

	//створюємо адміна та юзерів, які мають посилання на заг чат
	User* admin = new Admin(chat); chat->setAdmin(admin); //setAdmin - говоримо, щоб чат знав про адміна
	User* user1 = new SimpleUser(chat); chat->addUser(user1); //addUser - добавляємо, щоб чат знав про user1
	User* user2 = new SimpleUser(chat); chat->addUser(user2); //addUser - добавляємо, щоб чат знав про user2

	user1->sendMessage("HI, I'm user!");
	admin->sendMessage("Admin here!");

	delete admin;
	delete user1;
	delete user2;

	system("pause");
}
