/**
 * Test Harness for the different class functions
 */

#include "../headers/BookList.h"
#include "../headers/StoreUser.h"
#include "../headers/Admin.h"
#include "../headers/Customer.h"

void modInfo();
int modInfoIDHelper();

// global list to do work on
BookList myList;

// push_back
void testPushBackOutPut() {
    myList.push_back(855079, "Hi1", "Author1", 2019, 45);
    //std::cout << myList << std::endl;
    myList.push_back(30, "Percy Jackson", "Rick Riordan", 2024, 15);
    myList.push_back(31, "Harry Potter", "J.K. Rowling", 2012, 18);
    myList.push_back(32, "The Magic Tree House", "Idk who wrote this", 2023, 10);
    myList.push_back(33, "Diary of a Wimpy Kid", "Jeff Kinney", 2062, 3);
    std::cout << myList << std::endl;
}

// using a loop to push_back
void testPushBackOutPutLOOP() {
    // enter x entries into the list
    auto x = 5;
    for (auto i = 0; i < x; i++) {
        //
    }
    std::cout << myList << std::endl;
}

void testPushFront() {
    //
    myList.push_front(30, "Hi2", "Author2", 2022, 78);

    std::cout << myList << std::endl;
}

// using clear() after pushing front multiple entries
void testPushFrontClear() {
    //
    myList.push_front(30, "Hi2", "Author2", 2022, 78);
    myList.push_front(31, "Hi3", "Author3", 2023, 88);
    myList.push_front(32, "Hi4", "Author4", 2024, 98);
    myList.push_front(33, "Hi5", "Author5", 2025, 28);

    std::cout << myList << std::endl;

    myList.clear();

    std::cout << "The list is now empty, so: " << std::endl;
    std::cout << myList;
}

// using clear() after pushing back multiple entries, then outputting the empty list
void testClearMultEntries() {
    myList.push_back(24, "Hi1", "Author1", 2019, 45);
    std::cout << myList << std::endl;
    myList.push_back(30, "Hi2", "Author2", 2022, 78);
    std::cout << myList << std::endl;

    myList.clear();

    std::cout << "The list is now empty, so: " << std::endl;
    std::cout << myList;
}

void testClearZeroEntries() {
    myList.clear();
    std::cout << "The list is now empty, so: " << std::endl;
    std::cout << myList;
}

// tests the changeName() function
void testSetGetName() {
    myList.push_back(305675, "Hi2", "Author2", 2022, 78);
    myList.push_back(57, "Bye1", "Author590", 2075, 678);

    std::cout << myList << std::endl;

    std::cout << "Old Name: " << myList.getName(57) << std::endl;

    myList.setName(57, "Sheesh");

    std::cout << "New Name: " << myList.getName(57) << std::endl;

    std::cout << myList << std::endl;

    std::cout << "Clearing the list..." << std::endl;
    myList.clear();

    myList.setName(57, "New New Name");
    std::cout << "New Name: " << myList.getName(57) << std::endl;
}

// tests the changeName() function on an empty list
void testSetGetNameEmpty() {
    myList.setName(30, "Testing");
    std::cout << myList.getName(30);
}

// tests the setprice() function
void testSetGetPrice() {
    myList.push_back(305675, "Hi2", "Author2", 2022, 78);
    myList.push_back(57, "Bye1", "Author590", 2075, 678);

    std::cout << myList << std::endl;

    std::cout << "Old Price: $" << myList.getPrice(57) << std::endl;

    myList.setPrice(57, 43);

    if (myList.getPrice(57) == -1) {
        std::cout << "No price can be found; no entry could be matched." << std::endl;
    } else {
        std::cout << "New Price: $" << myList.getPrice(57) << std::endl;
    }

    std::cout << myList << std::endl;

    std::cout << "Clearing the list..." << std::endl;
    myList.clear();

    myList.setPrice(57, 15);
    if (myList.getPrice(57) == -1) {
        std::cout << "No price can be found; no entry could be matched." << std::endl;
    } else {
        std::cout << "New Price: $" << myList.getPrice(57) << std::endl;
    }
    
}

// tests the setPrice() function on an empty list
void testSetGetPriceEmpty() {
    myList.setPrice(57, 15);
    if (myList.getPrice(57) == -1) {
        std::cout << "No price can be found; no entry could be matched." << std::endl;
    } else {
        std::cout << "New Price: $" << myList.getPrice(57) << std::endl;
    }
}

