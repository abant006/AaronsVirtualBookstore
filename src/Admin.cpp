/**
 * @file Admin.cpp
 * @author Aaron Bantay (https://github.com/abant006)
 * 
 * The cpp file for Admin.h which defines each function declared in the interface
 * 
 */

#include "../headers/Admin.h"
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <random>


// inline constructor for admin class
// since this class is inheriting from StoreUser, we must first call StoreUser's constructor to 
// initialize all the inherited data members
// then we can initialize admin's data members UserName and Password to something predetermined (not something a user will be able to set)
// so, the username and password has "already been set" by the time an admin want's to login
Admin::Admin() : StoreUser(), UserName("StoreAdmin112"), Password("Password123") {}

// mutators
void Admin::addEntry(const std::string &tempName, const std::string &tempAuthor, int tempPub, int tempPrice) {
    int tempID = 0;

    // using the random() function to get a random ID number in the specified range
    tempID = random();

    // keep looping until we get a tempID that's not in the list
    while (isDuplicate(tempID) != false) {
        tempID = random();
    }

    // if it reaches here, then that means the tempID is NOT in the list
    // with all the values we have now, push it back into the list
    IDList.push_back(tempID);
    bookstoreList.push_back(tempID, tempName, tempAuthor, tempPub, tempPrice);
}

void Admin::removeEntry(int tempID) {
    // just call the remove() function on the bookstoreList
    bookstoreList.remove(tempID);
}

// the change info mutators

// changes the name of a book entry
void Admin::changeName(int tempID, const std::string &newName) {
    std::string response = "";
    
    // no need to check to see if the ID exists within the list (dont need to call exists())
    // becase setName function will already check to see if the ID exists
    std::cout << "Are you sure you would like to change the book's name to " << newName << "?: ";
    std::cin >> response;
    while (response != "yes" && response != "no") {
        std::cout << "Please enter a valid response (yes/no): ";
        std::cin >> response;
    }

    // check for conditions
    if (response == "yes") {
        bookstoreList.setName(tempID, newName);
    } else {
        std::cout << "The book name will not be changed." << std::endl;
    }
}

// changes the name of the book's author
void Admin::changeAuthor(int tempID, const std::string &newAuthor) {
    std::string response = "";
    
    // no need to check to see if the ID exists within the list (dont need to call exists())
    // becase setName function will already check to see if the ID exists
    std::cout << "Are you sure you would like to change the author's name to " << newAuthor << "?: ";
    std::cin >> response;
    while (response != "yes" && response != "no") {
        std::cout << "Please enter a valid response (yes/no): ";
        std::cin >> response;
    }

    // check for conditions
    if (response == "yes") {
        bookstoreList.setAuthor(tempID, newAuthor);
    } else {
        std::cout << "The author's name will not be changed." << std::endl;
    }
}

void Admin::changePubDate(int tempID, int newDate) {
    std::string response = "";
    
    // no need to check to see if the ID exists within the list (dont need to call exists())
    // becase setName function will already check to see if the ID exists
    std::cout << "Are you sure you would like to change the book's publish date to " << newDate << "?: ";
    std::cin >> response;
    while (response != "yes" && response != "no") {
        std::cout << "Please enter a valid response (yes/no): ";
        std::cin >> response;
    }

    // check for conditions
    if (response == "yes") {
        bookstoreList.setPubDate(tempID, newDate);
    } else {
        std::cout << "The book's publish date will not be changed." << std::endl;
    }
}

void Admin::changePrice(int tempID, int newPrice) {
    std::string response = "";
    
    // no need to check to see if the ID exists within the list (dont need to call exists())
    // becase setName function will already check to see if the ID exists
    std::cout << "Are you sure you would like to change the book's price to $" << newPrice << "?: ";
    std::cin >> response;
    while (response != "yes" && response != "no") {
        std::cout << "Please enter a valid response (yes/no): ";
        std::cin >> response;
    }

    // check for conditions
    if (response == "yes") {
        bookstoreList.setPrice(tempID, newPrice);
    } else {
        std::cout << "The book's price will not be changed." << std::endl;
    }
}

// the overriden purchase function
// this function is unique to the ADMIN class because it automatically applies a 50% discount on the purchase
void Admin::purchase(int tempID) {
    // this will call the bookList's get functions to confirm with the user
    std::string response = "";
    // discount will be made constant. We dont want this to change under any cirumstance for admins
    const int discount = 2;

    // first see if the book exists within the list
    if (bookstoreList.exists(tempID) == false) {
        std::cout << "No purchase could be made because there exists no book in the store with a matching ID." << std::endl;
    } else { // if it does exist
        std::cout << "Because you are an Admin every purchase you make will have a 50\% discount." << std::endl;
        std::cout << "Do you want to purchase the book " << bookstoreList.getName(tempID) << " for a total of $" << (bookstoreList.getPrice(tempID) / discount) << "?: ";
        std::cin >> response;
        while (response != "yes" && response != "no") {
            std::cout << "Please enter a valid response (yes/no): ";
            std::cin >> response;
        }

        // check for conditions
        if (response == "yes") {
            bookstoreList.remove(tempID);
            std::cout << "The book has successfully been purchased! Thank you for your patronage." << std::endl;
        } else {
            std::cout << "The book will not be purchased." << std::endl;
        }
    }
}

// accessors
// this function will couple together with a helper function in main that loops for at most 3 times if the user fails to enter the correct username and password
bool Admin::verification(const std::string &tempUser, const std::string &tempPass) const {
    if (tempUser == UserName && tempPass == Password) {
        return true;
    } else {
        return false;
    }
}

// this function is only accessible to Admin class (meaning base class and other subclasses cant use it)
void Admin::displayIDList() {
    // loop through the array displaying each member out in a comma seperated list
    for (auto i = 0; i < IDList.size(); i++) {
        if (i == IDList.size() - 1) {
            std::cout << IDList.at(i) << std::endl;
        } else {
            std::cout << IDList.at(i) << ", ";
        }
    }
}

// private helper function
bool Admin::isDuplicate(int keyID) const{
    // loop through the IDList and if there is any ID's that matches the key then remove false
    for (auto i = 0; i < IDList.size(); i++) {
        if (keyID == IDList.at(i)) {
            return true;
        }
    }

    // if the loop exits, that means there's no duplicate ID
    return false;
}

int Admin::random() {
    int min = 850000;
    int max = 860000;
    int range = max - min + 1;
    static bool first = true;

    if (first) {
        srand(time(NULL)); 
        first = false;
    }

    // generates a random number
    return rand() % range + min;
}