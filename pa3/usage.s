/*
 * Filename: usage.s
 * Author: Diana Ho
 * UserID: cs30xje
 * Description: Outputs the usage message
 * Date: February 23, 2015
 * Sources of Help: PA3 Write up, Piazza, Discussion notes, Classmates
 */

    .global usage           ! Declares the symbol to be globally visible so
                            ! we can call this function from other modules

    .section ".text"        ! The text segment begins here

/*
 * Function name: usage()
 * Function prototype: void usage( const char *programName ) 
 * Description: This routine outputs the usage message with the name of
 *              the program passed in as the only argument 
 * Parameters:
 *      arg 1:  Pointer to the program name
 * Side Effects: 
 * Error Conditions: None
 * Return Value: Void
 *
 * Registers Used:
 *      %l0 -- stdError
 *      %l1 -- STR_USAGE
 */

usage:

    save    %sp, -96, %sp

    set     stdError, %l0       ! Copy the stdError variable
    ld      [%l0], %o0          ! Dereference the pointer
    set     STR_USAGE, %l1      ! Usage message to be printed
    ld      [%l1], %o1          ! Dereference the char* to get the string
    mov     %i0, %o2            ! Get the program name
    call    fprintf
    nop

    ret
    restore
