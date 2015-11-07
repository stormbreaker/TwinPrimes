/*************************************************************************//**
 * @file
 *****************************************************************************/
#ifndef __FUNCTIONS_H_
#define __FUNCTIONS_H_

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>
#include "PrimeList.h"

void removeNonTwin(PrimeList *numList);
void genPrim(unsigned long int upperBnd, PrimeList *numList);
unsigned long int checkComLine(int argc, char *argv[]);
void allRand(PrimeList * ourlist, unsigned long int upBnd);
void queryCall(PrimeList * ourlist, int num1, char choice[]);
void random(PrimeList * ourlist);
void help(void);
void lessThan(PrimeList *list, unsigned long highBound);
void lessThanEqualTo(PrimeList *list, unsigned long highBound);
void greaterThan(PrimeList *list, unsigned long lowBound);
void greaterThanEqualTo(PrimeList *list, unsigned long lowBound);
void range(PrimeList *list, unsigned long lowBound, unsigned long highBound);


void mylessThan(PrimeList *list, unsigned long highBound);
void mylessThanEqualTo(PrimeList *list, unsigned long highBound);
void mygreaterThan(PrimeList *list, unsigned long lowBound);
void mygreaterThanEqualTo(PrimeList *list, unsigned long lowBound);
void myrange(PrimeList *list, unsigned long lowBound, unsigned long highBound);



// Function Prototypes

#endif