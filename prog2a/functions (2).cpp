/*************************************************************************//**
 * @file
 *****************************************************************************/
#include "functions.h"

// This is required otherwise we get a linker error due to unresolved external
// symbol.
void queryCall(PrimeList * ourlist, unsigned long int num1, char * choice);

/**************************************************************************//**
* @author Benjamin Kaiser
*
* @par Description:
* This function traverses a list of prime numbers and removes all of the ones
* which are not twin primes by comparing their values.  
*
*
*
* @param[in,out]  numList - this is the list being modified for twin primes
*
* @returns No returns.
*
*****************************************************************************/
void genPrim(unsigned long int upperBnd, PrimeList *numList)
{
    unsigned long int i = 0;
    unsigned long int temp = 0;
    numList->Append(3);
    for (i = 3; i <= upperBnd; i += 2)
    {
        temp = 0;
        temp = numList->getNext(temp);
        while (temp != 0 && i % temp != 0 ) // this might need another condition
        {
            temp = numList->getNext(temp);
        }
        if (temp == 0)
        {
            numList->Append(i);
        }
    }
}

/**************************************************************************//**
* @author Benjamin Kaiser
*
* @par Description:
* This function gets an upper bound which is passed and then generates all
* prime numbers between 3 and that upper bound.  It loads them into the 
* PrimeList class created by Tristan Anestas
* 
*
* @param[in]      upperBnd - this variable is upper boundary entered by user
* 
* @param[in,out]  numList - this is the list being generated
*
* @returns No returns.
*
*****************************************************************************/
void removeNonTwin(PrimeList * numList)
{
    unsigned long int prev = 0, curr = 0;
    unsigned long int temp = 0;
    bool prevTwin = false;
    bool currTwin = false;
    prev = numList->getNext(prev);
    curr = numList->getNext(prev);
    while (curr != 0)
    {
        if ((curr - prev != 2) && (prevTwin == false))
        {
            numList->Remove(prev);
        }
        else if ((curr - prev == 2))
        {
            prevTwin = true;
            currTwin = true;
        }
        prev = numList->getNext(prev);
        curr = numList->getNext(curr);
        prevTwin = currTwin;
        currTwin = false;
    }
    if (!prevTwin)
        numList->Remove(prev);
}

/**************************************************************************//**
* @author Eric Vandervort
*
* @par Description:
* Checks command line arguments, returns error and quits if no upper bound is
* given. retrieves upper bound and converts it from char to unsigned long int
* then returns that unsigned long int
*
* @param[in]      argc - number of command line arguments
* @param[in]      argv - character array of command line arguments
* @param[out]     upBnd - the number given in the command line for upper bound
*
* @returns upBnd the char given in command line converted to unsigned long int
*
*****************************************************************************/
unsigned long int checkComLine(int argc, char *argv[])
{
    unsigned long upBnd = 0;

    if (argc <= 1)
    {
        cout << "Error: No upper bound!\n";
        cout << "Usage: prog2pt1.exe arg1\n       arg1 - upper bound" << endl;
        return -1;
    }
    else
    {
        upBnd = strtoul(argv[1], 0, 10);
        if (upBnd == 0)
        {
            cout << "Error: Invalid upper bound!\n";
            cout << "Usage: prog2pt1.exe arg1\n       arg1 - upper bound" << endl;
            return -1;
        }
    }
    return upBnd;
}

