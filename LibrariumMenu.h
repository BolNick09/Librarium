#pragma once

#include <iostream>

#include "LibClasses.h"


enum Tasks
{
	TITLE = -1,			//Заголовочный пункт
	BOOK_ADD = 1,		//Добавить книгу
	BOOK_SEARCH,		//Поиск книги
	BOOK_LIST,			//Список всех книг
	JOURNAL_ADD,		//Добавить журнал
	JOURNAL_SEARCH,		//Поиск журнала
	JOURNAL_LIST,		//Список всех журналов
	AUTHOR_ADD,			//Добавить автора
	AUTHOR_LIST,		//Список всех авторов
	CLIENT_ADD,			//Добавить читателя
	CLIENT_SEARCH,		//Поиск читателя
	CLIENT_LIST,		//Список всех читателей
	ITEM_GIVE,			//Выдать предмет
	ITEM_TAKE_BACK,		//Вернуть предмет
	ITEM_SEARCH,		//Общий поиск по книгам и журналам
	ITEM_SEARCH_YEAR,	//Поиск по году выхода
	ITEM_LOAD_FILE,		//Загрузка данных
	EXIT				//Выход
};

class MenuItem
{
	//Класс элемента меню, включает в себя название, флаг выбора элемента и ID. Если пункт заголовочный, его ID = -1
private:
	std::string name;
	bool flSelected;
	Tasks task;
public:
	MenuItem(const std::string& name, Tasks task) : name(name), task (task), flSelected(false) {}
	const std::string& getName()
	{
		return name;
	}
	bool isSelected()
	{
		return flSelected;
	}
	size_t getTask()
	{
		return task;
	}
	void switchSelect(bool fl)
	{
		flSelected = fl;
	}
};

class Menu
{
private:
	std::vector <MenuItem*> vPtrMenuItems;

	std::vector<Author*> vAuthors;
	std::vector<Client*> vClients;
	std::vector<Item*> vItems;
public:
	void fillVMenuItems();
	void printMenu() const;

	void navigate(const char key);
	int findSelected();
	void execTask(Tasks task);

	~Menu()
	{
		for (auto a : vAuthors)
			delete a;
		for (auto c : vClients)
			delete c;
		for (auto i : vItems)
			delete i;
		for (auto m : vPtrMenuItems)
			delete m;
		vAuthors.clear();
		vClients.clear();
		vItems.clear();
		vPtrMenuItems.clear();
	}


};
std::string generateISBN();




