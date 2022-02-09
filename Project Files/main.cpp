#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Library.h"
#include "Books.h"
#include "Journals.h"
#include "Magazines.h"


vector<Books> books;
vector<Journals> journals;
vector<Magazines> magazines;
const string FILENAME = "Catalog.txt";

//function to load from catalog.txt
void loadCatalog(vector<Books> &b,vector<Magazines> &m, vector<Journals> &j){
    ifstream inFile(FILENAME);
    if (inFile.is_open())
    {
        string line;
        while(getline(inFile,line))
        {
            stringstream ss(line);
            string type, name, author, status, id, volume, issue;
            int newid, newissue, newvolume;
            bool bo;


            getline(ss,type,',');
            getline(ss,name,',');
            getline(ss,status,',');
            getline(ss,id,',');

            istringstream(status) >> bo;
            newid=stoi(id);

            if(type == "Book"){
                getline(ss,author,',');
                b.push_back(Books(newid, name, bo, author));

            }
            else if(type == "Magazine"){
                getline(ss,issue,',');
                newissue=stoi(issue);
                m.push_back(Magazines(newid, name, bo, newissue));
            }
            else if(type == "Journal"){
                getline(ss,volume,',');
                newvolume=stoi(volume);
                j.push_back(Journals(newid, name, bo, newvolume));
            }

        }
    }
    else{
        cout << "ERROR!" << endl;
        cout << "Application will not run" << endl;
        cout << "Library Catalog could not be loaded" << endl;
        cout << "Please make sure the file is in right directory" << endl;
        exit (EXIT_FAILURE);
    }
    cout << "Welcome to our Library, Catalog has been loaded from " << FILENAME <<  endl;
    cout << "----------------------------------------------------------------" << endl << endl;

}
//void mycatalog(vector<Books> &b,vector<Magazines> &m, vector<Journals> &j)
//{
//    Books books1(121,"For whom the Bell Tolls", true, "Ernest Hemingway");
//    Books books2(122, "Kurukku", true, "Faustina Bama");
//    Books books3(123, "Animal Farm", true,"George Orwell");
//    Books books4(124, "Allahabad Prasasti", true,"Harisen");
//    Books books5(125, "Principia", true,"Issac Newton");
//
//    b.push_back(books1);
//    b.push_back(books2);
//    b.push_back(books3);
//    b.push_back(books4);
//    b.push_back(books5);
//
//    Magazines magazines1(221, "Sports Illustrated", true, 1970);
//    Magazines magazines2(222, "Vanity Fair", true, 1971);
//    Magazines magazines3(223, "Cosmopolitan", true, 1972);
//    Magazines magazines4(224, "Airliners", true, 1973);
//    Magazines magazines5(225, "Sentimentalist Magazine", true, 1974);
//
//    m.push_back(magazines1);
//    m.push_back(magazines2);
//    m.push_back(magazines3);
//    m.push_back(magazines4);
//    m.push_back(magazines5);
//
//    Journals journals1(331, "Probability Theory and Related Fields", true, 1);
//    Journals journals2(332, "Computer Networks",false, 8);
//    Journals journals3(333, "ICGA Journal", true, 89);
//    Journals journals4(334, "The Imaging Science Journal", true, 34);
//    Journals journals5(345, "Journal of Cases on Information Technology", true, 36);
//
//    j.push_back(journals1);
//    j.push_back(journals2);
//    j.push_back(journals3);
//    j.push_back(journals4);
//    j.push_back(journals5);
//}

//function to save to catalog txt
void saveCatalog(vector<Books> &b,vector<Magazines> &m, vector<Journals> &j)
{
    ofstream savefile;
    savefile.open(FILENAME);

    if (savefile.is_open())
    {
        for (unsigned int i = 0; i < b.size(); i++)
            savefile << "Book" << "," << b[i].getname() << "," << b[i].getStatus() << "," << b[i].getid() << "," << b[i].getAuthorName() << endl;

        for (unsigned int i = 0; i < m.size(); i++)
            savefile << "Magazine" << "," << m[i].getname() << "," << m[i].getStatus() << "," << m[i].getid() << "," << m[i].getIssue() << endl;

        for (unsigned int i = 0; i < j.size(); i++)
            savefile << "Journal" << "," << j[i].getname() << "," << j[i].getStatus() << "," << j[i].getid() << "," << j[i].getVolume() << endl;

        cout << "Data has been saved to " << FILENAME << endl;
    }
    else
        cout << "Error: File not available." << endl;

    cout << endl;
}