/**************************************************************************//**
* @author Eric Vandervort
*
* @par Description:
* the user will enter a query they want performed on the list. If they didn't
* type 'exit' or 'quit' the function will then convert whatever they wrote to
* lowercase. If the user input 'all' 'random' or 'help' it will call that 
* function. If they enter '<>' the function will call the range function,
* otherwise it will call the query function.
* 
* @param[in]      ourlist - Pointer to the list
*
*****************************************************************************/
void allRand(PrimeList * ourlist, unsigned long int upBnd)
{
    char choice[100];
    unsigned long int num1, num2, i = 0;

    cout << "Enter a query to perform on the list or 'help' for a help menu" << endl;
    cin >> choice;

    while (true)
    {
        while (choice[i] != '\0')
        {
            choice[i] = tolower(choice[i]);
            i++;
        }

        i = 0;

        if (strcmp(choice, "exit") == 0 || strcmp(choice, "quit") == 0)
        {
            cout << "exiting!\n";
            break;
        }
        if (strcmp(choice, "all") == 0)
        {
            range(ourlist, 0, upBnd);
            cout << "Enter next query" << endl;
            cin >> choice;
        }
        else if (strcmp(choice, "random") == 0)
        {
            random(ourlist);
            cout << "Enter next query" << endl;
            cin >> choice;
        }
        else if (strcmp(choice, "help") == 0)
        {
            help();
            cout << "Enter next query" << endl;
            cin >> choice;
        }
        else if (strcmp(choice, "<>") == 0)
        {
            cout << "Please enter low bound then upper bound\n";
            cin >> num1 >> num2;
            range(ourlist, num1, num2);
            cout << "Enter next query" << endl;
            cin >> choice;
        }
        else if (choice[0] == '<' || choice[0] == '>')
        {
            cin >> num1;
            queryCall(ourlist, num1, choice);
            cout << "Enter next query" << endl;
            cin >> choice;
        }
        else
        {
            cout << "Invalid Query!\n";
            help();
            cout << "Enter next query" << endl;
            cin >> choice;
        }
    }
}

/**************************************************************************//**
* @author Eric Vandervort
*
* @par Description:
* passes in the users input for what query they want performed. Checks for 
* every query and calls the function, otherwise what they typed was invalid and
* they must enter a new query.
*
* @param[in]      ourlist - our linked list
* @param[in]      num1 - the number the user inputs for the query
* @param[in]      choice - the query the user entered to perform
*
*****************************************************************************/
void queryCall(PrimeList * ourlist, unsigned long int num1, char * choice)
{

    if (strcmp(choice, ">=") == 0)
    {
        mygreaterThanEqualTo(ourlist, num1);
        
    }
    else if (strcmp(choice, ">") == 0)
    {
        mygreaterThan(ourlist, num1);
    }
    else if (strcmp(choice, "<=") == 0)
    {
        
        mylessThanEqualTo(ourlist, num1);
    }
    else if (strcmp(choice, "<") == 0)
    {
        mylessThan(ourlist, num1);
    }
    else
    {
        cout << "Query not valid" << endl;
    }
    return;
}


/**************************************************************************//** 
 * @author Tristan Anastas
 * 
 * @par Description: 
 *      Randomly grabs a twin pair from the list and outputs it.
 * 
 * 
 * @param[in]  ourlist - a list of primes, of class PrimeList, for values to be pulled from
 * 
 *****************************************************************************/
void random(PrimeList * ourlist)
{
    int num;
    unsigned long int p = 0;
    unsigned long int c = 0;
    unsigned long int n = 0;

    num = (rand() % ourlist->size()) + 1;


    for (int i = 0; i < num; i++)
    {
        p = c;
        c = ourlist->getNext(c);
        n = ourlist->getNext(c);
    }
    if (c - p == 2) // check if p and c are twins
    {
        cout << "(" << p << ", " << c << ")\n";
        return;
    }
    if (n - c == 2) // check to see if c and n are twins
    {
        cout << "(" << c << ", " << n << " )\n";
        return;
    }

    return;
}

/**************************************************************************//**
* @author Eric Vandervort
*
* @par Description:
* Prints a menu of each query the user can perform on the list
*
*****************************************************************************/
void help()
{
    cout << "'> num' will output all twin primes greater than num" << endl
        << "'>= num' will output all twin primes greater than or equal to num"
        << endl << "'< num' will output all twin primes less than num" << endl
        << "'<= num' will output all twin primes less than or equal to num" <<
        endl << "'<> num1, num2' will output all twin primes between num1 and"
        << " num2" << endl << "'all' will output all twin primes in the list"
        << endl << "'random' will output a random twin prime in the list" <<
        endl << endl;

    return;
}

