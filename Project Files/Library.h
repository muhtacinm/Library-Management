#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <string>

using namespace std;

class Library{

    public:
        Library();
        Library(int, string, bool);   //id, name, status    base clase constructor
        void setid(int);
        int getid()const;
        void setname(string);
        string getname()const;
        void setStatus(bool);
        bool getStatus()const;
    private:
        int id;
        string name;
        bool status;
};

#endif // LIBRARY_H
