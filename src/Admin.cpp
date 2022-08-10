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

// inline constructor for admin class
// since this class is inheriting from StoreUser, we must first call StoreUser's constructor to 
// initialize all the inherited data members
// then we can initialize admin's data members UserName and Password to something predetermined (not something a user will be able to set)
// so, the username and password has "already been set" by the time an admin want's to login
Admin::Admin() : StoreUser(), UserName("StoreAdmin112"), Password("Password123") {}

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