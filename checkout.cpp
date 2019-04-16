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

//Function 1:helper
int checkUser(int person, vector<Person*> &card) {
  for (int x = 0; x < card.size(); x++)
  {
    if (card.at(x)->getId()==person)
    {
      if(card.at(x)->isActive() == false)
      {
        cout << "Card is not active" << endl;
        return 1;
      }
      else
      {
        cout << "Cardholder: " << card.at(x)->fullName() << endl;
        return 2;
      }
    }
    else if (card.size() - 1==x)
    {
      cout << "Card ID not found" << endl;
      return 1;
    }
  }
}

//Function 1:Helper
int checkBook(int inputBook, vector<Book*> &myBooks) {
  for(int i = 0; i < myBooks.size(); i++)
  {
    if(myBooks.at(i)->getId()==inputBook)
    {
      Person *temp = myBooks.at(i)->getPersonPtr();
      if(temp == 0)
      {
        cout << "Title: " << myBooks.at(i)->getTitle() << endl;
        return 2;
      }
      else
      {
        cout << "Book is already checked out!" << endl;
        return 1;
      }
    }
    else if (myBooks.size() - 1==i)
    {
      cout << "Book ID not found" << endl;
      return 1;
    }
  }
}

//Function 1:
void BookCheckout(vector<Book*> myBooks, vector<Person*> &card) {
  int id = 0;
  int inputBook = 0;
  int person = 0;
  int book = 0;
  cout << "Please enter the card ID: ";
  cin >> id;
  person = checkUser(id, card);
  switch(person)
  {
    case 1:
    return;
    case 2:
    cout << "Please enter the book ID: ";
    cin >> inputBook;
    book = checkBook(inputBook, myBooks);
    switch(book)
    {
      case 1:
      return;
      case 2:
      for(int x = 0; x < myBooks.size(); x++)
      {
        if(inputBook == myBooks.at(x)->getId())
        {
          for(int j = 0; j < card.size(); j++)
          {
            if(id == card.at(j)->getId())
            {
              myBooks.at(x)->setPersonPtr(card.at(j));
              cout << "Rental complete" << endl;
              return;
            }
          }
        }
      }
      default:
      return;
    }
    return;
    default:
    break;
  }
}

//Function 2:
void BookReturn(vector<Book *> & book)
{
  int j = 1;
  int bookid;
  cout << "Please enter the book ID to return: ";
  cin>> bookid;
  for (int i = 0; i < book.size(); i++)
  {
    if (book.at(i)->getId() == bookid)
    {
      j++;
      cout << "Title: " << book.at(i)->getTitle();
      cout << endl;
      book.at(i)->setPersonPtr(nullptr);
      cout << "Return Completed";
      break;
    }
  }
  if(j == 1)
  {
    cout << "Book ID not found";
  }
}

//Funtion 3
void allBooks(vector<Book *> &book)
{
  for (int i = 0; i < book.size(); i++)
  {
    if (book.at(i)->getPersonPtr()==nullptr)
    {
      cout << "Book ID: " << book.at(i)->getId();
      cout << endl;
      cout << "Title: " << book.at(i)->getTitle();
      cout << endl;
      cout << "Author: "<<book.at(i)->getAuthor();
      cout << endl;
      cout << "Category: " << book.at(i)->getCategory();
      cout << endl;
      cout << endl;
    }
    else if (i== book.size()-1)
    {
      if (book.at(i)->getPersonPtr() != nullptr)
      {
        return;
      }
      else
      {
        cout << "No available books";
        return;
      }
    }
  }
}

//Function 4
void allRentals(vector<Book *> &book, vector<Person*> &card)
{
  int count = 0;
  for (size_t x = 0; x < card.size(); x++)
  {
    for (int i = 0; i < book.size(); i++)
    {
      if (book.at(i)->getPersonPtr()==nullptr)
      {
        cout << "Book ID: " << book.at(i)->getId();
        cout << endl;
        cout << "Title: " << book.at(i)->getTitle();
        cout << endl;
        cout << "Author: "<<book.at(i)->getAuthor();
        cout << endl;
        cout << "Cardholder: "<<card.at(x)->fullName() << endl;
        cout << "Card ID: " << card.at(x)->getId();
        cout << endl;
        cout << endl;
        count++;
      }
    }
  }
  if (count == 0)
  {
    cout << "No outstanding rentals"<< endl;
  }
}

//Function 5
void rentalCarholders(vector<Book *> &book, vector<Person*> &card)
{
  int counter = 1;
  int person;
  int id;
  cout << "Please enter the card ID: ";
  cin >> id;
  person = checkUser(id, card);
  switch(person)
  {
    case 1:
    return;
    case 2:
    for (int x = 0; x < book.size(); x++)
    {
      if (book.at(x)->getPersonPtr()!=nullptr)
      {
        Person *temp = book.at(x)->getPersonPtr();
        if (temp->getId() == id)
        {
          cout << endl;
          cout << "Book ID: " << book.at(x)->getId();
          cout << endl;
          cout << "Title: " << book.at(x)->getTitle();
          cout << endl;
          cout << "Author: "<<book.at(x)->getAuthor();
          cout << endl;
          counter++;
        }
      }
    }
    if (counter == 1) {
      cout << "No books currently checked out";
    }
  }
}