/**************************************************************************//**
* @author Remington Bullis
*
* @par Description:
*      This function displays all twin-prime pairs consisting of numbers less than
* a defined value. It finds the first value in teh list, stores it, grabs the second
* value, compares those two values agains the upper bound. If the values are within
* bounds and the none of the values in the pair have been previously used, then the
* function prints the pair to the screen. The checking for previously-used values is
* necessary as the second value in the first pair (e.g. (1,2)) becomes the first value
* in the second pair (e.g. (2,3)), meaning only every-other pair should be outputted.
* While this is not optimal behavior, it is a simple way to process the information and
* is decently efficient. It also allows for easy porting to the STL <list> implementation.
*
*
* @param[in]  list - a list of primes, of class PrimeList, for values to be pulled from
* @param[in]  highBound - the highest number for which pairs will be outputted to
*
*****************************************************************************/
void lessThan(PrimeList *list, unsigned long highBound)
{
	unsigned long first = 0;
	unsigned long second = 0;
	unsigned long temp = 0;  // Declare vars for storing the received values in temporarily
	do
	{
		first = second;

		second = list->getNext(second);//grab second pair val

		if (second - first == 2)
			cout << "(" << first << ", " << second << ")" << endl;

	} while (second != 0 && second < highBound); //go through entire list
}

/**************************************************************************//** 
 * @author Remington Bullis
 * 
 * @par Description: 
 *      This function displays all twin-prime pairs consisting of numbers less than or equal to
 * a defined value. It finds the first value in teh list, stores it, grabs the second
 * value, compares those two values agains the upper bound. If the values are within 
 * bounds and the none of the values in the pair have been previously used, then the 
 * function prints the pair to the screen. The checking for previously-used values is 
 * necessary as the second value in the first pair (e.g. (1,2)) becomes the first value
 * in the second pair (e.g. (2,3)), meaning only every-other pair should be outputted.
 * While this is not optimal behavior, it is a simple way to process the information and 
 * is decently efficient. It also allows for easy porting to the STL <list> implementation.
 * 
 * 
 * @param[in]  list - a list of primes, of class PrimeList, for values to be pulled from
 * @param[in]  highBound - the highest number for which pairs will be outputted to
 * 
 *****************************************************************************/

/**************************************************************************//** 
 * @author Remington Bullis
 * 
 * @par Description: 
 *      This function displays all twin-prime pairs consisting of numbers less than or equal to
 * a defined value. It finds the first value in teh list, stores it, grabs the second
 * value, compares those two values agains the upper bound. If the values are within 
 * bounds and the none of the values in the pair have been previously used, then the 
 * function prints the pair to the screen. The checking for previously-used values is 
 * necessary as the second value in the first pair (e.g. (1,2)) becomes the first value
 * in the second pair (e.g. (2,3)), meaning only every-other pair should be outputted.
 * While this is not optimal behavior, it is a simple way to process the information and 
 * is decently efficient. It also allows for easy porting to the STL <list> implementation.
 * 
 * 
 * @param[in]  list - a list of primes, of class PrimeList, for values to be pulled from
 * @param[in]  highBound - the highest number for which pairs will be outputted to
 * 
 *****************************************************************************/

void lessThanEqualTo(PrimeList * list, unsigned long highBound)
{
    unsigned long first = 0;
    unsigned long second = 0;
    unsigned long temp = 0; //declare vars for storing pair values
    do
    {
        first = second;

        second = list->getNext(second);//grab second pair val

        if (second - first == 2)
            cout << "(" << first << ", " << second << ")" << endl;

    } while (second != 0 && second <= highBound); //go through entire list
}

