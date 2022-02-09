#include <iostream>
#include <string>

#include "Library.h"

using namespace std;

Library::Library()
{
    id = 0;
    name = "no-name";
    status = true;
}

Library::Library(int i, string n, bool s) //id, name, status    base clase constructor
{
    id = i;
    name = n;
    status = s;
}

void Library::setid(int i)
{
    id = i;
}
int Library::getid() const
{
    return id;
}

void Library::setname(string n)
{
    name=n;
}

string Library::getname() const
{
    return name;
}

void Library::setStatus(bool b)
{
    status = b;
}

bool Library::getStatus() const
{
    return status;
}

