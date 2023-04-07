#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>

/* Prototype for _putchar function */
int _putchar(char c);
/* Prototype for a function that converts a binary number to an unsigned int*/
unsigned int binary_to_uint(const char *b);
/* Protottype for a function that prints the binary */
void print_binary(unsigned long int n);
/* Prototype for a function that returns the value of a bit at a given index*/
int get_bit(unsigned long int n, unsigned int index);
/* Prototype for a function that sets the value of a bit to 1*/
int set_bit(unsigned long int *n, unsigned int index);
/*Prototype for a function that sets the value of a bit to 0 at a given index*/
int clear_bit(unsigned long int *n, unsigned int index);
/*Prototype for a function that returns the number of bits*/
unsigned int flip_bits(unsigned long int n, unsigned long int m);
/*Prototype for function that checks the endianness*/
int get_endianness(void);
#endif /* MAIN_H */