//Function 6
int openCard(vector<Person *> & card, int nextID)
{
  string firstname;
  string lastname;
  cout << "Please enter the first name: ";
  cin >> firstname;
  cout << "Please enter the last name: ";\
  cin >> lastname;
  for (int i = 0; i < card.size(); i++)
  {
    if (firstname == card.at(i)->getFirstName() && lastname == card.at(i)->getLastName())
    {
      card.at(i)->setActive(1);
      cout << "Card ID " << card.at(i)->getId() << " active" << endl;
      cout << "Cardholder: " << card.at(i)->getFirstName() << " " << card.at(i)->getLastName() << endl;
      return nextID;
    }
    else if(i == card.size()-1)
    {
      card.push_back(new Person(nextID,1,firstname,lastname));
      cout << "Card ID " << card.at(i+1)->getId() << " active" << endl;
      cout << "Cardholder: " << card.at(i+1)->getFirstName() << " " << card.at(i+1)->getLastName() << endl;
      return nextID +1;
    }
  }
}

//Function 7
void closeCard(vector<Person *> & card)
{
  int counter = 1;
  char choice;
  int id;
  cout << "Please enter the card ID: ";
  cin >> id;
  for (int i = 0; i < card.size(); i++)
  {
    if (id == card.at(i)->getId())
    {
      if (card.at(i)->isActive()==true)
      {
        cout << endl;
        cout << "Cardholder: " << card.at(i)->getFirstName() << " " << card.at(i)->getLastName() << endl;
        cout << "Are you sure you want to deactivate card (y/n)? ";
        cin >> choice;
        if (choice == 'y')
        {
          cout << endl;
          card.at(i)->setActive(0);
          cout << "Card ID deactivated";
          counter++;
          break;
        }
        else if (choice == 'n')
        {
          counter*=4;
          cout << "Bye";
          break;
        }
      }
      else if (card.at(i)->isActive()==false)
      {
        counter=0;
        cout << "Cardholder: " << card.at(i)->getFirstName() << " " << card.at(i)->getLastName() << endl;
        cout << "Card ID is already inactive";
        break;
      }
    }
  }
  if (counter == 1)
  {
    cout << endl;
    cout << "Card ID not found";
  }
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
  in.close();
  return;
}

int readPersons(vector<Person *> & card)
{
  int greatest = 0;
  ifstream in;
  in.open("persons.txt");
  int id;
  bool checkout;
  string firstname;
  string lastname;
  string name;
  while (in>>id>>checkout>>firstname>>lastname)
  {
    card.push_back(new Person(id,checkout,firstname,lastname));
  }
  in.close();

  for (int i = 0; i < card.size(); i++)
  {
    if (greatest < card.at(i)->getId())
    {
      greatest = card.at(i)->getId();
    }
  }

  return greatest+1;

}

void readRentals(vector<Book *> & myBooks, vector<Person *> card)
{
  ifstream in;

  int bookid, personid;
  in.open("rentals.txt");
  while (in>>bookid>>personid)
  {
    for (int i = 0; i < myBooks.size(); i++)
    {
      if (bookid == myBooks.at(i)->getId())
      {
        for (int x = 0; x < card.size(); x++)
        {
          if (personid == card.at(x)->getId())
          {
            myBooks.at(i)->setPersonPtr(card.at(x));
          }
        }
      }
    }
  }
  in.close();
  return;
}

//Function 8
void update(vector<Book*>  &myBooks, vector<Person*> &myCardHolders)
{
  cout << myCardHolders.size();
  ofstream out;
  out.open("persons.txt");

  for(int i = 0; i < myCardHolders.size(); i++)
  {
    out << myCardHolders.at(i)->getId() << " ";
    if(myCardHolders.at(i)->isActive() == true)
    {
      out << "1" << " " << myCardHolders.at(i)->fullName() << endl;
    }
    else
    {
      out << "0" << " " << myCardHolders.at(i)->fullName() << endl;
    }
  }
  out.close();

  out.open("rentals.txt");
  for(int i = 0; i < myBooks.size(); i++)
  {
    if(myBooks.at(i)->getPersonPtr() != nullptr)
    {
      Person *temp = myBooks.at(i)->getPersonPtr();
      out << myBooks.at(i)->getId() << " " << temp->getId() << endl;
    }
  }
  out.close();
}


int main()
{
  int nextID = 0;
  vector<Book *> books;
  vector<Person *> cardholders;
  //cout << id;
  readBooks(books);
  nextID=readPersons(cardholders);
  readRentals(books,cardholders);
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
      BookCheckout(books,cardholders);
      break;

      case 2:
      // Book return
      BookReturn(books);
      break;

      case 3:
      // View all available books
      allBooks(books);
      break;

      case 4:
      // View all outstanding rentals
      allRentals(books,cardholders);
      break;

      case 5:
      // View outstanding rentals for a cardholder
      rentalCarholders(books,cardholders);
      break;

      case 6:
      // Open new library card
      nextID = openCard(cardholders, nextID);

      break;

      case 7:
      // Close library card
      closeCard(cardholders);
      break;

      case 8:
      // Must update records in files here before exiting the program
      update(books,cardholders);
      break;

      default:
      cout << "Invalid entry" << endl;
      break;
    }
    cout << endl;
  } while(choice != 8);
  return 0;
}
