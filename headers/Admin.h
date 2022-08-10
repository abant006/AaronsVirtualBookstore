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
        void modInfo();
        // accessor
        bool verification(const std::string &tempUser, const std::string &tempPass) const;

    private:
        // private data members exclusive to the Admin class
        std::string UserName;
        std::string Password;
};

#endif //__ADMIN_H__