/**************************************************************************//** 
 * @author Remington Bullis
 * 
 * @par Description: 
 *      This function displays all twin-prime pairs consisting of numbers greater than 
 * a defined value. It finds the first value in teh list, stores it, grabs the second
 * value, compares those two values agains the upper bound. If the values are within 
 * bounds and the none of the values in the pair have been previously used, then the 
 * function prints the pair to the screen. The checking for previously-used values is 
 * necessary as the second value in the first pair (e.g. (1,2)) becomes the first value
 * in the second pair (e.g. (2,3)), meaning only every-other pair should be outputted.
 * While this is not optimal behavior, it is a simple way to process the information and 
 * is decently efficient. It also allows for easy porting to the STL <list> implementation.
 * 
 * 
 * @param[in]  list - a list of primes, of class PrimeList, for values to be pulled from
 * @param[in]  lowBound - the highest number for which pairs will be outputted from
 * 
 *****************************************************************************/

void greaterThan(PrimeList * list, unsigned long lowBound)
{
    unsigned long first = 0;
    unsigned long second = 0;
    unsigned long temp = 0; //declare vars for storing pair vals
    do
    {
            first = second;

            second = list->getNext(second);//grab second pair val

            if (second - first == 2)
                cout << "(" << first << ", " << second << ")" << endl;

        } while (second != 0 && second > lowBound); //go through entire list

}
/**************************************************************************//** 
 * @author Remington Bullis
 * 
 * @par Description: 
 *      This function displays all twin-prime pairs consisting of numbers greater than or equal to 
 * a defined value. It finds the first value in teh list, stores it, grabs the second
 * value, compares those two values agains the upper bound. If the values are within 
 * bounds and the none of the values in the pair have been previously used, then the 
 * function prints the pair to the screen. The checking for previously-used values is 
 * necessary as the second value in the first pair (e.g. (1,2)) becomes the first value
 * in the second pair (e.g. (2,3)), meaning only every-other pair should be outputted.
 * While this is not optimal behavior, it is a simple way to process the information and 
 * is decently efficient. It also allows for easy porting to the STL <list> implementation.
 * 
 * 
 * @param[in]  list - a list of primes, of class PrimeList, for values to be pulled from
 * @param[in]  lowBound - the highest number for which pairs will be outputted from
 * 
 *****************************************************************************/

void greaterThanEqualTo(PrimeList *list, unsigned long lowBound)
{
    unsigned long first = 0;
    unsigned long second = 0;
    unsigned long temp = 0; //declare vars to store pair vals in
    do
    {
        first = second;

        second = list->getNext(second);//grab second pair val

        if (second - first == 2)
            cout << "(" << first << ", " << second << ")" << endl;
       
    } while (second != 0 && second >= lowBound); //go through entire list
}

/**************************************************************************//** 
 * @author Remington Bullis
 * 
 * @par Description: 
 *      This function displays all twin-prime pairs consisting of numbers between a lower 
 * bound and a higher bound, inclusive. It finds the first value in teh list, stores it, grabs the second
 * value, compares those two values agains the upper bound. If the values are within 
 * bounds and the none of the values in the pair have been previously used, then the 
 * function prints the pair to the screen. The checking for previously-used values is 
 * necessary as the second value in the first pair (e.g. (1,2)) becomes the first value
 * in the second pair (e.g. (2,3)), meaning only every-other pair should be outputted.
 * While this is not optimal behavior, it is a simple way to process the information and 
 * is decently efficient. It also allows for easy porting to the STL <list> implementation.
 * 
 * 
 * @param[in]  list - a list of primes, of class PrimeList, for values to be pulled from
 * @param[in]  lowBound - the highest number for which pairs will be outputted from
 * @param[in]  highBound - the lowest number for which pairs will be outputted to
 *****************************************************************************/

