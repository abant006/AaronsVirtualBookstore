/**
 * @file BookList.h
 * @author Aaron Bantay (https://github.com/abant006)
 * 
 * Header for the booklist class.
 * This class will declare a custom Linked List used to store each book in the shop
 * 
 */

#include <iostream>

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
        // TODO: INSERT FUNCTIONS

    private:
        BookEntry *head;
        BookEntry *tail;
};