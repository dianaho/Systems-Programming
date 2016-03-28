/*
 * Filename: findAnagrams.c
 * Author: Diana Ho
 * Userid: cs30xje
 * Description: Searches through the anagram array in struct anagramInfo
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


/*
 * Function name: findAnagrams() 
 * Function prototype: int findAnagrams( const struct anagramInfo *info,
 *                          struct anagramMatches *matches );
 * Description: This function is reponsible for searching through the
 *              dynamically allocated array pointed to by the anagramPtr
 *              member of struct anagramInfo, and setting pointers to the
 *              first and last matched anagrams inside the struct
 *              anagramMatches argument
 * Parameters:
 *      arg 1: struct anagramInfo  
 *      arg 2: struct anagramMatches
 * Side Effects: None 
 * Error Conditions: 
 * Return Value: The number of anagrams found
 */

int findAnagrams( const struct anagramInfo *info, 
                  struct anagramMatches *matches )
{
    /* Variable declarations */
    struct anagram *search;
    char *strptr;
    int index = 0;
    int count = 0;

    /* Replace the newline character in the word member of the nested
     * struct with a null-terminator */
    strptr = strchr( matches->word.word, '\n' );
    if( strptr != NULL )
        *strptr = '\0';

    /* Copy the characters into the sorted member of the nested struct
     * converting each character to lowercase */
    (void) strcpy( matches->word.sorted, matches->word.word );
    while( index <= strlen( matches -> word.word ) )
    {
        matches->word.sorted[index] = tolower( matches->word.sorted[index] );
        index++;
    }

    /* Sort the sorted member */
    qsort( matches->word.sorted, strlen( matches->word.sorted ),
            sizeof( char ), charCompare );

    /* Use bsearch() and your sortedMemberCompare() function to search
     * for any matching anagrams in the anagramPtr array inside struct
     * anagramInfo */
    search = (struct anagram*) bsearch( &(matches->word), info->anagramPtr,
                    info->numOfAnagrams, sizeof( struct anagram ),
                    sortedMemberCompare );

    /* If no matches are found, set the first and last members of the
     * matches argument to NULL and return 0 */
    if( search == NULL )
    {
        matches -> first = NULL;
        matches -> last = NULL;
        return 0;
    }

    /* If there's only one match set first and last to search pointer */
    matches->first = search;
    matches->last = search;

    /* Use the pointer returned by bsearch to find the first anagram
     * and set the first member of the matches argument to this result */
    while( sortedMemberCompare( search, ( search + 1 )) == 0 )
    {
        matches->last = search;
        search++;
    }
    matches->last = search;

    while( sortedMemberCompare( search, ( search - 1 )) == 0 )
    {
        matches->first = search;
        search--;
        count++;
    }
    matches->first = search;

    /* Count the number of anagrams found and return this value */
    count++;
    
    return count;
}
