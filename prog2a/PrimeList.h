/*************************************************************************//**
 * @file
 *****************************************************************************/
#ifndef __LLIST_H_
#define __LLIST_H_

#include <iostream>
using namespace std;


class PrimeList {
private:
    struct node {                      // Node for storing data
        unsigned long prime;
        node *next;
    };
    struct node *headptr;              // Head Pointer to list
    int count;


public: 
    // Creates an empty list.
    PrimeList();
    // Deletes the nodes
    ~PrimeList();                      
    // Adds a number to the list
    void Append(unsigned long v);      
    // Removes a number to a list
    void Remove(unsigned long v);      
    // Prints out the list
    void PrintList();                  
    // Gets the next prime in the list after the inputed one
    unsigned long getNext(unsigned long v);  
    // Checks to see if the list is empty
    bool isEmpty();  
    // Returns the size of the function
    int size();

};


#endif
