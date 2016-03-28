/*
 * Filename: charCompare.s
 * Author: Diana Ho
 * UserID: cs30xje
 * Description: Checks to make sure the value of the first argument is within
 *              the range of minRange and maxRange, inclusive. 
 * Date: February 18, 2015
 * Sources of Help: PA3 Write up, Piazza, Discussion notes, Classmates
 */

    .global charCompare ! Declares the symbol to be globally visible so
                        ! we can call this function from other modules

    .section ".text"    ! The text segment begins here

/*
 * Function name: charCompare()
 * Function prototype: int charCompare(const void *ptr1, const void *ptr2);
 * Description: Compares the two characters
 * Parameters:
 *      arg 1:  void pointer
 *      arg 2:  void pointer
 * Side Effects: Returns a value less than zero if ptr1 is less than ptr2
 *               Returns a value greater than zero if ptr1 is greather 
 *               than ptr 2
 *               Reutns 0 if both values are equal
 * Error Conditions: None
 * Return Value: Less than 0, 0, or greater than 0
 *
 * Registers Used:
 *      %o0 - arg 1 -- first pointer
 *      %o1 - arg 2 -- second pointer
 */

charCompare:

    ldub    [%o0], %o0      ! Load the value of ptr1 into output register
    ldub    [%o1], %o1      ! Load the value of ptr2 into output register
    sub     %o0, %o1, %o0   ! Find the difference between ptr2 and ptr1

    retl                    ! Return leaf
    nop                     ! Delay slot
