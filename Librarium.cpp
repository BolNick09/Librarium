// Librarium.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <Windows.h>
#include <conio.h>

#include "LibrariumMenu.h"

using namespace std;

// Заглушки функций
void addBook() 
{ 
    cout << "Выбран пункт 1.1. Добавить книгу" << endl; 
}
void searchBook() 
{ 
    cout << "Выбран пункт 1.2. Поиск книги" << endl; 
}
void listBooks() 
{ 
    cout << "Выбран пункт 1.3. Список всех книг" << endl; 
}
void addMagazine() 
{ 
    cout << "Выбран пункт 2.1. Добавить журнал" << endl; 
}
void searchMagazine() 
{ 
    cout << "Выбран пункт 2.2. Поиск журнала" << endl; 
}
void listMagazines() 
{ 
    cout << "Выбран пункт 2.3. Список всех журналов" << endl; 
}
void addAuthor() 
{ 
    cout << "Выбран пункт 3.1. Добавить автора" << endl; 
}
void listAuthors() 
{ 
    cout << "Выбран пункт 3.2. Список всех авторов" << endl; 
}
void addReader() 
{ 
    cout << "Выбран пункт 4.1. Добавить читателя" << endl; 
}
void searchReader() 
{ 
    cout << "Выбран пункт 4.2. Поиск читателя" << endl; 
}
void listReaders() 
{ 
    cout << "Выбран пункт 4.3. Список всех читателей" << endl; 
}
void issueItem() 
{ 
    cout << "Выбран пункт 5.1. Выдать предмет (книга или журнал)" << endl; 
}
void returnItem() 
{ 
    cout << "Выбран пункт 6.1. Вернуть предмет (книга или журнал)" << endl; 
}
void searchItemsByYear() 
{ 
    cout << "Выбран пункт 7.1. Поиск по году выхода" << endl; 
}
void loadData() 
{ 
    cout << "Выбран пункт 8. Загрузка данных" << endl; 
}
void exitProgram() 
{ 
    cout << "Выбран пункт 9. Выход" << endl; 
}


int main()
{
    Menu menu;

    setlocale(LC_ALL, "Russian");

    menu.fillVMenuItems();
    menu.printMenu();

    while (true)
    {
        char key = _getch();
        menu.navigate(key);
    }

}


//int main() 
//{
//    setlocale(LC_ALL, "Russian");
//    // Список пунктов меню
//    vector<string> menuItems = 
//    {
//        "\t1. Управление книгами",
//        "\t1.1. Добавить книгу",
//        "\t1.2. Поиск книги",
//        "\t1.3. Список всех книг",
//        "\t2. Управление журналами",
//        "\t2.1. Добавить журнал",
//        "\t2.2. Поиск журнала",
//        "\t2.3. Список всех журналов",
//        "\t3. Управление авторами",
//        "\t3.1. Добавить автора",
//        "\t3.2. Список всех авторов (**в лексикографическом порядке**)",
//        "\t4. Управление читателями",
//        "\t4.1. Добавить читателя",
//        "\t4.2. Поиск читателя",
//        "\t4.3. Список всех читателей",
//        "\t5. Выдача предметов читателям",
//        "\t5.1. Выдать предмет (книга или журнал)",
//        "\t6. Возврат предметов от читателей",
//        "\t6.1. Вернуть предмет (книга или журнал)",
//        "\t7. Общий поиск по книгам и журналам",
//        "\t7.1. Поиск по году выхода",
//        "\t8. Загрузка данных",
//        "\t9. Выход"
//    };
//
//    // Текущий выбранный пункт меню
//    int selectedItem = 0;
//
//    // Цикл навигации по меню
//    bool running = true;
//    while (running) 
//    {
//        system("cls");
//
//        // Печать меню
//        for (int i = 0; i < menuItems.size(); i++) 
//        {
//            string item = menuItems[i];
//            if (i == selectedItem) 
//                item = "--> " + item;
//            
//            cout << item << endl;
//        }
//
//        // Получение нажатой клавиши
//        char key = _getch();
//
//        // Обработка нажатой клавиши
//        switch (key) 
//        {
//            case 72: // Клавиша со стрелкой вверх
//            {
//                if (selectedItem > 0)
//                    selectedItem--;
//                break;
//            }
//            case 80: // Клавиша со стрелкой вниз
//            {
//                if (selectedItem < menuItems.size() - 1)            
//                    selectedItem++;            
//                break;
//            }
//            case 13: // Клавиша Enter
//            {
//                // Вызов функции, соответствующей выбранному пункту меню
//                switch (selectedItem)
//                {
//                    case 0:
//                    {
//                        addBook();
//                        break;
//                    }
//                    case 1:
//                    {
//                        searchBook();
//                        break;
//                    }
//                    case 2:
//                    {
//                        listBooks();
//                        break;
//                    }
//                    case 3:
//                    {
//                        addMagazine();
//                        break;
//                    }
//                    case 4:
//                    {
//                        searchMagazine();
//                        break;
//                    }
//                    case 5:
//                    {
//                        listMagazines();
//                        break;
//                    }
//                    case 6:
//                    {
//                        addAuthor();
//                        break;
//                    }
//                    case 7:
//                    {
//                        listAuthors();
//                        break;
//                    }
//                    case 8:
//                    {
//                        addReader();
//                        break;
//                    }
//                    case 9:
//                    {
//                        searchReader();
//                        break;
//                    }
//                    case 10:
//                    {
//                        listReaders();
//                        break;
//                    }
//                    case 11:
//                    {
//                        issueItem();
//                        break;
//                    }
//                    case 12:
//                    {
//                        returnItem();
//                        break;
//                    }
//                    case 13:
//                    {
//                        searchItemsByYear();
//                        break;
//                    }
//                    case 14:
//                    {
//                        loadData();
//                        break;
//                    }
//                    case 15:
//                        exitProgram();
//                        running = false;
//                        break;
//                    }
//                break;
//            }
//        }
//
//    }
//
//    return 0;
//}