# Printf implementation in C
Rebuilding the classic printf function in C. This project handles dynamic formatting (%d, %f, %s, %c) using raw pointers, stack memory management, and custom math algorithms.

# Overview
* outChar() ; takes one single letter from string and sends it to putchar(). <br />

* putchar() ; used to write a single character to standard output. <br />

* outStr() ; it's pointer goes through every letter in the string until end of string sign accurs ('\0'). <br />

* outDec() ; checks if parameter 'x' is equal to zero or if it is a negative number. This function checks these two cases and gives the parameter to outNum() function. <br />

* outDouble() ; gives out floating point number by combining outDec() function to return integer part of a number and basic math algorithms to calculate fractional part of a number ( eight decimal places ). <br />

* outNum() ; Uses recursion to reverse the order of printing using the Memory Stack.