// tests the setAuthor() function
void testSetGetAuthor() {
    myList.push_back(305675, "Hi2", "Author2", 2022, 78);
    myList.push_back(57, "Bye1", "Author590", 2075, 777);

    std::cout << myList << std::endl;

    std::cout << "Old Author: " << myList.getAuthor(57) << std::endl;

    myList.setAuthor(57, "Sheesh");

    std::cout << "New Name: " << myList.getAuthor(57) << std::endl;

    std::cout << myList << std::endl;

    std::cout << "Clearing the list..." << std::endl;
    myList.clear();

    myList.setAuthor(57, "New New Name");
    std::cout << "New Name: " << myList.getAuthor(57) << std::endl;
}

// tests the changeName() function on an empty list
void testSetGetAuthorEmpty() {
    myList.setAuthor(30, "Testing");
    std::cout << myList.getAuthor(30);
}

// tests the setPubDate() function
void testSetGetDate() {
    myList.push_back(305675, "Hi2", "Author2", 2022, 78);
    myList.push_back(57, "Bye1", "Author590", 2075, 678);

    std::cout << myList << std::endl;

    std::cout << "Old Date: " << myList.getPubDate(57) << std::endl;

    myList.setPubDate(57, 43);

    if (myList.getPubDate(57) == -1) {
        std::cout << "No date can be found; no entry could be matched." << std::endl;
    } else {
        std::cout << "New Date: " << myList.getPubDate(57) << std::endl;
    }

    std::cout << myList << std::endl;

    std::cout << "Clearing the list..." << std::endl;
    myList.clear();

    myList.setPubDate(57, 15);
    if (myList.getPubDate(57) == -1) {
        std::cout << "No date can be found; no entry could be matched." << std::endl;
    } else {
        std::cout << "New Date: " << myList.getPubDate(57) << std::endl;
    }
    
}

// tests the setPubDate() function on an empty list
void testSetGetDateEmpty() {
    myList.setPubDate(57, 15);
    if (myList.getPubDate(57) == -1) {
        std::cout << "No date can be found; no entry could be matched." << std::endl;
    } else {
        std::cout << "New Date: " << myList.getPubDate(57) << std::endl;
    }
}

// test out the pop functions

void testPopFront() {
    myList.push_back(855079, "Hi1", "Author1", 2019, 45);
    //std::cout << myList << std::endl;
    myList.push_back(30, "Percy Jackson", "Rick Riordan", 2024, 15);
    myList.push_back(31, "Harry Potter", "J.K. Rowling", 2012, 18);
    myList.push_back(32, "The Magic Tree House", "Idk who wrote this", 2023, 10);
    myList.push_back(33, "Diary of a Wimpy Kid", "Jeff Kinney", 2062, 3);
    std::cout << myList << std::endl;

    myList.pop_front();
    std::cout << myList << std::endl;
    myList.pop_front();
    std::cout << myList << std::endl;
    myList.pop_front();
    std::cout << myList << std::endl;
    myList.pop_front();
    std::cout << myList << std::endl;
    myList.pop_front();
    std::cout << myList << std::endl;
}

void testPopBack() {
    myList.push_back(855079, "Hi1", "Author1", 2019, 45);
    //std::cout << myList << std::endl;
    myList.push_back(30, "Percy Jackson", "Rick Riordan", 2024, 15);
    myList.push_back(31, "Harry Potter", "J.K. Rowling", 2012, 18);
    myList.push_back(32, "The Magic Tree House", "Idk who wrote this", 2023, 10);
    myList.push_back(33, "Diary of a Wimpy Kid", "Jeff Kinney", 2062, 3);
    std::cout << myList << std::endl;

    myList.pop_back();
    std::cout << myList << std::endl;
    myList.pop_back();
    std::cout << myList << std::endl;
    myList.pop_back();
    std::cout << myList << std::endl;
    myList.pop_back();
    std::cout << myList << std::endl;
    myList.pop_back();
    std::cout << myList << std::endl;
}

