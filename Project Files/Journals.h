#ifndef JOURNALS_H
#define JOURNALS_H

#include <iostream>
#include <string>
#include "Library.h"

using namespace std;

class Journals: public Library
{
    public:
        Journals();
        Journals(int, string, bool, int);
        void setVolume(int);
        int getVolume()const;
    private:
        int volume;
};

#endif // JOURNALS_H
