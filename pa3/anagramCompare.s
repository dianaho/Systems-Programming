/*
 * Filename: anagramCompare.s
 * Author: Diana Ho
 * UserID: cs30xje
 * Description: Compares two words to see if they are anagrams 
 * Date: February 18, 2015
 * Sources of Help: PA3 Write up, Piazza, Discussion notes, Classmates
 */

    .global anagramCompare  ! Declares the symbol to be globally visible so
                            ! we can call this function from other modules

    .section ".text"        ! The text segment begins here

/*
 * Function name: anagramCompare()
 * Function prototype: int anagramCompare(const void *p1, const void *p2);
 * Description: Compares the words
 * Parameters:
 *      arg 1:  void pointer
 *      arg 2:  void pointer
 * Side Effects: Calls strcmp on sorted member of the struct anagram. If it
 *               returns 0, make another call to strcmp on the word members
 *               of struct anagram
 * Error Conditions: None
 * Return Value: Return the value of strcmp
 *
 * Registers Used:
 *      %l0 - Stores SORTED_OFFSET
 *      %l2 - Stores WORD_OFFSET
 */

anagramCompare:

    save    %sp, -96, %sp

    set     SORTED_OFFSET, %l0      ! Copy the global definition into local
    ld      [%l0], %l0             ! Load the value into local reg 1

    set     WORD_OFFSET, %l2        ! Copy the global definition into local
    ld      [%l2], %l2              ! Loads the value into local reg 3

    add     %i0, %l0, %o0           ! Get the offset position with SORTED
    add     %i1, %l0, %o1           ! Get the offset position with SORTED

    call    strcmp                  ! Compare the two strings
    nop

    cmp     %o0, %g0                ! Check to see if return value of
    be      CMP_WORD                ! strcmp is 0
    nop

    ba      END
    nop


CMP_WORD:
    add     %i0, %l2, %o0           ! Get offset position with WORD
    add     %i1, %l2, %o1           ! Get offset position with WORD

    call    strcmp                  ! Compare the strings
    nop
  
END: 
    mov     %o0, %i0                ! Return value of strcmp

    ret
    restore
