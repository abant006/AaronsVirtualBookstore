/**
 * @file StoreUser.h
 * @author Aaron Bantay (https://github.com/abant006)
 * 
 * Header for the StoreUser class.
 * This (abstract) class sets up an interface for classes that derive from it. Essentially this class has a data member that stores all the books held in the shop (in a Linked List)
 * The StoreUser has a set of functions defined within this class and a few which are pure virtual (must be defined in the derived classes). Any subclasses will be able to have access
 * to the store in a certain way by using the functions defined within this class.
 * 
 * TLDR: This class serves as a way for derived classes to access the list of books within the shop. 
 */