//function to search to catalog
void searchCatalog(vector<Books> &b,vector<Magazines> &m, vector<Journals> &j)
{
    string name;
    string author;
    int item;
    char choose;
    bool isfound=false;
    //4 different search options
    cout << "\nEnter 1 to search catalog by name" << endl;
    cout << "Enter 2 to search catalog by Books, Journals, or Magazines" << endl;
    cout << "Enter 3 to search catalog for book by author name" << endl;
    cout << "Enter 4 to display the whole catalog" << endl;
    cout << "Choice: ";
    cin >> item;
    cin.ignore();

    //switch function for each item
    switch(item){
        case 1:
        cout << "\nEnter name of the item" << endl;
        cout << "Choice: ";
        getline(cin,name);
        cin.ignore();
        cout << endl;

        for(unsigned i = 0; i < b.size();i++)
        {
            if (b[i].getname() == name){ //if name matches book name information is printed
            isfound=true;
            cout << "\nItem has been found"  << endl;
            cout << "-------------------" << endl;
            cout << "Name: " <<  b[i].getname()<< endl;
            cout << "Author name: " << b[i].getAuthorName() << endl;
            cout << "ID: " << b[i].getid() << endl;
            cout << "Status: " << (b[i].getStatus() == 1 ? "Checked In" : "Checked Out") << endl << endl;
            }
        }

        for(unsigned i = 0; i < m.size();i++)
        {
            if (m[i].getname() == name){ //if name matches magazine name information is printed
            isfound=true;
            cout << "\nItem has been found"  << endl;
            cout << "-------------------" << endl;
            cout << "Name: " <<  m[i].getname()<< endl;
            cout << "Issue: " << m[i].getIssue() << endl;
            cout << "ID: " << j[i].getid() << endl;
            cout << "Status: " << (j[i].getStatus() == 1 ? "Checked In" : "Checked Out") << endl << endl;
            }

        }

        for(unsigned i = 0; i < j.size();i++)
        {
            if (j[i].getname() == name){ //if name matches journal name information is printed
            isfound=true;
            cout << "\nItem has been found"  << endl;
            cout << "-------------------" << endl;
            cout << "Name: " <<  j[i].getname()<< endl;
            cout << "Volume: " << j[i].getVolume() << endl;
            cout << "ID: " << j[i].getid() << endl;
            cout << "Status: " << (j[i].getStatus() == 1 ? "Checked In" : "Checked Out") << endl << endl;
            }
        }
        if (isfound == false){ //if no name is matched then the statement is printed
            cout << "We do not carry this item.\n" << endl;
        }

    break;
    case 2:
        cout << "\nEnter B for Books" << endl;
        cout << "Enter M for Magazine" << endl;
        cout << "Enter J for Journals" << endl;
        cout << "Choice: ";
        cin >> choose;
        cout << endl;

    //if search by Books all books are returned
    if(choose == 'B')
    {
        for(unsigned i = 0; i < b.size();i++){
            cout << "Item " << i+1 << endl;
            cout << "------" << endl;
            cout << "Name: " <<  b[i].getname()<< endl;
            cout << "Author name: " << b[i].getAuthorName() << endl;
            cout << "ID: " << b[i].getid() << endl;
            cout << "Status: " << (b[i].getStatus() == 1 ? "Checked In" : "Checked Out") << endl << endl;
        }

        }


    //if search by journals all journals are returned
    else if (choose == 'J')
    {
        for(unsigned i = 0; i < j.size();i++){

            cout << "Item " << i+1 << endl;
            cout << "------" << endl;
            cout << "Name: " <<  j[i].getname()<< endl;
            cout << "Volume: " << j[i].getVolume() << endl;
            cout << "ID: " << j[i].getid() << endl;
            cout << "Status: " << (j[i].getStatus() == 1 ? "Checked In" : "Checked Out") << endl << endl;
        }

    }

    //if search by magazines all magazines are returned
    else if (choose == 'M')
    {
        for(unsigned i = 0; i < m.size();i++)
        {
            cout << "Item " << i+1 << endl;
            cout << "------" << endl;
            cout << "Name: " <<  m[i].getname()<< endl;
            cout << "Issue: " << m[i].getIssue() << endl;
            cout << "ID: " << m[i].getid() << endl;
            cout << "Status: " << (m[i].getStatus() == 1 ? "Checked In" : "Checked Out") << endl << endl;
    }
    }
    break;

    case 3:
        cout << "\nEnter name of the author: ";
        getline(cin, author);

        for(unsigned i = 0; i < b.size();i++)
        {
            if (b[i].getAuthorName() == author){ //if the author name matches the name of any book author information
                                                // related to the book is returned
            cout << "\nItem has been found"  << endl;
            cout << "-------------------" << endl;
            cout << "Name: " <<  b[i].getname()<< endl;
            cout << "Author name: " << b[i].getAuthorName() << endl;
            cout << "ID: " << b[i].getid() << endl;
            cout << "Status: " << (b[i].getStatus() == 1 ? "Checked In" : "Checked Out") << endl << endl;
            }
        }
    break;
    case 4:
    //this displays everything in the catalog like books, magazines, and journals
    cout << "\nBOOKS" << endl;
    cout << "-----" << endl;
    for(unsigned i = 0; i < b.size();i++){
            cout << "Name: " <<  b[i].getname()<< endl;
            cout << "Author name: " << b[i].getAuthorName() << endl;
            cout << "ID: " << b[i].getid() << endl;
            cout << "Status: " << (b[i].getStatus() == 1 ? "Checked In" : "Checked Out") << endl << endl;
    }
    cout << "\nJOURNALS" << endl;
    cout << "--------" << endl;
    for(unsigned i = 0; i < j.size();i++){
            cout << "Name: " <<  j[i].getname()<< endl;
            cout << "Volume: " << j[i].getVolume() << endl;
            cout << "ID: " << j[i].getid() << endl;
            cout << "Status: " << (j[i].getStatus() == 1 ? "Checked In" : "Checked Out") << endl << endl;
    }
    cout << "\nMAGAZINES" << endl;
    cout << "---------" << endl;
    for(unsigned i = 0; i < m.size();i++){
            cout << "Name: " <<  m[i].getname()<< endl;
            cout << "Issue: " << m[i].getIssue() << endl;
            cout << "ID: " << m[i].getid() << endl;
            cout << "Status: " << (m[i].getStatus() == 1 ? "Checked In" : "Checked Out") << endl << endl;
    }
    break;
    default:
        cout << "Error: Please try again.";
        searchCatalog(b,m,j);
    }


}

