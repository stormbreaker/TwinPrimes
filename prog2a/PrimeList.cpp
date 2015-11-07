/*************************************************************************//**
 * @file
 *****************************************************************************/
#include "PrimeList.h"


/**************************************************************************//** 
 * @author Tristan Anastas
 * 
 * @par Description: 
 * Contructor for the List class. It sets the headpointer and count to nullptr
 * and zero respectfully.
 * 
 *****************************************************************************/
PrimeList::PrimeList()
{
    headptr = nullptr;
    count = 0;
}

/**************************************************************************//** 
 * @author Tristan Anastas
 * 
 * @par Description: 
 * Deconstructor for the list class. Goes through and deletes all the allocated
 * memory (nodes).
 * 
 *****************************************************************************/
PrimeList::~PrimeList()
{
    struct node *c = headptr;
    struct node *p = headptr;
    
    if (headptr == nullptr)   // empty list
    {
        return;
    }

    while (c != nullptr)
    {
        p = c;
        c = c->next;
        delete p;
    } 
    
}

/**************************************************************************//** 
 * @author Tristan Anastas
 * 
 * @par Description: 
 * Appends an unsigned long (v) to the end of the list.
 * 
 * @param[in]      v - unsigned long to be appended to the end of the list.
 * 
 *****************************************************************************/
void PrimeList::Append(unsigned long v)
{
    struct node *add = new (nothrow) struct node;
    add->prime = v;
    add->next = nullptr;
    
    struct node *c = headptr;  // Sets up a current and prev for walking 
    struct node *p = headptr;  // through the list.

    while (c != nullptr)   // Walks to the end of the list
    {
        p = c;
        c = c->next;
    }

    if (headptr == nullptr)  // If an empty list
    {
        headptr = add;
        count = 1;
        return;
    }
    
    p->next = add;  // adds add to the end of the list
    count++;
}

/**************************************************************************//** 
 * @author Tristan Anastas
 * 
 * @par Description: 
 * Removes the first instance of value (v) from the this list. 
 * 
 * @param[in]      v - the value to be removed from the list.
 * 
 *****************************************************************************/
void PrimeList::Remove(unsigned long v)
{
    struct node *c = headptr;   // Temp vars for walk through
    struct node *p = headptr;

    while (c != nullptr && c->prime != v)  // Stops at end of list or when the
    {                                      // the value is found.
        p = c;
        c = c->next;
    }

    if (c == nullptr)                    // Not found, return;
        return;

    if (headptr->next == nullptr)         // Only 1 in the list
    {
        delete c;
        headptr = nullptr;               // has to set headptr to nullptr for 
        count = 0;                       // empty list.
        return;
    }

    p->next = c->next;    // Removes the element
    delete c;
    count--;

}

/**************************************************************************//** 
 * @author Tristan Anastas
 * 
 * @par Description: 
 * Prints out the list.
 * 
 *****************************************************************************/
void PrimeList::PrintList()
{
    struct node *temp = headptr;
    if (headptr == nullptr)      // if its empty print nothing
        return;

    while (temp != nullptr)          // goes through list and prints out primes
    {
        cout << temp->prime << endl;
        temp = temp->next;
    }
}

/**************************************************************************//** 
 * @author Tristan Anastas
 * 
 * @par Description: 
 * Gives the value after the inputed value (v).
 * 
 * @param[in]      v - the value used to find the return value. 
 * @param[out]     temp->prime - returns the value of the element after v
 * 
 * 
 * @returns -1 when the list is empty.
 * @returns 0 when you have reached the end of the list.
 * @returns value of the next element in the list.
 * 
 *****************************************************************************/
unsigned long PrimeList::getNext(unsigned long v)
{
    struct node *temp = headptr;       // temp value for iteration

    if (headptr == nullptr)            // if empty return -1
        return -1;

    while (temp != nullptr && temp->prime <= v)   // goes through until end of
    {                                             // list or next value found
        temp = temp->next;
    }

    if (temp == nullptr)  // if end of list return 0
        return 0;

    return temp->prime;    // return the next value
}

/**************************************************************************//** 
 * @author Tristan Anastas
 * 
 * @par Description: 
 * Returns true or false depending if the list is empty.
 *
 * @returns true if the list is empty.
 * @returns false if the list is not empty.
 * 
 *****************************************************************************/
bool PrimeList::isEmpty()
{
    if (headptr == nullptr)
        return true;

    return false;
}

/**************************************************************************//** 
 * @author Tristan Anastas
 * 
 * @par Description: 
 * Returns the number of elements in the list.
 * 
 * @param[out]      count - the number of elements in the list.
 *  
 * @returns number of elements in the list.
 * 
 *****************************************************************************/
int PrimeList::size()
{
    return count;
}

