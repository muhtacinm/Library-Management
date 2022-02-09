#ifndef MAGAZINES_H
#define MAGAZINES_H

#include <iostream>
#include <string>
#include "Library.h"

using namespace std;

class Magazines : public Library
{

    public:
        Magazines();
        Magazines(int i, string s, bool b, int iss);
        void setIssue(int s);
        int getIssue()const;
    private:
        int issue;

};

#endif // MAGAZINES_H
