#include <stdio.h>
#include <string.h>

void reverse(char s[]);

main(int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "usage: reverse <string>\n");
		return 1;
	}

	printf("\"%s\" reversed is ", argv[1]);
	reverse(argv[1]);
	printf("\"%s\"\n", argv[1]);

	return 0;
}

/* reverse:  reverse string s in place */
void reverse(char s[])
{
	int c, i, j;

	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
