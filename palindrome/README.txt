In the palindrome_test.c we freed up the memory that was allocated by the palindrome function. By storing the result of palindrome in a variable and then freeing after the assert(which uses the string from palindrome) we stop any potential memory leaks.
we also freed "rev" in the palindrom function.
