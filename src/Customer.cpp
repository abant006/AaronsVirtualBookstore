/**
 * @file Customer.cpp
 * @author Aaron Bantay (https://github.com/abant006)
 * 
 * The cpp file for Customer.h which defines each function declared in the interface
 * 
 */

#include "../headers/Customer.h"
#include <iostream>

// constructor which calls the storeuser's constructor to initialize the inherited data members
Customer::Customer() : StoreUser(), discountCode("SummerSale22") { }

// overriden purchase function
void Customer::purchase(int tempID) {
    // this will call the bookList's get functions to confirm with the user
    std::string response = "";
    std::string code = "";
    // discount will be made constant. We dont want this to change under any cirumstance for admins
    const int discount = 4;
    int price = 0;

    // first see if the book exists within the list
    if (bookstoreList.exists(tempID) == false) {
        std::cout << "No purchase could be made because there exists no book in the store with a matching ID." << std::endl;
    } else { // if it does exist
        price = bookstoreList.getPrice(tempID);

        std::cout << "Do you have any discount codes you would like to apply?: ";
        std::cin >> response;
        while (response != "yes" && response != "no") {
            std::cout << "Please enter a valid response (yes/no): ";
            std::cin >> response;
        }

        // if the user has a discount code
        if (response == "yes") {
            std::cout << "Please enter a discount code: ";
            std::cin >> code;
            if (code == discountCode) {
                std::cout << "$4 discount applied succesfully!" << std::endl;
                std::cout << "Do you want to purchase the book " << bookstoreList.getName(tempID) << " for a total of $" << (price - discount) << "?: ";
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
            } else {
                std::cout << "Not a valid code!" << std::endl;
            }
        } else { // if the user does NOT have a discount code
            std::cout << "Do you want to purchase the book " << bookstoreList.getName(tempID) << " for a total of $" << price << "?: ";
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
}