/**
 * @file StoreUser.cpp
 * @author Aaron Bantay (https://github.com/abant006)
 * 
 * cpp file for the StoreUser class.
 * Defines all the functions (besides the pure virtual ones) declared within the header file for StoreUser
 * 
 * SUGGESTIONS:
 *  - MAKE A CLASS CALLED modInfo FOR ADMIN USERS THAT ASKS ADMIN WHAT INFO THEY WANT TO CHANGE
 *      AND IT WILL USE ANY OF THE CHANGE FUNCTIONS FROM THE BOOKLIST BASED OFF THE INPUT
 * 
 */

#include "../headers/StoreUser.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

// default constructor: open the file containing the BookEntries and push the info into the store's booklist
StoreUser::StoreUser() {
    //create a new ifstream object
    std::ifstream inFile;
    // create a temp string which will store each entry in the file
    std::string tempIn = "";
    // create a temporary vector which will hold tempIn entries before pushing to actual list
    std::vector<std::string> tempVec;

    // open the file
    inFile.open("../BookList.dat");
    // check to see if it did not open the file properly
    if (!inFile) {
        std::cout << "Error! File could not be opened!" << std::endl;
        exit(1); // exits the program
    }

    SkipBOM(inFile);

    // now loop through the file and push everything into tempVec;
    while(getline(inFile, tempIn)) {
        tempVec.push_back(tempIn);
    }

    // now close the file because we are done using it
    inFile.close();

    // loop through tempVec, and store those values into the store's booklist
    for (auto i = 0; i < tempVec.size(); i = i + 5) {
        // converting strings to integers where needed
        int tempID = stoi(tempVec.at(i));
        int tempPub = stoi(tempVec.at(i + 3));
        int tempPrice = stoi(tempVec.at(i + 4));

        // push_back() into list
        bookstoreList.push_back(tempID, tempVec.at(i + 1), tempVec.at(i + 2), tempPub, tempPrice);
        // push_back() the id's into the store's ID list
        IDList.push_back(tempID);
    }
    
}

StoreUser::~StoreUser() {
    // destruct's bookstoreList upon calling the StoreUser's destructor
    bookstoreList.~BookList();
}

// mutators
void StoreUser::filter() {
    std::string response = "";
    // first ask the user if they would like to sort the list in ascending ID number order
    std::cout << "Are you sure you would like to view the book list in ascending order based on ID numbers?: ";

    std::cin >> response;
    while (response != "yes" && response != "no") {
        std::cout << "Please enter a valid response (yes/no): ";
        std::cin >> response;
    }

    if (response == "yes") {
        // call selection sort function on the list to sort it in ascending order
        bookstoreList.selection_sort();
        std::cout << "The list has been filtered!" << std::endl;
    } else {
        std::cout << "The list has not been filtered." << std::endl;
    }
}

// accessors
void StoreUser::output() const {
    // function will print the contents within the bookstoreList
    std::cout << "ID" << std::setw(42) 
        << "Book Name" << std::setw(39)
        << "Author" << std::setw(46)
        << "Publish Date" << std::setw(40)
        << "Price" << std::endl;

    for (auto i = 0; i < 169; i++) {
        std::cout << "-";
    }
    std::cout << std::endl;
    
    // now print the list
    std::cout << bookstoreList;
}

// private helper functions

void StoreUser::SkipBOM(std::ifstream &in) {
    char test[3] = {0};
    in.read(test, 3);
    if ((unsigned char)test[0] == 0xEF && 
        (unsigned char)test[1] == 0xBB && 
        (unsigned char)test[2] == 0xBF)
    {
        return;
    }
    in.seekg(0);
}