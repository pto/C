#include <stdio.h>
#include <string.h>

main(int argc, char *argv[])
{
	int last;

	if (argc != 2) {
		fprintf(stderr, "usage: trim <string>\n");
		return 1;
	}

	printf("\"%s\" trimmed is ", argv[1]);
	last = trim(argv[1]);
	printf("\"%s\" (last non-space is in position %d)\n", argv[1], last);
}


/* trim:  remove trailing blanks, tabs, newlines */
int trim(char s[])
{
	int n;

	for (n = strlen(s)-1; n >= 0; n--)
		if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
			break;
	s[n+1] = '\0';
	return n;
}
