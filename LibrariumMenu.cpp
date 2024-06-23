#include "LibrariumMenu.h"

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
		default:
		{
			break;
		}
	}
	Menu::printMenu();



}


