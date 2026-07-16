#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Book
{
private:
    int bookId;
    string title;
    string author;
    bool issued;
public:
    void addBook()
    {
        cout << "\nEnter Book ID : ";
        cin >> bookId;
        cin.ignore();
        cout << "Enter Book Title : ";
        getline(cin, title);
        cout << "Enter Author Name : ";
        getline(cin, author);
        issued = false;
    }
    void displayBook()
    {
        cout << "\n-----------------------------------";
        cout << "\nBook ID      : " << bookId;
        cout << "\nTitle        : " << title;
        cout << "\nAuthor       : " << author;
        if(issued)
            cout << "\nStatus       : Issued";
        else
            cout << "\nStatus       : Available";

        cout << "\n-----------------------------------";
    }
    void issueBook()
    {
        if(issued)
        {
            cout << "\nBook is already issued.";
        }
        else
        {
            issued = true;
            cout << "\nBook Issued Successfully.";
        }
    }
    void returnBook()
    {
        if(!issued)
        {
            cout << "\nBook is already available.";
        }
        else
        {
            issued = false;
            cout << "\nBook Returned Successfully.";
        }
    }
    void searchBook()
    {
        string search;
        cin.ignore();
        cout << "\nEnter Book Title : ";
        getline(cin, search);
        if(search == title)
        {
            displayBook();
        }
        else
        {
            cout << "\nBook Not Found.";
        }
    }
    void saveBook()
    {
        ofstream file("books.txt", ios::app);
        file << bookId << endl;
        file << title << endl;
        file << author << endl;
        file << issued << endl;
        file.close();
    }
};
int main()
{
    Book b;
    int choice;
    do
    {
        cout << "\n====================================";
        cout << "\n LIBRARY MANAGEMENT SYSTEM";
        cout << "\n====================================";
        cout << "\n1. Add Book";
        cout << "\n2. Display Book";
        cout << "\n3. Search Book";
        cout << "\n4. Issue Book";
        cout << "\n5. Return Book";
        cout << "\n6. Exit";
        cout << "\n\nEnter Choice : ";
        cin >> choice;
        switch(choice)
        {
            case 1:
                b.addBook();
                b.saveBook();
                cout << "\nBook Added Successfully.\n";
                break;
            case 2:
                b.displayBook();
                break;
            case 3:
                b.searchBook();
                break;
            case 4:
                b.issueBook();
                break;
            case 5:
                b.returnBook();
                break;
            case 6:
                cout << "\nThank You!";
                break;
            default:
                cout << "\nInvalid Choice!";
        }
    }while(choice != 6);
    return 0;
}