void range(PrimeList *list,unsigned long lowBound, unsigned long highBound)
{
    unsigned long first = 0;
    unsigned long second = 0;
    unsigned long temp = 0;//declare vars for storing pair vals
    do
    {
        first = second;

        second = list->getNext(second);//grab second pair val

        if (second - first == 2)
            cout << "(" << first << ", " << second << ")" << endl;

    } while (second != 0 && second >= lowBound && second <= highBound); //go through entire list
}


/**************************************************************************//** 
 * @author Tristan Anastas
 * 
 * @par Description: 
 *     Displays the twin primes less than the upper bound.
 * 
 * @param[in]  list - a list of primes, of class PrimeList, for values to be pulled from
 * @param[in]  highBound - the highest number for which pairs will be outputted to
 * 
 *****************************************************************************/
void mylessThan(PrimeList *list, unsigned long highBound)
{
    unsigned long p = 0;
    unsigned long c = 0;

    do
    {
        p = c;
        c = list->getNext(c);
        if (c - p == 2)
        {
            cout << "(" << p << "," << c << ")\n";
        }
    } while (c != 0 && list->getNext(c) < highBound);
}

/**************************************************************************//** 
 * @author Tristan Anastas
 * 
 * @par Description: 
 *     Displays the twin primes less than the upper bound.
 * 
 * @param[in]  list - a list of primes, of class PrimeList, for values to be pulled from
 * @param[in]  highBound - the highest number for which pairs will be outputted to
 * 
 *****************************************************************************/
void mylessThanEqualTo(PrimeList *list, unsigned long highBound)
{
    unsigned long p = 0;
    unsigned long c = 0;

    do
    {
        p = c;
        c = list->getNext(c);
        if (c - p == 2)
        {
            cout << "(" << p << "," << c << ")\n";
        }
    } while (c != 0 && list->getNext(c) <= highBound);
}

/**************************************************************************//** 
 * @author Tristan Anastas
 * 
 * @par Description: 
 *     Displays the twin primes less than the upper bound.
 * 
 * @param[in]  list - a list of primes, of class PrimeList, for values to be pulled from
 * @param[in]  lowBound - the lowest number for which pairs will be outputted to
 * 
 *****************************************************************************/
void mygreaterThan(PrimeList *list, unsigned long lowBound)
{
    unsigned long p = 0;
    unsigned long c = 0;

    do
    {
        p = c;
        c = list->getNext(c);
        if (c - p == 2)
        {
            cout << "(" << p << "," << c << ")\n";
        }
    } while (c != 0 && list->getNext(p) > lowBound);
}

/**************************************************************************//** 
 * @author Tristan Anastas
 * 
 * @par Description: 
 *     Displays the twin primes less than the upper bound.
 * 
 * @param[in]  list - a list of primes, of class PrimeList, for values to be pulled from
 * @param[in]  lowBound - the highest number for which pairs will be outputted to
 * 
 *****************************************************************************/
void mygreaterThanEqualTo(PrimeList *list, unsigned long lowBound)
{
    unsigned long p = 0;
    unsigned long c = 0;

    do
    {
        p = c;
        c = list->getNext(c);
        if (c - p == 2)
        {
            cout << "(" << p << "," << c << ")\n";
        }
    } while (c != 0 && list->getNext(p) >= lowBound);
}

/**************************************************************************//** 
 * @author Tristan Anastas
 * 
 * @par Description: 
 *     Displays the twin primes within the range.
 * 
 * @param[in]  list - a list of primes, of class PrimeList, for values to be pulled from
 * @param[in]  highBound - the highest number for which pairs will be outputted to
 * @param[in]  lowBound - the lowest number for which pairs will be outputted to
 * 
 *****************************************************************************/
void myrange(PrimeList *list, unsigned long lowBound, unsigned long highBound)
{
    unsigned long p = 0;
    unsigned long c = 0;

    do
    {
        p = c;
        c = list->getNext(c);
        if (c - p == 2)
        {
            cout << "(" << p << "," << c << ")\n";
        }
    } while (c != 0 && list->getNext(c) < highBound && list->getNext(p) > lowBound);
}