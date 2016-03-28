/*
 * Filename: displayAnagrams.c
 * Author: Diana Ho
 * Userid: cs30xje
 * Description: Displays the anagrams found by findAnagrams()
 * Date: February 23, 2015
 * Sources of Help: PA3 Write up, Piazza, Discussion notes, friends
 */ 

/* Include files */
#include "pa3.h"
#include "pa3_strings.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

/* Define variables */

/*
 * Function name: displayAnagrams()
 * Function prototype: void displayAnagrams( int count, 
 *                                      struct anagramMatches *matches );
 * Description: This function displays the anagrams found by findAnagrams.c 
 * Parameters:
 *      arg 1: number of anagrams 
 *      arg 2: pointer to struct anagramMatches
 * Side Effects: None 
 * Error Conditions: If count is equal or less than 1 
 * Return Value: Void
 */

void displayAnagrams( int count, struct anagramMatches *matches )
{
    /* Check if the count argument is 0 */
    if( count == 0 )
    {
        /* Print out string and return */
        (void) fprintf( stdout, STR_NO_ANAGRAMS_FOUND );
        return;
    }

    /* If count is 1, check if the anagram is the same as the word
     * entered by performing a case-sensitive comparison using strcmp */
    else if( count == 1 )
    {
        if( strcmp( matches->first->word, matches->word.word ) == 0 )
        {
            /* If words are the same, print message and return */
            (void) fprintf( stdout, STR_NO_ANAGRAMS_FOUND );
            return;
        }

        (void) fprintf( stdout, STR_ANAGRAMS_FOUND);
        (void) fprintf( stdout, STR_ANAGRAM_WORD, matches->first->word );
    }

    /* Check if count is greater than 1 */
    else if( count > 1 )
    {
        /* Print anagram string to stdout */
        (void) fprintf( stdout, STR_ANAGRAMS_FOUND );

        /* Print all anagrams which are not case-sensitive matches
         * of the word entered */
        while( count != 0 )
        {
            if( strcmp( matches->word.word, matches->first->word ) != 0 )
            {
                (void) fprintf( stdout, STR_ANAGRAM_WORD, 
                        matches->first->word );
            }
            matches->first++;
            count--;
        }
    }

    /* Print newline string and return */
    (void) fprintf( stdout, STR_NEW_LINE );
    return;
}
