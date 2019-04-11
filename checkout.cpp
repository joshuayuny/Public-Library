// Name
// Section #
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "person.cpp"
#include "book.cpp"
using namespace std;


void printMenu() {
    cout << "----------Library Book Rental System----------" << endl;
    cout << "1.  Book checkout" << endl;
    cout << "2.  Book return" << endl;
    cout << "3.  View all available books" << endl;
    cout << "4.  View all outstanding rentals" << endl;
    cout << "5.  View outstanding rentals for a cardholder" << endl;
    cout << "6.  Open new library card" << endl;
    cout << "7.  Close library card" << endl;
    cout << "8.  Exit system" << endl;
    cout << "Please enter a choice: ";
}



void BookCheckout(vector<Book *> & book, vector<Person *> & card)
{
  int cardid;
  int bookid;
  bool cardids = false;
  bool bookids = false;
  cout << "What is your ID: ";
  cin >> cardid;
  for (int i = 0; i < card.size(); i++)
  {
    if (cardid == card.at(i)->getId())
    {
      cardids = true;
      cout << "What is your bookid: ";
      cin >> bookid;
      for (int i = 0; i < book.size(); i++)
      {
        if (bookid == book.at(i)->getId())
        {
          bookids = true;
          book.at(i)->setPersonPtr(card.at(i));
        }
      }
    }
  }
}

void BookReturn(vector<Book *> &book)
{
  int bookid;
  cout << "Please enter the book ID to return: ";
  cin>> bookid;
  for (int i = 0; i < book.size(); i++)
  {
    if (book.at(i)->getId() == bookid)
    {
      book.at(i)->setPersonPtr(nullptr);
    }
  }
}

void allBooks(vector<Book *> &book)
{

}

void allRentals()
{

}
void rentalCarholders()
{

}
void closeCard()
{

}

void readBooks(vector<Book *> & myBooks)
{
  ifstream in;
  in.open("books.txt");
  int id;
  string title;
  string author;
  string type;
  string garbage;
  while(in>>id)
  {
    getline(in,garbage);
    getline(in,title);
    getline(in,author);
    getline(in,type);
    myBooks.push_back(new Book(id,title,author,type));
  }
}

int readPersons(vector<Person *> & myCardholders)
{
  ifstream in;
  in.open("persons.txt");
  int id;
  bool checkout;
  string firstname;
  string lastname;
  string name;
  while (in>>id>>checkout>>firstname>>lastname)
  {
    myCardholders.push_back(new Person(id,checkout,firstname,lastname));
  }
}

void readRentals(vector<Book *> & myBooks, vector<Person *> myCardholders)
{
  ifstream in;
  in.open("rentals.txt");
  int bookid, personid;
  while (in>>bookid>>personid)
  {
    for (int i = 0; i < myBooks.size(); i++)
    {
      if (bookid == myBooks.at(i)->getId())
      {
        for (int x = 0; x < myCardholders.size(); x++)
        {
          if (personid == myCardholders.at(x)->getId())
          {
            //myBooks.at(i)->getId() = setPersonPtr(*myCardholders.at(i));
            myBooks[i]->setPersonPtr(myCardholders.at(x));
          }
        }
      }
    }
  }
}

void openCard(vector<Person *> & myCardholders, int nextID)
{

}

Book * searchBook(vector<Book *> myBooks, int id)
{
    return nullptr;
}

int main()
{
    vector<Book *> books;
    vector<Person *> cardholders;

    int choice;
    do
    {
        // If you use cin anywhere, don't forget that you have to handle the <ENTER> key that
        // the user pressed when entering a menu option. This is still in the input stream.
        printMenu();
        cin >> choice;
        switch(choice)
        {
            case 1:
                // Book checkout
                break;

            case 2:
                // Book return
                break;

            case 3:
                // View all available books
                break;

            case 4:
                // View all outstanding rentals
                break;

            case 5:
                // View outstanding rentals for a cardholder
                break;

            case 6:
                // Open new library card
                break;

            case 7:
                // Close library card
                break;

            case 8:
                // Must update records in files here before exiting the program
                break;

            default:
                cout << "Invalid entry" << endl;
                break;
        }
        cout << endl;
   } while(choice != 8);
      return 0;
}
