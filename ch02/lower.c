#include <stdio.h>

int lower(int c);

main(int argc, char *argv[])
{
	if (argc != 2) {
		printf("usage: lower <character to convert>\n");
		return 1;
	}

	printf("%c\n", lower(argv[1][0]));

	return 0;
}

/* lower:  convert c to lower case; ASCII only */
int lower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return c + 'a' - 'A';
	else
		return c;
}
