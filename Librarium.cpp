// Librarium.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <Windows.h>
#include <conio.h>

#include "Librarium.h"

using namespace std;


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

