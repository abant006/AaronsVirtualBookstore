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
    // then seg fault b/c you're trying to access memory that doesn't exist

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

// Finds an entry and changes the name of the book 
void BookList::setName(int tempID, const std::string &tempName) {
    // loop through the list until you find the corresponding ID passed in
    // create a temp BookEntry pointer
    BookEntry *temp = nullptr;
    // calls the linearSearch function on the list and returns the address of the node where a match occurs
    // or it sets temp to nullptr if nothing is found
    temp = this->linearSearch(tempID);

    // if temp is not nullptr, change the name of the entry at the matched address
    // if it is, output an error message
    if (temp != nullptr) {
        temp->bookName = tempName;
        // keep for now?
        std::cout << "Your changes have been made successfully to new name: " << temp->bookName << std::endl;
    } else {
        std::cout << "Error! No match could be found! Name not set!" << std::endl;
    }
}

// Finds an entry and changes the price of the book
void BookList::setPrice(int tempID, int tempPrice) {
    // loop through the list until you find the corresponding ID passed in
    // create a temp BookEntry pointer
    BookEntry *temp = nullptr;
    // calls the linearSearch function on the list and returns the address of the node where a match occurs
    // or it sets temp to nullptr if nothing is found
    temp = this->linearSearch(tempID);

    // if temp is not nullptr, change the name of the entry at the matched address
    // if it is, output an error message
    if (temp != nullptr) {
        temp->price = tempPrice;
        // keep for now?
        std::cout << "Your changes have been made successfully to new price: $" << temp->price << std::endl;
    } else {
        std::cout << "Error! No match could be found! Price not set!" << std::endl;
    }
}

void BookList::setAuthor(int tempID, const std::string &tempName) {
    // loop through the list until you find the corresponding ID passed in
    // create a temp BookEntry pointer
    BookEntry *temp = nullptr;
    // calls the linearSearch function on the list and returns the address of the node where a match occurs
    // or it sets temp to nullptr if nothing is found
    temp = this->linearSearch(tempID);

    // if temp is not nullptr, change the name of the entry at the matched address
    // if it is, output an error message
    if (temp != nullptr) {
        temp->author = tempName;
        // keep for now?
        std::cout << "Your changes have been made successfully to new author: " << temp->author << std::endl;
    } else {
        std::cout << "Error! No match could be found! Author name not set!" << std::endl;
    }
}

void BookList::setPubDate(int tempID, int tempDate) {
    // loop through the list until you find the corresponding ID passed in
    // create a temp BookEntry pointer
    BookEntry *temp = nullptr;
    // calls the linearSearch function on the list and returns the address of the node where a match occurs
    // or it sets temp to nullptr if nothing is found
    temp = this->linearSearch(tempID);

    // if temp is not nullptr, change the name of the entry at the matched address
    // if it is, output an error message
    if (temp != nullptr) {
        temp->publishDate = tempDate;
        // keep for now?
        std::cout << "Your changes have been made successfully to new publish date: " << temp->publishDate << std::endl;
    } else {
        std::cout << "Error! No match could be found! Publish date not set!" << std::endl;
    }
}

void BookList::pop_front() {
    // create a temp pointer
    BookEntry *temp = nullptr;

    // pop only if the list is not empty
    if (head != nullptr) {
        temp = head->next;
        delete head;
        head = temp;

        // if there was only one node in the list prior to deleting it, the list is now empty
        // so set tail to nullptr as well
        if (head == nullptr) {
            tail = nullptr;
        }
    }
}

void BookList::pop_back() {
    // create a temp pointer
    BookEntry *temp = nullptr;
    temp = head;

    // pop only if the list is not empty
    if (head != nullptr) {
        // first condition: if there is only one node in the list
        if (head == tail) {
            delete head;
            // set head and tail to nullptr because the list is now empty
            head = nullptr;
            tail = nullptr;
        } else { // if there's more than one node in the list
            while (temp->next != tail) {
                // loop until temp reaches right before tail
                temp = temp->next;
            }
            // after it has reached delete tail
            delete tail;
            temp->next = nullptr;
            tail = temp;
        }
    }
}

