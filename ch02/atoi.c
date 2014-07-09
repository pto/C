#include <stdio.h>

#define do(value) printf("%s is %d\n", value, atoi(value))

int atoi(char s[]);

main()
{
	do("123");
	do("-42");
	do("0");
	do("123456789");
}

/* atoi: convert s to integer */
int atoi(char s[])
{
	int i, n;

	n = 0;
	for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
		n = 10 * n + (s[i] - '0');
	return n;
}
