#include <iostream>
#include <string>

using namespace std;
#include "Journals.h"


Journals::Journals()
{
    volume = 0;
}
Journals::Journals(int i, string s, bool stat, int v): Library(i, s, stat) //id, journal name, status, volume#
{
    volume = v;
}
void Journals::setVolume(int v)
{
    volume = v;
}
int Journals::getVolume() const
{
    return volume;
}
