/*
 * Filename: main.c
 * Author: Diana Ho
 * UserID: cs30xje
 * Description: Read in the command line arguments 
 * Date: February 23, 2015
 * Sources of Help: PA3 Write up, Piazza, Discussion notes, Classmates
 */
 
/*
 * Header files included here
 */

/* Std C Library headers */
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

/* Local headers */
#include "pa3.h"
#include "pa3_strings.h"

/*
 * Function name: main()
 * Function prototype: int main( int argc, char *argv[] );
 * Description: This function will drive the rest of the program. It will
 *              perform five tiers of input checking and if all input is
 *              valid it will call displayPlus().
 * Parameters:
 *      Arg 1:  argument count
 *      Arg 2:  argument vector
 * Side Effects: Prints usage message and calls exit if the wrong number
 *               of input arguments are given or if input arguments can't
 *               be converted to longs. Prints error message if the size
 *               argument is not odd or if input arguments are not within
 *               their required range. Prings usage message if the plus,
 *               fill, and border chars are not all unique.
 * Error Conditions: None
 * Return Value: 0 indicating successful execution.
 */

int main( int argc, char *argv[] )
{
    /* Declare variables */
    struct anagramInfo info;
    struct anagramMatches matches;
    int makeTable;
    int results;

    /* Check if argc is not equal to EXPECTED_ARGS. If this is the case,
     * call usage() and return EXIT_FAILURE */
    if( argc != EXPECTED_ARGS )
    {
        usage( argv[0] );
        return EXIT_FAILURE;
    } 

    /* Call makeAnagramTable passing in the appropriate arguments and
     * then checking the return value. If it returns a non-zero value,
     * call perror(), usage, and return EXIT_FAILURE */
    makeTable = makeAnagramTable( argv[1], &info );
    if( makeTable != 0 )
    {
        perror( STR_ERR_MAKE_ANAGRAM_TABLE );
        usage( argv[0] );
        return EXIT_FAILURE;
    }

    /* Create a struct anagramMatches object on the stack, zero-fill the
     * nested struct anagram member using memset() */
    (void) memset( &(matches.word), 0, sizeof( struct anagram ));

    /* Display the search string to stdout */
    (void) fprintf( stdout, STR_SEARCH );

    /* Use fgets() to read input from stdin, storing results into
     * the word member of the nested struct anagram in anagramMatches */
    while( fgets( matches.word.word, SIZE, stdin ) != NULL )
    {
        /* Call findAnagrams followed by displayAnagrams */
        results = findAnagrams( &info, &matches );
        displayAnagrams( results, &matches );    
        /* Zero-fill the struct again, and print the search string */
        (void) memset( &(matches.word), 0, sizeof( struct anagram ));
        (void) fprintf( stdout, STR_SEARCH );
    }

    /* Else if fgets() returned NULL, free the dynamically allocated
     * memory that anagramPtr is pointing to, print the newline string 
     * and return exit success */
    free( info.anagramPtr );
    (void) fprintf( stdout, STR_NEW_LINE );

    return EXIT_SUCCESS; 
}