void checkOut(vector<Books> &b,vector<Magazines> &m, vector<Journals> &j)
{
    bool found = false;
    int id;
    cout << "Please input the Id of Item to checkOut." << endl;
    searchCatalog(b,m,j); //to find the Id of an item you have to search the catalog
                         // so the search function is called

    cout << "Enter the id of the item: ";
    cin >> id; //gets the id of book from user

    //each for loop iterates through magazine, books, and journals
    //if an item status of true means it is checked you can check it out
    //if not a message of item is already checked out exists
    for(unsigned i = 0; i < j.size();i++)
    {
        if(id == j[i].getid())
        {
            found = true;
            if (j[i].getStatus() == true)
            {
                j[i].setStatus(false);
                cout << "Item has been successfully checked out." << endl << endl;
            }
            else
                cout << "This Journals is already checked out." << endl << endl;
            break;
        }

    }


    for(unsigned i = 0; i < m.size();i++)
    {
        if(id == m[i].getid())
        {
            found = true;
            if (m[i].getStatus() == true)
            {
                m[i].setStatus(false);
                cout << "Item has been successfully checked out." << endl << endl;
            }
            else
                cout << "Error: This magazine is already checked out" << endl << endl;
            break;
        }

    }


    for(unsigned i = 0; i < b.size();i++)
    {
        if(id == b[i].getid())
        {
            found = true;
            if (b[i].getStatus() == true)
            {
                b[i].setStatus(false);
                cout << "Item has been successfully checked out." << endl << endl;
            }
            else
                cout << "Error: This book is already checked out." << endl << endl;
            break;
        }

    }

    if(!found)
    {
        cout << "Error: Please try again." << endl << endl;
        checkOut(b,m,j);
    }

}

void returnItem(vector<Books> &b,vector<Magazines> &m, vector<Journals> &j)
{
    bool found = false;
    cout << "Please input the Id of Item to return." << endl;
    searchCatalog(b,m,j);//to find the Id of an item you have to search the catalog
                         // so the search function is called

    cout << "Enter the id of the item: ";
    int id;
    cin >> id;

    //each for loop iterates through magazine, books, and journals
    //if an item status of false means it is checked out you can return it
    //if not a message of item is already checked in exists
    for(unsigned i = 0; i < j.size();i++)
    {
        if(id == j[i].getid())
        {
            found = true;
            if (j[i].getStatus() == false)
            {
                j[i].setStatus(true);
                cout << "Item has been successfully returned." << endl << endl;
            }
            else
                cout << "Error: Item is already checked in." << endl << endl;
            break;
        }

    }


    for(unsigned i = 0; i < m.size();i++)
    {
        if(id == m[i].getid())
        {
            found = true;
            if (m[i].getStatus() == false)
            {
                m[i].setStatus(true);
                cout << "Item has been successfully returned." << endl << endl;
            }
            else
                cout << "Error: Item is already checked in." << endl << endl;
            break;
        }

    }


    for(unsigned i = 0; i < b.size();i++)
    {
        if(id == b[i].getid())
        {
            found = true;
            if (b[i].getStatus() == false)
            {
                b[i].setStatus(true);
                cout << "Item has been successfully returned." << endl << endl;
            }
            else
                cout << "Error: Item is already checked in." << endl << endl;
            break;
        }

    }

    if(found == false)
    {
        cout << "SORRY, incorrect id. Please try again" << endl;
        returnItem(b,m,j);
    }

}


