#include <stdio.h>

int atoi(char s[]);

main(int argc, char *argv[])
{
	if (argc != 2) {
		printf("usage: atoi <string to convert>\n");
		return 1;
	}

	printf("%d\n", atoi(argv[1]));

	return 0;
}

/* atoi:  convert s to integer */
int atoi(char s[])
{
	int i, n;

	n = 0;
	for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
		n = 10 * n + (s[i] - '0');
	return n;
}
