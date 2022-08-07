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
#include <ostream>
#include <string>

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
    BookEntry(int pID, const std::string &pBookName, const std::string &pAuthor, int pPub, int pPrice) 
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
        void push_back(int, const std::string & , const std::string & , int , int );
        void push_front(int, const std::string & , const std::string & , int , int );
        void clear();
        void setName(int tempID, const std::string &tempName);
        void setPrice(int tempID, int tempPrice);
        void setAuthor(int tempID, const std::string &tempName);
        void setPubDate(int tempID, int tempDate);
        void pop_back();
        void pop_front();
        void remove(int tempID); // via ID
        // void selection_sort();
        
        // accessors
        std::string getName(int tempID) const; // think about & with return type here
        int getPrice(int tempID) const;
        std::string getAuthor(int tempID) const;
        int getPubDate(int tempID) const;
        

        // output operator somewhere for printing the list
        friend std::ostream & operator<<(std::ostream &o, const BookList &list);

    private:
        BookEntry *head;
        BookEntry *tail;

        // private helper functions

        // make this const, we don't want it to modify the list
        BookEntry * linearSearch(int tempID) const; // returns a BookEntry pointer (an address)

};

#endif //__BOOKLIST_H__