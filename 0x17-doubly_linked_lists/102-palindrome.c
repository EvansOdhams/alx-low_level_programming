#include <stdio.h>

/**
 * isPalindrome - Check if a number is a palindrome
 * @number: The number to check
 *
 * Return: 1 if the number is a palindrome, 0 otherwise
 */
int isPalindrome(int number)
{
int originalNumber = number;
int reversedNumber = 0;

while (number > 0)
{
reversedNumber = reversedNumber * 10 + number % 10;
number /= 10;
}

return (originalNumber == reversedNumber);
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
int largestPalindrome = 0;

for (int i = 999; i >= 100; i--)
{
for (int j = i; j >= 100; j--)
{
int product = i * j;
if (isPalindrome(product) && product > largestPalindrome)
{
largestPalindrome = product;
}
}
}

FILE *file = fopen("102-result", "w");
if (file != NULL)
{
fprintf(file, "%d", largestPalindrome);
fclose(file);
}

return (0);
}
