#ifndef BOOKS_H
#define BOOKS_H

#include <iostream>
#include <string>
#include "Library.h"
using namespace std;

class Books: public Library
{
    public:
        Books();
        Books(int, string, bool, string);
        void setAuthor(string);
        string getAuthorName()const;
    private:
        string authorName;
};
#endif // BOOKS_H
