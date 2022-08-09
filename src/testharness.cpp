/**
 * Test Harness for the different class functions
 */

#include "../headers/BookList.h"

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
    myList.push_back(855079, "Hi1", "Author1", 2019, 45);
    myList.push_back(30, "Percy Jackson", "Rick Riordan", 2024, 15);
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

    testSelectionSort();

    //testCopyConstructor();
    //testAssignmentOperator();
}
