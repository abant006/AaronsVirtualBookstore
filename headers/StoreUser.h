/**
 * @file StoreUser.h
 * @author Aaron Bantay (https://github.com/abant006)
 * 
 * Header for the StoreUser class.
 * This (abstract) class sets up an interface for classes that derive from it. Essentially this class has a data member that stores all the books held in the shop (in a Linked List)
 * The StoreUser has a set of functions defined within this class and a few which are pure virtual (must be defined in the derived classes). Any subclasses will be able to have access
 * to the store in a certain way by using the functions defined within this class.
 * 
 * TLDR: This class serves as a way for derived classes to access the list of books within the shop. In a way, this class is BOTH the user and the store. Holds the list of book entries
 *       seen in a store, but has functions that modifies/accesses those entries like a user would.
 * 
 * CREATE A PRIVATE DATA MEMBER FOR THE CUSTOMER CLASS THAT IS A DISCOUNT CODE (STRING)
 * 
 */
#ifndef __STOREUSER_H__
#define __STOREUSER_H__

#include "BookList.h"
#include <vector>
#include <fstream>

class StoreUser {
    public:
        // constructor and destructor
        StoreUser();
        ~StoreUser(); // this should just call bookstoreList's destructor
        
        // mutators
        void filter();

        // for purchasing, make it so that there's an "add to cart" feature
        //virtual void purchase() = 0; // pure virtual function that should be overriden by subclasses

        // accessors
        void output() const;

        // display IDList function? for admins maybe.. or we can do so in here for now

    protected:
        // IN STOREUSER'S CONSTRUCTOR DO I HAVE TO CALL BOOKSTORELIST'S CONSTRUCTOR? OR HOW DOES IT WORK
        BookList bookstoreList;
        // SAME QUESTION HERE? OR HOW DO I CONSTRUCT IT???
        std::vector<int> IDList; // stores any and all currently/previously used Book ID's to ensure no duplicates are made
        
        // private helper functions

        //USE THIS FOR THE ADMIN SUBCLASS
        //bool isDuplicate(); // checks to see if there are any duplicates within the IDList
        void SkipBOM(std::ifstream &in); // skips the Byte Order Mark (BOM) that defines UTF-8 in some text files
};


#endif //__STOREUSER_H__