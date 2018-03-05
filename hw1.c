/* 
 * File:   hw1.c
 * Author: mohibkohi
 *
 * Created on April 11, 2016, 3:47 PM
 */

#include <stdio.h>
//#include <stdlib.h>
#include <math.h>

/**
 * Main runs the program.
 * @return 0;
 */
int main(void) {
    
    char myR;
    //do while statement 
    do {
        printf("What type of display do you want? \n");
        printf("Enter 1 for character parity, 2 for integer checksum: ");
        
        int x, y, num;
        scanf("%d", &x);
        
        char charac;
        //if user selects the character parity
        if (x == 1) {

            printf("Enter a character for parity calculation: ");
            //the typed character
            scanf(" %c", &charac);
           
            printf("Character: %c, Bit representation: ", charac);
            //change the character to a binary from the ASCHI
            int countOnes = toBinary(charac, 8);
            printf("\nNumber of ones: %d ", countOnes);
            printf("\nEven 1 parity for the character is: ");
            //if the number of ones is even
            if (countOnes % 2 == 0) {
                //just print the same binary
                toBinary(charac, 8);
            } else {    //if the number of ones is odd
                //add one and print the binary.
                printf("%d", 1);
                toBinary(charac, 7);
            }
            printf("\n");
        } else if (x == 2) {    // if the user wants to find the checksum
            printf("Enter an integer for checksum calculation: ");
            //the typed number
            scanf("%d", &y);
            //unsigned number numb
            unsigned int numb = y;
            int count;
            printf("Integer: %d, Bit representation: ", numb);
            //print the 32 bit binary representation of the number
            toBinary(numb, 32);
            //count the checksum
            count = checkSum(y, 32);
            
            printf("Sum of the number is: %d \n", count);
            int result = count % 255;
            printf("Checksum of the number is: %d, Bit representation: ", result);
            //print the 8 bit binary of the checksum
            toBinary(result, 8);
            printf("\n");
        }
        
        printf("\nEnter r to repeat, q to quit: ");
        //scan the next character
        scanf(" %c", &myR);
    } while (myR != 'q' && myR == 'r');

    return 0;
}

/**
 * Change number to the given bits of binary.
 * @param decimal to change to binary.
 * @param bits to change the binary into.
 * @return the number of ones in the binary number.
 */
int toBinary(int decimal, int bits) {
    int i;
    //Binary Left Shift Operator
    int mask = 1 << bits - 1;
    int countOnes = 0;
    for (i = 1; i <= bits; i++) {
        //copies a bit to the result if it exists in both operands
        if (decimal & mask) {
            countOnes++;
            putchar('1');
        }
        else {
            putchar('0');
        }
        //Binary Left Shift Operator
        decimal <<= 1;
        if (!(i % 8)) {
            putchar(' ');
        }
    }
    return countOnes;
}

/**
 * Calculate the checksum of the given number.
 * @param decimal to change to binary.
 * @param bits to change the binary into.
 * @return checksum of the number.
 */
int checkSum(int decimal, int bits) {
    int i;
    //Binary Left Shift Operator
    int mask = 1 << bits - 1;
    int count = 0;
    int total = 0;
    int x = 7;
    for (i = 1; i <= bits; i++) {
        //copies a bit to the result if it exists in both operands
        if (decimal & mask) {
            count += pow(2,x);
        }
        x--;  
        //Binary Left Shift Operator
        decimal <<= 1;
        if(x == -1) { 
            total += count;
            count = 0;
            x = 7;
        }
    }
    printf("\n");
    return total;
}
