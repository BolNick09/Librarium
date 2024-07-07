#include "LibClasses.h"

#include <algorithm>
#include <iostream>


void Author::printAuthors(std::vector<Author*>& vAuthors, bool isWithBooks)
{
    //std::sort(vAuthors.begin(), vAuthors.end(), [](Author a, Author b) { return a.name < b.name; });

    for (Author* author : vAuthors)
    {
        std::cout << "Name: " << author->name << " Date of birth: " << author->dateOfBirth << " Num of books: " << author->vOwnItems.size() << std::endl;
        if (author->vOwnItems.size() && isWithBooks)
        {
            std::cout << "Список книг автора: " << std::endl;
            for (Item* item : author->vOwnItems)            
                item->print();            
        }
    }

}

Author* Author::findAuthor(std::vector<Author*>& vAuthors, const std::string& name)
{
    for (Author* author : vAuthors) 
    {
        if (author->name == name)
            return author;
        
    }
    //std::cout << "Автор не найден" << std::endl;
    return nullptr;
}

void Client::printClients(const std::vector <Client*>& vClient, bool isPrintBooks) 
{
    for (Client* client : vClient)
    {
        client->print();
        if (isPrintBooks)
        {
            if (client->vTakenItems.size())
            {
                for (auto item : client->vTakenItems)
                    item->print();
            }
        }
    }
    
}

Client* Client::find(const std::string& name, std::vector <Client*>& vClient)
{
    //std::cout << "Выбран поиск по имени или фамилии" << std::endl;
    for (Client* client : vClient) 
    {
        if (client->firstName == name)
            return client;
        if (client->sureName == name)
            return client;
        
    }
    //std::cout << "Клиент не найден" << std::endl;
    return nullptr;
}

Client* Client::find(size_t cardNum, std::vector<Client*>& vClient)
{
    //std::cout << "Выбран поиск по номеру читательского билета" << std::endl;
    for (Client* client : vClient) 
    {
        if (client->cardNum == cardNum)
            return client;        
    }
    //std::cout << "Клиент не найден" << std::endl;
    return nullptr;
}

void Client::takeItem(Item* item)
{
    if (item->getAvailableCount())
    {
        vTakenItems.push_back(item);
        item->give();
    }
    else
        std::cout << "В библиотеке закончилась эта книга" << std::endl;
}

void Client::giveBackItem(Item* item)
{
    for (size_t i = 0; i < vTakenItems.size(); i++) 
    {
        if (vTakenItems[i] == item) 
        {
            vTakenItems.erase(vTakenItems.begin() + i);
            item->takeBack();
            return;
        }
    }
    std::cout << "У читателя нет такой книги" << std::endl;
    return;
    
}

void Book::print() const
{
    std::cout << "  Данные книги: " << name << std::endl;
    std::cout << "  ID: " << id << std::endl;
    std::cout << "  Автор: " << author->getName() << std::endl;
    std::cout << "  Год публикации: " << publishYear << std::endl;
    std::cout << "  Общий тираж: " << totalCount << std::endl;
    std::cout << "  Доступно экземпляров: " << availableCount << std::endl;
    std::cout << "  ISBN: " << ISBN << std::endl;
    std::cout << "  Количество страниц: " << pageCount << std::endl;
}

Item* Item::find(const std::string& name, std::vector<Item*>& vItems)
{
    for (Item* item : vItems) 
    {
        if (item->name == name) 
            return item;       
    }
    return nullptr;  
}

Item* Item::find(int year, std::vector<Item*>& vItems)
{
    for (Item* item : vItems)
    {
        if (item->publishYear == year)
            return item;
    }
    return nullptr;
}


Book* Book::find(int year, std::vector <Item*>& vItems)
{
    Item* item = Item::find(year, vItems);
    if (item && dynamic_cast<Book*>(item)) 
        return dynamic_cast<Book*>(item);
    
    return nullptr;  // Ничего не найдено
}

Book* Book::find(const std::string& name, std::vector <Item*>& vItems)
{
    Item* item = Item::find(name, vItems);
    if (item && dynamic_cast<Book*>(item))
        return dynamic_cast<Book*>(item);

    return nullptr;  // Ничего не найдено
}

Journal* Journal::find(int year, std::vector <Item*>& vItems)
{
    Item* item = Item::find(year, vItems);
    if (item && dynamic_cast<Journal*>(item) )
        return dynamic_cast<Journal*>(item);

    return nullptr;  // Ничего не найдено
}

Journal* Journal::find(const std::string& name, std::vector <Item*>& vItems)
{
    Item* item = Item::find(name, vItems);
    if (item && dynamic_cast<Journal*>(item))
        return dynamic_cast<Journal*>(item);

    return nullptr;  // Ничего не найдено
}

void Journal::print() const
{
    std::cout << "Данные журнала: " << name << std::endl;
    std::cout << "  ID: " << id << std::endl;
    std::cout << "  Автор: " << author->getName() << std::endl;
    std::cout << "  Год публикации: " << publishYear << std::endl;
    std::cout << "  Общий тираж: " << totalCount << std::endl;
    std::cout << "  Доступно экземпляров: " << availableCount << std::endl;
    std::cout << "  Номер публикации: " << pubNum << std::endl;
    std::cout << "  Категория: " << category << std::endl;
}


