#include <stdio.h>

int xstrlen(char s[]);

main()
{
	printf("%d\n", xstrlen("hello, world\n"));
}

/* xstrlen: return length of s */
int xstrlen(char s[])
{
	int i;

	i = 0;
	while (s[i] != '\0')
		++i;
	return i;
}
