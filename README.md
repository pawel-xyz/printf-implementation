# Printf implementation in C
Rebuilding the classic printf function in C. This project handles dynamic formatting (%d, %f, %s, %c) using raw pointers, stack memory management, and custom math algorithms.

# Overview
* `outChar()` : Takes a single character and sends it to standard output using `putchar()`. <br />

* `putchar()` : A built-in C function used to write a single character to the standard output. <br />

* `outStr()` : Uses a pointer to iterate through every character in a string until the null terminator ('\0') occurs. <br />

* `outDec()` ; checks if parameter 'x' is equal to zero or if it is a negative number. This function checks these two cases and gives the parameter to `outNum()` function. <br />

* `outDouble()` : Prints floating-point numbers. It uses outDec() to print the integer part, and custom math algorithms to calculate and print the fractional part (up to eight decimal places). <br />

* `outNum()` : Uses recursion to reverse the order of printed digits by utilizing the call stack. <br />

# What did I learn ? 

-> Implementing and utilizing **Variadic Functions** (`via va_list`, `va_start`, `va_arg`) to dynamically handle an unknown number of arguments.<br />

-> Managing **raw Pointers** for efficient string iteration and direct memory access. <br />

-> How to handle **Integer Promotion** in variadic functions. Specifically, why types like 'char' must be extracted as 'int' via va_arg to prevent stack misalignment and memory corruption.


