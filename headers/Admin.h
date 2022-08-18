/**
 * @file Admin.h
 * @author Aaron Bantay (https://github.com/abant006)
 * 
 * This is the admin clas (subclass) to the StoreUser class. This will act as an admin user
 * where they can do the same thing as a store user, but also have admin capabilties.
 * 
 * In addition to sorting and outputing and purchasing, they can also add entries, remove entries, 
 * and modify any entires in the list. They also have a 50% discount to all items they purchase.
 * 
 */

#ifndef __ADMIN_H__
#define __ADMIN_H__

#include "BookList.h"
#include "StoreUser.h"
#include <iostream>
#include <vector>
#include <string>

// class declaration interface which inherits from store user
// can do everything StoreUser can, but more
class Admin : public StoreUser {
    public:
        // default constructor
        Admin();

        // mutators
        void addEntry(const std::string &tempName, const std::string &tempAuthor, int tempPub, int tempPrice);
        void removeEntry(int tempID);
        void changeName(int tempID, const std::string &newName);
        void changeAuthor(int tempID, const std::string &newAuthor);
        void changePubDate(int tempID, int newDate);
        void changePrice(int tempID, int newPrice);
        // overriden purchase function from the StoreUser base class
        void purchase(int tempID); // TODO
        // accessor
        bool verification(const std::string &tempUser, const std::string &tempPass) const;
        void displayIDList();

    private:
        // private data members exclusive to the Admin class
        std::string UserName;
        std::string Password;

        // private helper functions
        bool isDuplicate(int keyID) const; // checks to see if there are any duplicates within the IDList
        // random number generator
        int random();
};

#endif //__ADMIN_H__