void testRemove() {
    // myList.push_back(855079, "Hi1", "Author1", 2019, 45);
    // myList.push_back(30, "Percy Jackson", "Rick Riordan", 2024, 15);
    // myList.push_back(31, "Harry Potter", "J.K. Rowling", 2012, 18);
    // myList.push_back(32, "The Magic Tree House", "Idk who wrote this", 2023, 10);
    // myList.push_back(33, "Diary of a Wimpy Kid", "Jeff Kinney", 2062, 3);
    std::cout << myList << std::endl;

    myList.remove(30);
    std::cout << myList << std::endl;
    myList.remove(855078);
    std::cout << myList << std::endl;
    myList.remove(855079);
    myList.remove(855079);
}

void testSelectionSort() {
    myList.push_back(858239, "Diary of a Wimpy Kid", "Jeff Kinney", 2062, 3);
    myList.push_back(859879, "The Magic Tree House", "Idk who wrote this", 2023, 10);
    myList.push_back(811079, "Hi1", "Author1", 2019, 45);
    myList.push_back(855079, "Percy Jackson", "Rick Riordan", 2024, 15);
    myList.push_back(825079, "Harry Potter", "J.K. Rowling", 2012, 18);
    std::cout << myList << std::endl;

    myList.selection_sort();

    std::cout << myList << std::endl;
}

void testCopyConstructor() {
    myList.push_back(15, "Diary of a Wimpy Kid", "Jeff Kinney", 2062, 3);
    myList.push_back(24, "The Magic Tree House", "Idk who wrote this", 2023, 10);
    myList.push_back(855079, "Hi1", "Author1", 2019, 45);
    myList.push_back(30, "Percy Jackson", "Rick Riordan", 2024, 15);
    myList.push_back(565, "Harry Potter", "J.K. Rowling", 2012, 18);
    std::cout << "First List: " << std::endl;
    std::cout << myList << std::endl;

    std::cout << std::endl;

    // create a new list and call the copy constructor
    BookList newList(myList); // one way
    //BookList newList = myList; // another way

    // now print the new list
    std::cout << "Second List: " << std::endl;
    std::cout << newList << std::endl;
}

