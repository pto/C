#include <stdio.h>

#pragma GCC diagnostic ignored "-Wbuiltin-declaration-mismatch"
int strlen(char s[]);

main(int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "usage: strlen <string>\n");
		return 1;
	}

	printf("%d\n", strlen(argv[1]));

	return 0;
}

/* strlen:  return length of s */
int strlen(char s[])
{
	int i;

	i = 0;
	while (s[i] != '\0')
		++i;
	return i;
}