void addItem(vector<Books> &b,vector<Magazines> &m, vector<Journals> &j)
{
    int id;
    char option;
    int volume;
    int issue;
    string name;
    string author;
    bool canBeAdded=true;

    //asks user to input what kind of item to add
    cout << "\nWhich type of item do you want to add?" << endl;
    cout << "Enter B to add a Book" << endl;
    cout << "Enter M to add a Magazine" << endl;
    cout << "Enter J to add a Journals" << endl;
    cout << "Choice: ";
    cin >> option;
    cin.ignore();
    cout << endl;

    switch (option)
    {
        //if adding book this option shows
        case 'B':
            cout << "Enter the name of the Book: ";
            getline(cin, name);

            for(unsigned i=0; i< b.size(); i++){
            if(b[i].getname() == name)  //if book name exists  this book cannot be added
                    canBeAdded=false;
            }
            //if canbeadded is still true rest of information is inputted
            if(canBeAdded){
                cout << "Enter the name of the author: ";
                getline(cin, author);
                cout << "Enter the id for this Book: ";
                cin >> id;
                b.push_back(Books(id, name, true, author)); //pushes to book vector
                cout << "\nBook has been added" << endl;
            }
            else
                cout << "\nBook already exists it cannot be added." << endl;
        break;
        case 'M':
            //if adding book this option shows
            cout << "Enter the name of the Magazine: ";
            getline(cin, name);
            cout << "Enter the issue number of the Magazine: ";
            cin >> issue;
            cout << "Enter the id for this Magazine: ";
            cin >> id;
            m.push_back(Magazines(id, name, true, issue)); //pushes to magazine vector
            cout << "\nMagazine has been added" << endl;
            break;

        case 'J':
            //if adding journal this option shows
            cout << "Enter the name of the Journal: ";
            getline(cin, name);
            cout << "Enter the Volume number: ";
            cin >> volume;
            cout << "Enter the id for this Volume: ";
            cin >> id;
            j.push_back(Journals(id, name, true, volume)); //pushes to journal vector
            cout << "\nJournal has been added" << endl;
            break;

        default:
            //default case if invalid option
            //prompts user to add item again
            cout << "Wrong option, Please try again";
            addItem(b,m,j);
            break;
    }
    cout <<endl;
}

//menu function to get choice of user
int menu()
{
    int num;
    cout << "1: Search Catalog" << endl;
    cout << "2: Add a new item" << endl;
    cout << "3: Check Out Item" << endl;
    cout << "4: Return Item" << endl;
    cout << "5: Save Catalog" << endl;
    cout << "6: Exit" << endl;
    cout << endl;
    cout << "Please choice an option above ";
    cout << "Option: ";
    cin >> num;

    return num;
}

int main() {
    int num;
    //upon running the application loadCatalog function is called
    // this sets five books, journals, and magazines to each related vector
    loadCatalog(books, magazines, journals);
    //do while statement that runs until option is not 6
    do{

        try{
            num = menu(); //
            if (cin.fail())
                throw 'a';
            if (num == 1)
                searchCatalog(books, magazines, journals); //option 1 searches catalog

            else if (num == 2)
                addItem(books, magazines, journals); //option 2 adds catalog

            else if (num == 3)
                checkOut(books, magazines, journals); //option 3 checks out item from catalog

            else if (num == 4)
                returnItem(books, magazines, journals); //option 4 returns item from catalog

            else if (num == 5)
                saveCatalog(books, magazines, journals); //option 5 saves catalog to txt file

            else if (num == 6){
                cout << "\nThank you, come again!" << endl;
                return 0;
            }
            else
                throw 1;
        }

        catch(int)
        {
            cout << endl << "Error: please try again." << endl << endl;
        }

        catch(char){
            cout << endl << "Error: please try again." << endl << endl;
            cin.clear();
            cin.ignore();
        }
    }

    while (num != 6);

    cout << endl;
    return 0;
}
