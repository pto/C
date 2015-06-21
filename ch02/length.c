#include <stdio.h>

int xstrlen(char s[]);

main(int argc, char *argv[])
{
	if (argc != 2) {
		printf("usage: length <string to test>\n");
		return 1;
	}

	printf("%d\n", xstrlen(argv[1]));

	return 0;
}

/* xstrlen:  return length of s */
int xstrlen(char s[])
{
	int i;

	i = 0;
	while (s[i] != '\0')
		++i;
	return i;
}
