#include <stdio.h>

#define do(value) printf("%c is %c\n", value, lower(value))

int lower(int c);

main()
{
	do('H');
	do('h');
	do('3');
}

/* lower: convert c to lower case; ASCII only */
int lower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return c + 'a' - 'A';
	else
		return c;
}
