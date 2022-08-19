/**
 * @file Customer.h
 * @author Aaron Bantay (https://github.com/abant006)
 * 
 * This is the Customer class (subclass) to the StoreUser class. This will act as a regular user
 * where they can do the same thing as a store user, but limited capabilities compared to an admin
 * 
 * They can purchase items, and can also apply a discount code if they want to
 * 
 */

#ifndef __CUSTOMER_H__
#define __CUSTOMER_H__

#include "BookList.h"
#include "StoreUser.h"

class Customer : public StoreUser {
    public:
        // default constructor
        Customer();

        // overriden purchase function
        void purchase(int tempID);

    private:
        // optional discount code which will be initialized in the constructor
        std::string discountCode;
};



#endif //__CUSTOMER_H__