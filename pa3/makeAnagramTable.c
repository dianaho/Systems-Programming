/*
 * Filename: makeAnagramTable.c
 * Author: Diana Ho
 * Userid: cs30xje
 * Description: Creats an array of struct anagram objects on the Heap
 * Date: February 18, 2015
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
 * Function name: makeAnagramTable()
 * Function prototype: int makeAnagramTable( const char* filename,
 *                          struct anagramInfo* info );
 * Description: This function is responsible for creating an array of struct
 *              anagram objects on the Heap using malloc and realloc for
 *              dynamic memory allocation and populating the struct anagramInfo
 *              parameter with the array and number of elements.
 *              Each struct anagram object will contain the original word read
 *              from the dictionary file and a lowercase sorted version of
 *              the word.
 * Parameters:
 *      arg 1:  const char* filename
 *      arg 2:  struct anagramInfo* info
 * Side Effects: None 
 * Error Conditions: If any errors occur during processing the function should
 *                   clean up any resources and return errno.
 * Return Value: Returns errno if any errors occur during processing
 *               Reutrns 0 if there are no errors
 */

int makeAnagramTable( const char* filename, struct anagramInfo* info )
{
    /* Initialize all variables */
    FILE * fp;
    struct anagram *anagramPtr;
    struct anagram *new;
    char *strptr;
    // char word[SIZE];

    int count = 0;
    int index = 0;

    /* Clear errno */
    errno = 0;

    /* Attempt to open filename via fopen() */
    fp = fopen( filename, FILE_OPEN_MODE );

    /* If fopen() returned NULL, return errno */
    if( fp == NULL )
        return errno;

    /* Attempt to allocate memory for the first struct anagram using
     * malloc() or realloc() */
    anagramPtr = ( struct anagram* ) malloc( sizeof( struct anagram));

    /* If null is returned, close the file with fclose() and return errno */
    if( anagramPtr == NULL )
    {
        (void) fclose( fp );
        return errno;
    }

    /* If memory allocation is successful, zero-fill the newly allocated
     * struct with memset() and copy into the word member of the struct
     * the first word in filename using fgets() */
    (void) memset( anagramPtr, 0, sizeof( struct anagram ) );
    //count++;
    
    while( fgets( anagramPtr[count].word, SIZE, fp ) != NULL )
    {
        index = 0;
        /* Using strchr(), replace the newline character if present
         * with a null-terminator */
        strptr = strchr( anagramPtr[count].word, '\n' );
        if( strptr != NULL )
        {
            *strptr = '\0';
        }

        /* Copy the word into the sorted member of the struct converting
         * each character to lowercase using tolower() */
        (void)strcpy( anagramPtr[count].sorted, anagramPtr[count].word );

        while( index <= strlen( anagramPtr[count].sorted ) )
        {
            anagramPtr[count].sorted[index] = 
                tolower( anagramPtr[count].sorted[index] );
            index++;
        }

        //(void)strncpy( anagramPtr[count-1].sorted, word, SIZE);

        /* Using qsort() and charCompare module, sort the sorted member of
         * the anagram struct */
        qsort( anagramPtr[count].sorted, 
                strlen( anagramPtr[count].sorted ),
                sizeof( char ), charCompare );

        /* Use realloc() to increase the size of the dynamically allocated
         * array to make room for another anagram struct */
        new = realloc( anagramPtr, (count + 2)*sizeof(struct anagram));

       /* Check if realloc() fails */
       if( new == NULL )
       {
           /* Release any memory allocated up to this point */
           free( anagramPtr );
           // anagramPtr = NULL;
           free( new );

           /* Close any open files with fclose() */
           (void) fclose( fp );

           /* Return errno */
           return errno;
       }

       /* Else zero-fill the newly allocated struct and attempt to read
        * the next word into the word member. Copy the word into the sorted
        * member, converting each character to lowercase and then sort
        * the sorted member with qsort() */
       anagramPtr = new;
       (void)memset( &(anagramPtr[count+1]), 0, sizeof( struct anagram ) );
       count++;
    }

    /* Sort the dynamically allocated array of anagram structs using
     * qsort() and the assembly module anagramCompare */
    qsort( anagramPtr, count, sizeof( struct anagram ), anagramCompare );

    /* Set the number of anagrams processed into the numOfAnagrams member
     * of the struct anagramInfo argument */
    info -> numOfAnagrams = count;

    /* Set the anagramPtr member to point to the array */
    info -> anagramPtr = anagramPtr;

    /* Return 0 */
    return 0;
}
