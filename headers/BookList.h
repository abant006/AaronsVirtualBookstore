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
        void push_back();
        void push_front();
        void remove();
        void selection_sort();
        void insert_ordered();
        // accessors
        bool isDuplicate() const;


    private:
        BookEntry *head;
        BookEntry *tail;
};

#endif //__BOOKLIST_H__