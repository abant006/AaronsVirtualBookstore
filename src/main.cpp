/**
 * @file main.cpp
 * @author Aaron Bantay (https://github.com/abant006)
 *
 * Main file which will hold the heart of the program; all the instructions that the user will "see"
 *
 */
 
#include <iostream>
#include <vector>
#include "../headers/BookList.h"
#include "../headers/StoreUser.h"
#include "../headers/Admin.h"
#include "../headers/Customer.h"


void AdminVerification(Admin &newAdmin);
void AdminMainMenu(); // just outputs the menu
void AdminAddEntry(Admin &newAdmin);
void AdminRemoveEntry(Admin &newAdmin);
void AdminModMenu(Admin &newAdmin);
int modInfoIDHelper();


void CustomerMainMenu(); // just outputs the menu

//------------------------------------------------------------------------
//------------------------------------------------------------------------
//------------------------------------------------------------------------

int main() {
    std::string choice = "";
    std::cout << "Hello! Welcome to Aaron's Virtual Bookstore!" << std::endl;
    std::cout << "Are you an admin of the store?: ";
    std::cin >> choice;

    while (choice != "yes" && choice != "no") {
        std::cout << "Please enter a valid response (yes/no): ";
        std::cin >> choice;
    }

    if (choice == "yes") {
        char response = '0';
        int id = 0;
        std::string res = "";
        Admin newAdmin; // CREATE A NEW ADMIN OBJ
        std::cout << std::endl;
        // first verifies the admin credentials
        AdminVerification(newAdmin);
        // then initially print out the admin menu
        std::cout << "Welcome back Admin! What would you like to do?" << std::endl;
        AdminMainMenu();
        // prompt the user on what they want to do
        std::cin >> response;
        std::cout << std::endl;

        // loop until the user wants to exit
        while (response != 'z') {
            if (response == 'a') {
                std::cout << "Adding a book entry to the list..." << std::endl;
                AdminAddEntry(newAdmin);
                std::cout << std::endl;
            }
            else if (response == 'r') {
                std::cout << "Removing an entry..." << std::endl;
                AdminRemoveEntry(newAdmin);
                std::cout << std::endl;
            }
            else if (response == 'e') {
                std::cout << "Opening the admin edit menu..." << std::endl;
                AdminModMenu(newAdmin);
            }
            else if (response == 'b') {
                std::cout << "Purchasing a book as an admin..." << std::endl;
                std::cout << "Please enter the book's ID: ";
                std::cin >> id;
                newAdmin.purchase(id);
                std::cout << std::endl;
            }
            else if (response == 'o') {
                std::cout << "Outputting the list..." << std::endl;
                newAdmin.output();
                std::cout << std::endl;
            }
            else if (response == 'f') {
                std::cout << "Filtering the list..." << std::endl;
                newAdmin.filter();
                std::cout << std::endl;
            }
            else if (response == 'd') {
                std::cout << "Do you want to display the list of ID numbers the store is using for the books?: ";
                std::cin >> res;
                while (res != "yes" && res != "no") {
                    std::cout << "Please enter a valid response (yes/no): ";
                    std::cin >> res;
                }

                if (res == "yes") {
                    std::cout << std::endl;
                    newAdmin.displayIDList();
                } else {
                    std::cout << "The ID list will not be displayed." << std::endl;
                }

                std::cout << std::endl;
            }

            // if the response isn't any of the options
            else {
                std::cout << "Please enter a valid response (a/r/e/b/o/f/z)" << std::endl;
            }

            // ask the user again what they would like to do
            std::cout << "What would you like to do?" << std::endl;
            AdminMainMenu();
            // prompt the user on what they want to do
            std::cin >> response;
            std::cout << std::endl;
        }

        std::cout << "Thank you for visiting, see you next time!" << std::endl;
    }

    else {
        char response = '0';
        int id = 0;
        std::string res = "";
        Customer newCust; // CREATE A NEW ADMIN OBJ
        std::cout << std::endl;
        // then initially print out the admin menu
        std::cout << "Welcome valued Customer! What would you like to do?" << std::endl;
        CustomerMainMenu();
        // prompt the user on what they want to do
        std::cin >> response;
        std::cout << std::endl;

        // loop until the user wants to exit
        while (response != 'z') {
            if (response == 'o') {
                std::cout << "Outputting the list..." << std::endl;
                newCust.output();
                std::cout << std::endl;
            }
            else if (response == 'f') {
                std::cout << "Filtering the list..." << std::endl;
                newCust.filter();
                std::cout << std::endl;
            }
            else if (response == 'b') {
                std::cout << "Purchasing a book..." << std::endl;
                std::cout << "Please enter the book's ID: ";
                std::cin >> id;
                newCust.purchase(id);
                std::cout << std::endl;
            }

            // if the response isn't any of the options
            else {
                std::cout << "Please enter a valid response (o/f/b/z)" << std::endl;
            }

            // ask the user again what they would like to do
            std::cout << "What would you like to do?" << std::endl;
            CustomerMainMenu();
            // prompt the user on what they want to do
            std::cin >> response;
            std::cout << std::endl;
        }

        std::cout << "Thank you for visiting, see you next time!" << std::endl;

    }
}

//------------------------------------------------------------------------
//------------------------------------------------------------------------
//------------------------------------------------------------------------

