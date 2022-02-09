#include <iostream>
#include <string>

using namespace std;
#include "Magazines.h"


Magazines::Magazines()
{
    issue = 0;
}
Magazines::Magazines(int i, string s, bool b, int is): Library(i, s, b) //id, magazine name, status, issue#
{
    issue = is;
}
void Magazines::setIssue(int is)
{
    issue = is;
}

int Magazines::getIssue() const
{
    return issue;
}

