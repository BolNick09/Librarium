#pragma once
#include "LibClasses.h"

#include <algorithm>
#include <iostream>

void Author::addAuthor(std::vector<Author>& vAuthors, Author author)
{
	vAuthors.push_back(author);
}

void Author::printAuthors(std::vector<Author>& vAuthors)
{
    std::sort(vAuthors.begin(), vAuthors.end(), [](Author a, Author b) { return a.name < b.name; });

        for (Author author : vAuthors)         
            std::cout << "Name: " << author.name << " Date of birth: " << author.dateOfBirth << " Num of books: " << author.vOwnItems.size() << std::endl;        

}

Author* Author::findAuthor(std::vector<Author>& vAuthors, std::string name)
{
    for (Author author : vAuthors) 
    {
        if (author.name == name) 
            return &author;        
    }
    return nullptr;
}
