/**
 * @file BookList.cpp
 * @author Aaron Bantay (https://github.com/abant006)
 * 
 * cpp file for the BookList Linked List.
 * Defines the functions declared in the class's interface
 * 
 */

#include "../headers/BookList.h"
#include <iostream>

// destructor (Just have it call the clear function)
BookList::~BookList() {
    // honestly we don't even need this-> or BookList:: here
    // this-> just makes the implicit parameter apparent; the list that's being destructed is calling clear() on it
    // BookList:: just shows that clear() is a function belonging to the BookList class
    this->BookList::clear();
}
// copy constructor
BookList::BookList(const BookList &cpy) {
    // TODO!!!
}
// assignment operator
void BookList::operator=(const BookList &cpy) {
    // TODO!!
}

void BookList::push_back(int tempID, const std::string &tempBookName, const std::string &tempAuthor, int tempPub, int tempPrice) {
    // first create a BookEntry Node pointer, and a bookentry in the heap
    BookEntry *temp = new BookEntry(tempID, tempBookName, tempAuthor, tempPub, tempPrice);

    // if list is empty point the booklist's head AND tail to it
    if (this->head == nullptr) {
        this->head = temp;
        this->tail = temp;
    } else { // if list is not empty
        this->tail->next = temp;
        this->tail = temp;
    }
}

void BookList::push_front(int tempID, const std::string &tempBookName, const std::string &tempAuthor, int tempPub, int tempPrice) {
    // create a BookEntry node pointer, and a BookEntry in the heap
    // creating a BookEntry in heap
    BookEntry *temp = new BookEntry(tempID, tempBookName, tempAuthor, tempPub, tempPrice);

    // if list is empty then point the booklist's head AND tail to the new entry
    if (this->head == nullptr) {
        this->head = temp;
        this->tail = temp;
    } else { // if the list is not empty
        temp->next = this->head;
        this->head = temp;
    }
}

// check to see if this works with empty/one node in the list
void BookList::clear() {
    // will remove each node one by one until no more remain
    // first make sure the list is NOT empty, if it is, 
    //then seg fault b/c you're trying to access memory that doesn't exist

    // make two temp pointers, one will point to the head, and the other to the previous one
    BookEntry *temp1 = nullptr;
    BookEntry *temp2 = nullptr;

    // if head pointer is pointing to nullptr, then list is empty
    if (this->head != nullptr) {
        temp1 = head->next;
        temp2 = head;
        // now loop through the linked list
        while (temp1 != nullptr) {
            delete temp2;
            temp2 = temp1;
            temp1 = temp1->next;
        }

        // now delete the last node
        delete temp2;

        // set head and tail to nullptr
        this->head = nullptr;
        this->tail = nullptr;
    }
}

ostream & operator<<(ostream &o, const BookList &list) {

}