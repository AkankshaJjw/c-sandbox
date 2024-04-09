#include "stdint.h"
#include <stdio.h>
#include <stdbool.h>

// Using the #define statement, how would you declare a manifest constant that returns the number of seconds in a year? Disregard leap years in your answer.
#define NUM_SEC_IN_YEAR (365UL*24*60*60) //this would cast the whole expression to unsigned long

#define MIN(A,B) ((A) <= (B) ? (A) : (B))
// Given an integer variable a, write two code fragments. 
// The first should set bit 3 of a. The second should clear bit 3 of a. In both cases, the remaining bits should be unmodified.
int reverseNumber(int num);
bool isPowerOfTwo(int n);
/*
int a; // An integer

int *a; // A pointer to an integer

int **a; // A pointer to a pointer to an integer

int a[10]; // An array of 10 integers

int *a[10]; // An array of 10 pointers to integers

int (*a)[10]; // A pointer to an array of 10 integers

int (*a)(int); // A pointer to a function a that takes an integer argument and returns an integer

int (*a[10])(int); // An array of 10 pointers to functions that take an integer argument and return an integer
*/

int main()
{
    // assuming indexing starts from the left. If it started from the right bit mask woild be (0x1 << 3) instead
    int a= 0x00000000;
    printf("a:%x\n", a);
    int num_bits_a = sizeof(a) * 8;
    printf("num bits in a:%d\n", num_bits_a);
    a = a  | (0x1 <<29);
    printf("a:%x\n", a);
    a = a & ~(0x1 <<29);
    printf("a:%x\n", a);   

    // // On a certain project it is required to set an integer variable at the absolute address 0x67a9 to the value 0xaa55. 
    // // The compiler is a pure ANSI compiler. Write code to accomplish this task.
    // int* address = (int *)0x67a9;
    // *address = 0xaa5;

    unsigned int num = 0x12345678;
    printf("Original: 0x%x\n", num);
    printf("Reversed: 0x%x\n", reverseNumber(num));

    isPowerOfTwo(31) ? printf("Yes\n") : printf("No\n");
    isPowerOfTwo(64) ? printf("Yes\n") : printf("No\n");

    return 0;
}

// reverse bits in a 32bit hex number
int reverseNumber(int num) {
    int reversedNum = 0;
    for(int i = 0; i <32; i++) {
        reversedNum = reversedNum << 1;
        int lastDigit = num & 1;
        reversedNum |=  lastDigit;
        num = num >> 1;
    }
    return reversedNum;
}

bool isPowerOfTwo(int n)
{
    if (n == 0)
        return 0;
    while (n != 1) {
        if (n % 2 != 0)
            return 0;
        n = n / 2;
    }
    return 1;
}

