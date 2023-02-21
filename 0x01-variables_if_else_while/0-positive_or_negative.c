#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 *main - Prints positive, zero, or negative
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	/* your code goes there */
	if (n > 0)
	{
		printf("%d is positive\n", n);
	}
	if (n < 0)
	{
		printf("%d is negative\n", n);
	}
	if (n == 0)
	{
		printf("%d is zero\n", n);
	}
<<<<<<< HEAD
	else if (n == 0)
	{       
        printf("%d is zero\n", n);
        } 
	else
	{       
        printf("%d is negative\n", n);
        } 
=======
>>>>>>> 8c5dd04ba28da4496dc380a696589a8add99a510
	return (0);
}

