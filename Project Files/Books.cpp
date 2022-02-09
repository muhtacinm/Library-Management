#include <iostream>
#include <string>

using namespace std;
#include "Books.h"


Books::Books()
{
    authorName = "no-name";
}
Books::Books(int i, string n, bool stat, string s): Library(i, n, stat)
{
    authorName = s;
}
void Books::setAuthor(string s)
{
    authorName = s;
}
string Books::getAuthorName() const
{
    return authorName;
}
