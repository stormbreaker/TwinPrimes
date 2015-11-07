/*************************************************************************//**
 * @file
 *****************************************************************************/
#ifndef __FUNCTIONS_H_
#define __FUNCTIONS_H_

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>
#include <list>
using namespace std;

void removeNonTwinSTL(list<unsigned long>* numList);
void genPrimSTL(unsigned long int upperBnd, list<unsigned long int>* numList);
unsigned long int checkComLine(int argc, char *argv[]);
void allRand(list<unsigned long>* ourlist, unsigned long int upBnd);
void queryCall(list<unsigned long int> * ourlist, int num1, char choice[]);
void random(list<unsigned long>* ourlist);
void help(void);
void listLessThan(list<unsigned long>* myList, unsigned long highBound);
void listLessThanEqualTo(list<unsigned long>* myList, unsigned long highBound);
void listGreaterThan(list<unsigned long>* myList, unsigned long lowBound);
void listGreaterThanEqualTo(list<unsigned long>* myList, unsigned long lowBound);
void listRange(list<unsigned long>* myList, unsigned long lowBound, unsigned long highBound);




// Function Prototypes

#endif