// ACCESSORS

// searches the list to see if there is a bookentry that matches the parameter ID, if so return the name of that book entry
std::string BookList::getName(int tempID) const {
    // create a temp BookEntry Pointer
    BookEntry *temp = nullptr;

    // call the linearSearch helper function, pass in the parameter tempID into the function
    // to see if there is a book entry that exists in the list
    // if there is, store the address of the book entry in temp (point temp to the book entry)
    temp = this->linearSearch(tempID);

    // if temp != nullptr, then there is a matching bookentry
    if (temp != nullptr) {
        return temp->bookName;
    } else { // if no match found
        return "No match! Name could not be found!";
    }
}

// searches the list to see if there is a bookentry that matches the parameter ID, if so return the price of that book entry
int BookList::getPrice(int tempID) const {
    // create a temp BookEntry Pointer
    BookEntry *temp = nullptr;

    // call the linearSearch helper function, pass in the parameter tempID into the function
    // to see if there is a book entry that exists in the list
    // if there is, store the address of the book entry in temp (point temp to the book entry)
    temp = this->linearSearch(tempID);

    // if temp != nullptr, then there is a matching bookentry
    if (temp != nullptr) {
        return temp->price;
    } else { // if no match found return -1
        return -1;
    }
}

// searches the list to see if there is a bookentry that matches the parameter ID, if so return the author of that book entry
std::string BookList::getAuthor(int tempID) const {
    // create a temp BookEntry Pointer
    BookEntry *temp = nullptr;

    // call the linearSearch helper function, pass in the parameter tempID into the function
    // to see if there is a book entry that exists in the list
    // if there is, store the address of the book entry in temp (point temp to the book entry)
    temp = this->linearSearch(tempID);

    // if temp != nullptr, then there is a matching bookentry
    if (temp != nullptr) {
        return temp->author;
    } else { // if no match found
        return "No match! Author could not be found!";
    }
}

// searches the list to see if there is a bookentry that matches the parameter ID, if so return the publish date of that book entry
int BookList::getPubDate(int tempID) const {
    // create a temp BookEntry Pointer
    BookEntry *temp = nullptr;

    // call the linearSearch helper function, pass in the parameter tempID into the function
    // to see if there is a book entry that exists in the list
    // if there is, store the address of the book entry in temp (point temp to the book entry)
    temp = this->linearSearch(tempID);

    // if temp != nullptr, then there is a matching bookentry
    if (temp != nullptr) {
        return temp->publishDate;
    } else { // if no match found return -1
        return -1;
    }
}

std::ostream & operator<<(std::ostream &o, const BookList &list) {
    // create a temp BookEntry pointer that points to the beginning of the list
    BookEntry *temp = nullptr;
    // point it to the list's head (remember not technically a member function, so the list is passed as a parameter)
    temp = list.head;

    // now loop through the list as long as it's not empty
    if (temp != nullptr) {
        while (temp != nullptr) {
            // print each Entry's info in a formatted way before going to the next entry
            o << temp->id << "\t\t\t" << temp->bookName << "\t\t\t" << temp->author << "\t\t\t" << temp->publishDate << "\t\t\t" << "$" << temp->price << std::endl;

            // move the temp pointer to the next entry
            temp = temp->next;
        }
    }

    return o;
}

// private helper functions

// linear search performs a linear search on the lists trying to find an ID which
// matches the one passed as a parameter. If there's a match, return the address of that entry node
BookEntry * BookList::linearSearch(int tempID) const {
    BookEntry *temp = nullptr;
    temp = this->head;

    // loop only if the list is NOT empty
    if (temp != nullptr) {
        while (temp != nullptr) {
            // if any id's in the list matches the one passed as a parameter,
            // return the address of the entry where the id was matched
            if (temp->id == tempID) {
                return temp;
            } else { // if no match found, go to the next entry
                temp = temp->next;
            }
        }
    } 

    // if the function reaches here, that means that temp has now become nullptr
    // or the list is empty, so just return nullptr
    return nullptr;
 
}