void AdminVerification(Admin &newAdmin) {
    std::string tempUser = "";
    std::string tempPass = "";
    bool loginCond = false;
    int logoutCntr = 0;

    std::cout << "Enter your username: ";
    std::cin >> tempUser;
    std::cout << "Enter your password: ";
    std::cin >> tempPass;
    loginCond = newAdmin.verification(tempUser, tempPass);
    logoutCntr++;

    while (loginCond == false && logoutCntr < 3) {
        std::cout << "Incorrect login credentials! Please enter again." << std::endl << std::endl;
        std::cout << "Enter your username: ";
        std::cin >> tempUser;
        std::cout << "Enter your password: ";
        std::cin >> tempPass;
        loginCond = newAdmin.verification(tempUser, tempPass);
        logoutCntr++;
    }

    // check first to see if the login condition is true after the loop exits
    if (loginCond == true) {
        std::cout << "You have logged in successfuly." << std::endl << std::endl;
    }

    // if false then the login condition has failed, and the user has tried too many times
    else {
        std::cout << "You have entered the wrong creditials repeatedly. Exiting the store..." << std::endl;
        // put in an exit function here to close the program
        exit(1);
    }
}

void AdminMainMenu() {
    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "a - Add a book entry to the store" << std::endl;
    std::cout << "r - Remove a book entry from the store" << std::endl;
    std::cout << "e - Open up the admin edit menu" << std::endl;
    std::cout << "b - Purchase a book from the store (50\% discount)" << std::endl;
    std::cout << "o - Output the list" << std::endl;
    std::cout << "f - Filter the list in ascending ID order" << std::endl;
    std::cout << "d - Display the store's ID list" << std::endl;
    std::cout << "z - Exit the store altogether" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

}

void AdminAddEntry(Admin &newAdmin) {
    std::string tempName = "";
    std::string tempAuthor = "";
    int tempPub = 0;
    int tempPrice = 0;

    // prompt the admin to enter book entry information
    std::cin.ignore();
    std::cout << "Please enter a book name: ";
    std::getline(std::cin, tempName);
    std::cout << "Please enter the author's name: ";
    std::getline(std::cin, tempAuthor);
    std::cout << "Please enter the book's publish date: ";
    std::cin >> tempPub;
    std::cout << "Please enter the book's price: ";
    std::cin >> tempPrice;

    // use those values and call the admin's addEntry function
    newAdmin.addEntry(tempName, tempAuthor, tempPub, tempPrice);
    std::cout << "Entry added!" << std::endl;
}

void AdminRemoveEntry(Admin &newAdmin) {
    int tempID = 0;
    std::cout << "Please enter the ID of the entry you would like to remove: ";
    std::cin >> tempID;

    newAdmin.removeEntry(tempID);
}

void AdminModMenu(Admin &newAdmin) {
    char response = '0';

    std::cout << "Hello admin, what would you like to do within the edit menu?" << std::endl;
     std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "n - Change the name of a book" << std::endl;
    std::cout << "a - Change the name of a book's author" << std::endl;
    std::cout << "p - Change a book's publish date" << std::endl;
    std::cout << "m - Change the price of a book" << std::endl;
    std::cout << "x - Exit admin edit menu" << std::endl;
     std::cout << "--------------------------------------------------" << std::endl;
    std::cin >> response;
    std::cout << std::endl;

    while (response != 'x') {
        if (response == 'n') {
            std::string newName = "";

            std::cin.ignore(); // CRUCIAL MUST HAVE THIS
            std::cout << "Please enter the new name of the book: ";
            std::getline(std::cin, newName);

            newAdmin.changeName(modInfoIDHelper(), newName);
            break;
        }
        else if (response == 'a') {
            std::string newAuthor = "";

            std::cin.ignore(); // CRUCIAL MUST HAVE THIS
            std::cout << "Please enter the new name of the author: ";
            std::getline(std::cin, newAuthor);

            newAdmin.changeAuthor(modInfoIDHelper(), newAuthor);
            break;
        }
        else if (response == 'p') {
            int newDate = 0;

            std::cout << "Please enter the new publish date of the book: ";
            std::cin >> newDate;

            newAdmin.changePubDate(modInfoIDHelper(), newDate);
            break;
        }
        else if (response == 'm') {
            int newPrice = 0;

            std::cout << "Please enter the new price of the book: ";
            std::cin >> newPrice;

            newAdmin.changePrice(modInfoIDHelper(), newPrice);
            break;
        }
        else {
            std::cout << "Please enter a valid response (n/a/p/m/x): ";
            std::cin >> response;
        }
    }

    std::cout << "Exited the admin edit menu successfully." << std::endl << std::endl;
}

// helper function that returns the ID that the user wants to pass into the modInfo function
int modInfoIDHelper() {
    int tempID = 0;

    std::cout << "Please enter the ID of the book you want to modify: ";
    std::cin >> tempID;

    return tempID;
}

//------------------------------------------------------------------------
//------------------------------------------------------------------------
//------------------------------------------------------------------------

void CustomerMainMenu() {
    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "b - Purchase a book from the store" << std::endl;
    std::cout << "o - Output the list" << std::endl;
    std::cout << "f - Filter the list in ascending ID order" << std::endl;
    std::cout << "z - Exit the store altogether" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;
}