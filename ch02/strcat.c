#include <stdio.h>
#include <string.h>

void _strcat(char s[], char t[]);

main(int argc, char *argv[])
{
	char buffer[BUFSIZ];

	if (argc != 3) {
		fprintf(stderr, "usage: strcat <first string> <second string>\n");
		return 1;
	}

	if (strlen(argv[1]) + strlen(argv[2]) > BUFSIZ-1) {
		fprintf(stderr, "strcat: string too long\n");
		return 1;
	}

	buffer[0] = '\0';
	_strcat(buffer, argv[1]);
	_strcat(buffer, argv[2]);
	printf("%s\n", buffer);

	return 0;
}

/* _strcat:  concatenate t to end of s; s must be big enough */
void _strcat(char s[], char t[])
{
	int i, j;

	i = j = 0;
	while (s[i] != '\0')	/* find end of s */
		i++;
	while ((s[i++] = t[j++]) != '\0')	/* copy t */
		;
}