void testAssignmentOperator() {
    std::cout << "Testing the Assignment Operator" << std::endl;

    myList.push_back(858239, "Diary of a Wimpy Kid", "Jeff Kinney", 2062, 3);
    myList.push_back(859879, "The Magic Tree House", "Idk who wrote this", 2023, 10);
    myList.push_back(811079, "Hi1", "Author1", 2019, 45);
    myList.push_back(855079, "Percy Jackson", "Rick Riordan", 2024, 15);
    myList.push_back(825079, "Harry Potter", "J.K. Rowling", 2012, 18);
    std::cout << "First List: " << std::endl;
    std::cout << myList << std::endl;

    std::cout << std::endl;

    // create a new list
    BookList newList;

    // push_back some "fake values"
    newList.push_back(33, "BookOne", "AuthorOne", 2062, 9);
    newList.push_back(678, "BookTwo", "AuthorTwo", 2023, 78);
    newList.push_back(8079, "BookThree", "AuthorThree", 2019, 64564);

    // now use the assignment operator to set mylist to newList
    newList = myList;
    // newList.operator=(myList); // another way to write

    // now print the new list
    std::cout << "Second List: " << std::endl;
    std::cout << newList << std::endl;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

//StoreUser myStore; // this will call the default constructor, thus reading from the dat file

// void testStoreUserOutput() {
//     myStore.output();
// }

// void testStoreSort() {
//     // call the filter function first
//     myStore.filter();
//     // output it after to see the changes (or no changes)
//     myStore.output();
// }

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

Admin newAdmin;

void testAdminOutput() {
    std::cout << "Testing output() for Admin class: " << std::endl;
    newAdmin.output();
}

void testAdminSort() {
    std::cout << "Testing filter() for Admin class: " << std::endl;
    newAdmin.filter();
    newAdmin.output();
}

// use this function in actual main
void testVerification() {
    std::string tempUser = "";
    std::string tempPass = "";
    bool loginCond = false;
    int logoutCntr = 0;

    std::cout << "Enter your username: " << std::endl;
    std::cin >> tempUser;
    std::cout << "Enter your password: " << std::endl;
    std::cin >> tempPass;
    loginCond = newAdmin.verification(tempUser, tempPass);
    logoutCntr++;

    while (loginCond == false && logoutCntr < 3) {
        std::cout << "Incorrect login credentials! Please enter again." << std::endl << std::endl;
        std::cout << "Enter your username: " << std::endl;
        std::cin >> tempUser;
        std::cout << "Enter your password: " << std::endl;
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
        std::cout << "You have entered the wrong creditials repeatedly. Please try again later." << std::endl;
        // put in an exit function here to close the program
        //exit(1);
    }
}

void testDisplayIDList() {
    newAdmin.displayIDList();
}

// adds an entry to the list then outputs it (the list)
void testAddEntryAndOutput() {
    std::string tempName = "";
    std::string tempAuthor = "";
    int tempPub = 0;
    int tempPrice = 0;

    // prompt the admin to enter book entry information
    std::cout << "Please enter a book name: ";
    std::getline(std::cin, tempName);
    std::cout << std::endl;
    std::cout << "Please enter the author's name: ";
    std::getline(std::cin, tempAuthor);
    std::cout << std::endl;
    std::cout << "Please enter the book's publish date: ";
    std::cin >> tempPub;
    std::cout << std::endl;
    std::cout << "Please enter the book's price: ";
    std::cin >> tempPrice;
    std::cout << std::endl;

    // use those values and call the admin's addEntry function
    newAdmin.addEntry(tempName, tempAuthor, tempPub, tempPrice);

    // now output the list;
    newAdmin.output();
}

void testRemoveAndOutput() {
    int tempID = 0;

    // prompt user to enter an ID they want to remove
    std::cout << "Please enter the ID of the entry you would like to remove: ";
    std::cin >> tempID;

    newAdmin.removeEntry(tempID);
    newAdmin.output();
}

// void testDuplicateID() {
//     int tempID = 0;
//     std::cout << "Enter an ID Number: " << std::endl;
//     std::cin >> tempID;

//     if (newAdmin.isDuplicate(tempID) == true) {
//         std::cout << "ERROR! The ID already exits!" << std::endl;
//     } else {
//         std::cout << "The ID is not in the list yet. No duplicates." << std::endl;
//     }
// }

// this function tests the admin class's overriden purchase function
void testAdminPurchase() {
    int id = 0;

    newAdmin.output();

    std::cout << "Please enter the book's ID: ";
    std::cin >> id;

    newAdmin.purchase(id);

    newAdmin.output();
}

// function will be built similar to the mod info function used in the main driver program
void modInfo() {
    char response = '0';

    newAdmin.output(); // FOR TESTING REASONS

    std::cout << std::endl;
    std::cout << "Hello admin, what would you like to do within the edit menu?" << std::endl;
    std::cout << "n - Change the name of a book" << std::endl;
    std::cout << "a - Change the name of a book's author" << std::endl;
    std::cout << "p - Change a book's publish date" << std::endl;
    std::cout << "m - Change the price of a book" << std::endl;
    std::cout << "x - Exit admin edit menu" << std::endl;
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

    newAdmin.output(); // FOR TESTING REASONS
}

// helper function that returns the ID that the user wants to pass into the modInfo function
int modInfoIDHelper() {
    int tempID = 0;

    std::cout << "Please enter the ID of the book you want to modify: ";
    std::cin >> tempID;

    return tempID;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
Customer newCust;

void testCustPurchase() {
    int id = 0;

    newCust.output();

    std::cout << "Please enter the book's ID: ";
    std::cin >> id;

    newCust.purchase(id);

    newCust.output();
}

void testCustOutputFilter() {
    newCust.output();
    std::cout << std::endl;
    newCust.filter();
    newCust.output();
}


int main() {
    // RUN ONE TEST AT A TIME


    //testPushBackOutPut();
    //testClearZeroEntries();

    //testPushFront();
    //testPushFrontClear();

    //testSetGetName();
    //testSetGetNameEmpty();

    //testSetGetPrice();
    //testSetGetPriceEmpty();

    // testSetGetAuthor();
    // testSetGetAuthorEmpty();

    //testSetGetDate();
    //testSetGetDateEmpty();

    //testPopFront();
    //testPopBack();

    //testRemove();

    //testSelectionSort();

    //testCopyConstructor();
    //testAssignmentOperator();




    //testStoreUserOutput();
    //testStoreSort();



    //testAdminOutput();
    //testAdminSort();
    //testVerification();

    //testDisplayIDList();
    //testDuplicateID();

    //testAddEntryAndOutput();
    //testRemoveAndOutput();

    //testAdminPurchase();
    //modInfo();


    //testCustPurchase();
    testCustOutputFilter();


}
