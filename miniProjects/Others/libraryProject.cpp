#include <iostream>
#include <iomanip>
using namespace std;
struct book_details{string category; int id; string name; bool state; int period; int date;}; //struct creats a new data type
//functions
int show_options(book_details*, int);       //function to ask the user for his choise
int adding(book_details*, int);             //adding function
int removing(book_details*, int);           //removing function
int borrow(book_details* , int);            //borrowing function 
int returning(book_details*, int);          //returning function
int show(book_details*, int);               //show liberary statues              //they all takes parameter {array and its cabacity}
int main()
{
    int capacity;                           //the liberary cabacity.
    cout << "Enter The Capacity: ";
    cin >> capacity;
    book_details *books = new book_details[capacity];   //creating a new array with data type "book_details" , dynamic array.
    show_options(books, capacity);                      // calling the function
}
int show_options(book_details* books, int capacity)
{
    int first_choose;
    cout << "1) Adding a book." << endl;
    cout << "2) Removing a book." << endl;
    cout << "3) Rorrowing a book." << endl;
    cout << "4) Returning a book." << endl;
    cout << "5) Show library statues." << endl;
    cout << "6) Exit." << endl;
    cin >> first_choose;
    switch (first_choose)
    {
        case 1: adding(books, capacity);    break;
        case 2: removing(books, capacity);  break;
        case 3: borrow(books, capacity);    break;
        case 4: returning(books, capacity); break;
        case 5: show(books, capacity);      break;
    }
}
int adding(book_details* books, int capacity)
{
    int num_added;
    cout << "How Many books you want to add: ";
    cin >> num_added;
    for (int i = 0; i < num_added; i++)
    {
        cout << "Enter The Category of book " <<i+1 << ": "<< endl;
        cin >>books[i].category;
        cout << "Enter The Name of book " <<i+1 << ": "<< endl;
        cin >> books[i].name;
        cout << "Enter The ID of book " <<i+1 << ": "<< endl;
        cin >> books[i].id;
        books[i].state = false;
        books[i].period = 0;
        books[i].date = 0;
    }
    cout << "book added.." << endl;
    char x;
    cin.get(x);
    show_options(books, capacity);
}
int removing(book_details* books, int capacity)
{
    int id;
    bool non;
    cout << "Enter The ID of the book you want to remove: ";
    cin >> id;
    for(int i = 0; i<capacity; i++)
    {
        if(books[i].id == id)
        {
            if(books[i].state == false)
            {
                books[i].id = 0;
                cout << "book removed" << endl;
            }
            else {cout << "sorry.. This book is borrowed at the date: " << books[i].date << " for: " << books[i].period << endl;}
            non = true;
            break;
        }
        else {non = false;}
    }
    if (non = false) cout << "Sorry This book is not exist.." << endl;
    char x;
    cin.get(x);
    show_options(books, capacity);
}
int borrow(book_details* books, int capacity)
{
    int id;
    bool non;
    cout << "Enter the ID for the book you want to borrow: ";
    cin >> id;
    for(int i = 0; i<capacity; i++)
    {
        if(books[i].id == id)
        {
            if(books[i].state == false)
            {
                cout << "Enter the date please: " << endl;
                cin >> books[i].date;
                cout << "Enter the period you want to lend the book for: " << endl;
                cin >> books[i].period;
                books[i].state == true;
            }
            else {cout << "sorry.. This book is borrowed at the date: " << books[i].date << " for: " << books[i].period << endl;}
            non = true;
            break;
        }
        else {non = false;}
    }
    if (non = false) cout << "Sorry This book is not exist.." << endl;
    char x;
    cin.get(x);
    show_options(books, capacity);
}
int returning(book_details* books, int capacity)
{
    int id;
    bool non;
    cout << "Enter the ID for the book you want to return: ";
    cin >> id;
    for(int i = 0; i<capacity; i++)
    {
        if(books[i].id == id)
        {
            if(books[i].state == true)
            {
                cout << "The book has been recovered.. " << endl;
                books[i].date = 0;
                books[i].period = 0;
                books[i].state == false;
            }
            else {cout << "This book is not borrowed it's exist here.." << endl;}
            non = true;
            break;
        }
        else {non = false;}
    }
    if (non = false) cout << "Sorry This book is not exist.." << endl;
    char x;
    cin.get(x);
    show_options(books, capacity);
}
int show(book_details* books, int capacity)
{
    int biology=0,maths=0,history=0,chemistry,politics=0;
    int borrowed;
    for(int i=0;i<capacity;i++)
    {
        cout << setw(10) << books[i].category << setw(10) << books[i].id << setw(10) << books[i].name;
        if (books[i].state == false) cout << setw(10) << "Exist";
        else {cout << setw(10) << "Borrowed" << setw(10) << books[i].date << setw(10) << books[i].period << endl; borrowed++;}
        if (books[i].category == "biology") biology++;
        if (books[i].category == "maths") maths++;
        if (books[i].category == "history") history++;
        if (books[i].category == "chemistry") chemistry++;
        if (books[i].category == "politics") politics++;
    }
    cout << "total number of borrowed books in the system:  " << borrowed << endl;
    cout << "total number of biology books in the system:   " << biology << endl;
    cout << "total number of maths books in the system:     " << maths << endl;
    cout << "total number of history books in the system:   " << history << endl;
    cout << "total number of chemistry books in the system: " << chemistry << endl;
    cout << "total number of politics books in the system:  " << politics << endl;
    char x;
    cin.get(x);
    show_options(books, capacity);
}