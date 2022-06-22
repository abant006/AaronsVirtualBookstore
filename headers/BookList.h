/**
 * @file BookList.h
 * @author Aaron Bantay (https://github.com/abant006)
 * 
 * Header for the booklist class.
 * This class will declare a custom Linked List used to store each book in the shop
 * 
 */
#ifndef __BOOKLIST_H__
#define __BOOKLIST_H__


#include <iostream>
#include <string>
#include <vector>

// each node will be a book entry
// each entry in the shop will have the book's ID number, name, author, publish date, price, and a BookEntry pointer storing the address of the next entry in the shop.
struct BookEntry {
    int id;
    std::string bookName;
    std::string author;
    int publishDate;
    int price;
    BookEntry *next;

    // inline constructor
    BookEntry(int pID, std::string pBookName, std::string pAuthor, int pPub, int pPrice) 
    : id(pID), bookName(pBookName), author(pAuthor), publishDate(pPub), price(pPrice), next(nullptr) {}
};

class BookList {
    public:
        // constructors / destructors
        BookList() : head(nullptr), tail(nullptr) {} // inline
        BookList(const BookList &cpy); // copy constructor (might need const, idk)
        ~BookList();
        // assignment operator
        void operator=(const BookList &cpy);
        // mutators
        void push_back(const std::string & , const std::string & , int , int );
        void push_front(const std::string & , const std::string & , int , int );
        void remove(int );
        void remove(const std::string & );
        void selection_sort();
        void insert_ordered(const std::string & , const std::string & , int , int );
        // accessors
        // note: SEE PRIVATE HELPER FUNCTION BELOW
        bool in(int , const std::string & ) const; // is two parameters here the right move? would 2 in() functions be better?

        // output operator somewhere for printing the list

        // adds integer ID values to the IDList vector (meant for classes using this one, that are opening/reading from text file)
        void initIDList(int );

    private:
        BookEntry *head;
        BookEntry *tail;

        // private helper function that scans the vector to see if the ID has already been added before creating a node with a unique ID
        // bool in(int );

        // temporary measure: vector that stores all the ID's to check if one has been used already
        // might be a bad solution but just adding for now
        std::vector<int> IDList;
};

#endif //__BOOKLIST_H__