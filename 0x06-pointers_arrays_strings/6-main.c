#include "main.h"
#include <stdio.h>

/**
* main - Entry point
*
* Return: Always 0 (Success)
*/
int main(void)
{
char str[] = "Expect the best. Prepare for the worst.\n"
"Capitalize on what comes.\n"
"hello world! hello-world 0123456hello world\thello world.\n"
"hello world\n";
char *ptr;

ptr = cap_string(str);
printf("%s", ptr);
printf("%s", str);

return (0);
}
