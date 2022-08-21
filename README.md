# Aaron's Online Bookstore

**Welcome to my virtual bookstore!**

*What is this?* You might be asking right about now...

## Introduction
This is an application that works just like any other bookstore you may come across, except *everything* is done virtually. The store is loaded with 14 different books, mangas, and light novels! 

As we dive further into this manual, I'll go more in depth on the specifics, but for now I'll go over a broad overview of what the store has to offer.

Upon opening the store you'll immediately notice that you're being asked if you are an *Admin* or not. If you respond yes, you will be prompted to enter your login credentials. After that, you will be greeted with a menu asking what you would like to do. As a regular customer this all very similar, except you will not have to enter any login credentials.

## Admin Users
Like stated in the general introduction, when you open the store, you will be asked if you are an admin or not. Following this, you will be asked to enter your login credentials.

***PLEASE BE WARY***

If you enter the wrong information **3 times** the store will close immediately.

For reference:
    - Username: StoreAdmin112
    - Password: Password123

![Admin Login Fail](https://github.com/abant006/AaronsVirtualBookstore/blob/master/BookstorePhotos/AdminLoginFAIL.PNG?raw=true)

###### Main Menu for Admins
Once past the login screen, you will be greeted by a menu screen with many different options to chose from

![Admin Main Menu](https://github.com/abant006/AaronsVirtualBookstore/blob/master/BookstorePhotos/AdminMainMenu.PNG?raw=true)

---------------------
**Adding A book entry**

Once pressing ***a***, you will be asked to enter a book's name, author's name, book's publish date, and its price.

*Please note* that you will NOT need to enter the Book's ID, because those are entered automatically by the store once a book entry is made.

-----------------------
**Removing a book entry**

Once pressing ***r***, you will be asked to enter the ID of the entry you would like to remove from the store.

*Please note* that if you enter an invalid ID, no entry will be removed.

-----------------------------
**Opening the admin edit menu**

Once pressing ***e***, a menu similar looking to the main menu will appear. In this menu you will see options to change the name of any given book, any given author, any given publish date, and any given price. Like the main menu, just press the corressponding button to access that option and follow the instructions to modify the entry.

--------------------------------
**Purchasing an item as an ADMIN**

Once pressing ***b***, you will be asked to enter thhe ID of a book you want to purchase from the store. Because you are an admin, the store offers a 50% discount on all purchases. After entering the ID, the store will ask for confirmation of your purchase with the name of the book and its final price.

*Please note* that if you enter the wrong ID number you will not be able to purchase the book.

---------------------
**Outputting the list**

Once pressing ***o***, the list of all the books currently in stock on the store will be printed out. Each entry will be split into respective columns of ID, Book Name, Author, Publish Date, and Price.

![Admin Output List](https://github.com/abant006/AaronsVirtualBookstore/blob/master/BookstorePhotos/AdminOutputMenu.PNG?raw=true)

---------------------
**Filtering the list**

Once pressing ***f***, you will be asked if you would like to filter the list from least to greatest in terms of ID numbers. If you reply yes, the list will be filtered and ready to output.

--------------------------------
**Displaying the store's ID list**

Once pressing ***d***, you will be asked if you would like to display the list od ID numbers the store is using. If you answer yes, all the ID numbers will be printed in a list.

*Please note* that even when you add a new entry to the list, the entry's ID will also be added to this ID list.

## Customers
As a customer you will not have as much access as an admin (obviously). And as such, you will be able to output the list of books in stock, filter them, and purchase one.

###### Main Menu for Customers
Similar in look to the Admin menu, however, you will be met with 3 distinct options I have stated in the customer overview.

![Customer Main Menu](https://github.com/abant006/AaronsVirtualBookstore/blob/master/BookstorePhotos/AdminOutputMenu.PNG?raw=true)
