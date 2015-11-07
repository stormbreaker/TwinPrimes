/*************************************************************************//**
 * @file 
 *
 * @mainpage Prog 2 - Twin Primes
 * 
 * @section course_section Course Information 
 *
 * @author Tristan Anastas, Remington Bullis, Benjamin Kaise,  Eric Vandervort
 * 
 * @date Nov 3, 2014 at 11:59pm
 * 
 * @par Professor: 
 *         Roger Schrader
 * 
 * @par Course: 
 *         CSC250 - M002 -  3:00pm
 * 
 * @par Location: 
 *         Mclaury - 306
 *
 * @section program_section Program Information 
 * 
 * @details This program generates prime numbers, removes the non-twin primes, 
 * and sets up an interface to display the primes.
 *
 * @section compile_section Compiling and Usage 
 *
 * @par Compiling Instructions: 
 *      No special compiling instruction
 * 
 * @par Usage: 
   @verbatim  
   c:\> prog2.exe arg1
   @endverbatim 
 *
 * 
 * @par Modifications and Development Timeline: 
   @verbatim 
   Date          Modification 
   ------------  -------------------------------------------------------------- 
   Oct  20, 2014  Class interface made
   Oct  29, 2014  Started on List class
   Nov   2, 2014  Everything done-ish
   Nov   3, 2014  Testing and completion.
   @endverbatim
 *
 *****************************************************************************/

#include "functions.h"


/**************************************************************************//**
* @author Tristan Anastas
*
* @par Description:
* Main program fucntion, sets the list sends it to functions to be populated. 
* Then starts up the interface.
*
*
*
* @param[in]    argc - number of command line args
* @param[in]    arfv - the upper bound (hopefully)
*
* @returns No returns.
*
*****************************************************************************/
int main(int argc, char *argv[])
{
    PrimeList ourList; 
    int upBnd;

    srand(time(NULL)); // seed random number gen

    upBnd = checkComLine(argc, argv);  // get upper bound

    if (upBnd == -1)
        return 0;

    genPrim(upBnd, &ourList);
    removeNonTwin(&ourList);

    allRand(&ourList, upBnd); // run program

    return 0;
}