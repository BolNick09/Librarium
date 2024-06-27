#pragma once
#include "LibrariumMenu.h"

#include <conio.h>


void Menu::fillVMenuItems()
{
	vPtrMenuItems.push_back(new MenuItem("\t1. Управление книгами", Tasks::TITLE));
	vPtrMenuItems.push_back(new MenuItem("\t1.1. Добавить книгу", Tasks::BOOK_ADD));
	vPtrMenuItems.push_back(new MenuItem("\t1.2. Поиск книги", Tasks::BOOK_SEARCH));
	vPtrMenuItems.push_back(new MenuItem("\t1.3. Список всех книг", Tasks::BOOK_LIST));
	vPtrMenuItems.push_back(new MenuItem("\t2. Управление журналами", Tasks::TITLE));
	vPtrMenuItems.push_back(new MenuItem("\t2.1. Добавить журнал", Tasks::JOURNAL_ADD));
	vPtrMenuItems.push_back(new MenuItem("\t2.2. Поиск журнала", Tasks::JOURNAL_SEARCH));
	vPtrMenuItems.push_back(new MenuItem("\t2.3. Список всех журналов", Tasks::JOURNAL_LIST));
	vPtrMenuItems.push_back(new MenuItem("\t3. Управление авторами", Tasks::TITLE));
	vPtrMenuItems.push_back(new MenuItem("\t3.1. Добавить автора", Tasks::AUTHOR_ADD));
	vPtrMenuItems.push_back(new MenuItem("\t3.2. Список всех авторов", Tasks::AUTHOR_LIST));
	vPtrMenuItems.push_back(new MenuItem("\t4. Управление читателями", Tasks::TITLE));
	vPtrMenuItems.push_back(new MenuItem("\t4.1. Добавить читателя", Tasks::CLIENT_ADD));
	vPtrMenuItems.push_back(new MenuItem("\t4.2. Поиск читателя", Tasks::CLIENT_SEARCH));
	vPtrMenuItems.push_back(new MenuItem("\t4.3. Список всех читателей", Tasks::CLIENT_LIST));
	vPtrMenuItems.push_back(new MenuItem("\t5. Выдача предметов читателям", Tasks::TITLE));
	vPtrMenuItems.push_back(new MenuItem("\t5.1. Выдать предмет", Tasks::ITEM_GIVE));
	vPtrMenuItems.push_back(new MenuItem("\t6. Возврат предметов от читателей", Tasks::TITLE));
	vPtrMenuItems.push_back(new MenuItem("\t6.1. Вернуть предмет", Tasks::ITEM_TAKE_BACK));
	vPtrMenuItems.push_back(new MenuItem("\t7. Общий поиск по книгам и журналам", Tasks::ITEM_SEARCH));
	vPtrMenuItems.push_back(new MenuItem("\t7.1. Поиск по году выхода", Tasks::ITEM_SEARCH_YEAR));
	vPtrMenuItems.push_back(new MenuItem("\t8. Загрузка данных", Tasks::ITEM_LOAD_FILE));
	vPtrMenuItems.push_back(new MenuItem("\t9. Выход", Tasks::EXIT));
}

void Menu::printMenu() const
{
	for (auto i : vPtrMenuItems)
	{
		if (i->isSelected())
			std::cout << "-->"; 
		
		std::cout << i->getName() << std::endl;	
	}

}
int Menu::findSelected()
{
	for (size_t i = 0; i < vPtrMenuItems.size(); i++)
	{
		if (vPtrMenuItems[i]->isSelected())
			return i;
	}
	return 0;
}

void Menu::navigate(const char key)
{
	system("cls");
	size_t selectedItem = Menu::findSelected();

	if (!selectedItem)
		vPtrMenuItems[0]->switchSelect(true);

	switch (key)
	{
		    case 72: // Клавиша со стрелкой вверх
            {
				if (selectedItem > 0)
				{
					vPtrMenuItems[selectedItem]->switchSelect(false);
					selectedItem--;
					vPtrMenuItems[selectedItem]->switchSelect(true);
				}
                break;
            }
            case 80: // Клавиша со стрелкой вниз
            {
				if (selectedItem < vPtrMenuItems.size() - 1)
				{
					vPtrMenuItems[selectedItem]->switchSelect(false);
					selectedItem++;
					vPtrMenuItems[selectedItem]->switchSelect(true);
				}
                break;
            }
			case 13: //ENTER
			{
				vPtrMenuItems[selectedItem]->execTask();
				break;
			}
		default:
		{
			break;
		}
	}
	Menu::printMenu();



}

void MenuItem::execTask()
{
	system("cls");
	
	switch (task)
	{
		case TITLE :
		{
			std::cout << "TITLE" << std::endl; //Заголовочный пункт
			break;
		}
		case BOOK_ADD :
		{
			std::cout << "BOOK_ADD" << std::endl;			//Добавить книгу
			break;
		}
		case BOOK_SEARCH :
		{
			std::cout << "BOOK_SEARCH" << std::endl;	//Поиск книги
			break;
		}
		case BOOK_LIST :
		{
			std::cout << "BOOK_LIST" << std::endl;	//Список всех книг
			break;
		}
		case JOURNAL_ADD :
		{
			std::cout << "JOURNAL_ADD" << std::endl;	//Добавить журнал
			break;
		}
		case JOURNAL_SEARCH :
		{
			std::cout << "JOURNAL_SEARCH" << std::endl;	//Поиск журнала
			break;
		}
		case JOURNAL_LIST:
		{
			std::cout << "JOURNAL_LIST" << std::endl;	//Список всех журналов
			break;
		}
		case AUTHOR_ADD :
		{
			
			std::cout << "Выбрана функция добавления автора" << std::endl;	//Добавить автора
			std::cout << "Введите имя: ";
			std::string name;
			std::cin >> name;
			std::cout << std::endl << "Введите год рождения: ";
			int age;
			std::cin >> age;
			Author author(name, age);
			author.addAuthor(vAuthors, author);
			std::cout << std::endl << "Автор " << name << "успешно добавлен." << std::endl << "нажмите любую клавишу, чтобы вернуться в меню";
			char k = _getch();

			break;
		}
		case AUTHOR_LIST :
		{
			std::cout << "AUTHOR_LIST" << std::endl;	//Список всех авторов
			break;
		}
		case CLIENT_ADD :
		{
			std::cout << "CLIENT_ADD" << std::endl;	//Добавить читателя
			break;
		}
		case CLIENT_SEARCH :
		{
			std::cout << "CLIENT_SEARCH" << std::endl;	//Поиск читателя
			break;
		}
		case CLIENT_LIST :
		{
			std::cout << "CLIENT_LIST" << std::endl;	//Список всех читателей
			break;
		}
		case ITEM_TAKE_BACK :
		{
			std::cout << "ITEM_TAKE_BACK" << std::endl;	//Вернуть предмет
			break;
		}
		case ITEM_GIVE:
		{
			std::cout << "ITEM_GIVE" << std::endl;	//Выдать предмет
			break;
		}
		case ITEM_SEARCH :
		{
			std::cout << "ITEM_SEARCH" << std::endl;	//Общий поиск по книгам и журналам	
			break;
		}
		case ITEM_SEARCH_YEAR :
		{
			std::cout << "ITEM_SEARCH_YEAR" << std::endl;	//Поиск по году выхода
			break;
		}
		case ITEM_LOAD_FILE :
		{
			std::cout << "ITEM_LOAD_FILE" << std::endl;	//Загрузка данных
			break;
		}
		case EXIT :
		{
			std::cout << "EXIT" << std::endl;	//Выход
			break;
		}
		
	}
}

