/*
 * Filename: sortedMemberCompare.s
 * Author: Diana Ho
 * UserID: cs30xje
 * Description: Compares the sorted members of the anagram struct
 * Date: February 23, 2015
 * Sources of Help: PA3 Write up, Piazza, Discussion notes, Classmates
 */

    .global sortedMemberCompare ! Declares the symbol to be globally 
                                ! visible so we can call this function
                                ! from other modules

    .section ".text"            ! The text segment begins here

/*
 * Function name: sortedMemberCompare()
 * Function prototype: int sortedMemberCompare(const void *p1, 
 *                                          const void *p2);
 * Description: Similar to anagramCompare- compares the sorted members
 *              of the anagram struct and returns a value based on what
 *              strcmp retuns
 * Parameters:
 *      arg 1:  sorted word to compare
 *      arg 2:  sorted word to compare
 * Side Effects: Calls strcmp on sorted member of the struct anagram.
 * Error Conditions: None
 * Return Value: Return the value of strcmp
 *
 * Registers Used:
 *      %l0 - Stores SORTED_OFFSET
 *      %o0 - Stores the return value of strcmp
 */

sortedMemberCompare:

    save    %sp, -96, %sp

    set     SORTED_OFFSET, %l0      ! Saves globally defined variable to use
    ld      [%l0], %l1              ! Copy the value into local register
    
    add     %l1, %i0, %o0           ! Add offset to input 1
    add     %l1, %i1, %o1           ! Add offset to input 2
    call    strcmp  
    nop

    mov     %o0, %i0                ! Move the return value into input reg

    ret
    restore
