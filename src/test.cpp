/**
 * @file test.cpp
 * @author Aaron Bantay (https://github.com/abant006)
 *
 * Test file which will hold all the tests I run for classes in the program
 *
 */
 
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>

// node objects (FOR VECTOR USE)
struct Book {
    int id;
    std::string bookName;
    std::string author;
    int publishDate;
    int price;

    Book(int pID, std::string pBookName, std::string pAuthor, int pPub, int pPrice) : id(pID), bookName(pBookName), author(pAuthor), publishDate(pPub), price(pPrice) {}

};

// function declarations
void testRead();
void SkipBOM(std::ifstream &in);

// MAIN WHICH WILL RUN THE TESTS
int main() {
    testRead();
}

void testRead() {
    // tests/opens the txt file, reads the data into a temp vector, then prints the contents
    std::ifstream inFile;
    std::string info = "";
    std::vector<std::string> booklist;
    std::vector<Book> bookshelf;

    inFile.open("BookList.dat");
    if (!inFile) {
        std::cout << "Error! File could not be opened!" << std::endl;
        exit(1);
    }

    SkipBOM(inFile);

    while (getline(inFile, info)) {
        booklist.push_back(info);
    }

    // print the vector's info
    for (auto i = 0; i < booklist.size(); ++i) {
        std::cout << booklist.at(i) << std::endl;
    }

    inFile.close();

    // copy the temp Vector's info into a Book object, and into a vector
    for (auto i = 0; i < booklist.size(); i += 5) {
        // converting the strings in the booklist vector to ints where needed
        int tempID = stoi(booklist.at(i)); 
        int tempPub = stoi(booklist.at(i + 3));
        int tempPrice = stoi(booklist.at(i + 4));
        Book tempBook(tempID, booklist.at(i + 1), booklist.at (i + 2), tempPub, tempPrice);

        bookshelf.push_back(tempBook);
    }

    // print the new vector's info
    for (auto i = 0; i < bookshelf.size(); ++i) {
        std::cout << bookshelf.at(i).id << "\t\t" << bookshelf.at(i).bookName << "\t\t" << bookshelf.at(i).author << "\t\t" << bookshelf.at(i).publishDate << "\t\t" << "$" << bookshelf.at(i).price << std::endl;
    }

}

// skips the Byte Order Mark (BOM) that defines UTF-8 in some text files.
void SkipBOM(std::ifstream &in)
{
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