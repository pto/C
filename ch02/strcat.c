#include <stdio.h>

void xstrcat(char s[], char t[]);

main(int argc, char *argv[])
{
	char buffer[BUFSIZ];

	if (argc != 3) {
		printf("usage: strcat <first string> <second string>\n");
		return 1;
	}

	buffer[0] = '\0';
	xstrcat(buffer, argv[1]);
	xstrcat(buffer, argv[2]);
	printf("%s\n", buffer);

	return 0;
}

/* xstrcat:  concatenate t to end of s; s must be big enough */
void xstrcat(char s[], char t[])
{
	int i, j;

	i = j = 0;
	while (s[i] != '\0')	/* find end of s */
		i++;
	while ((s[i++] = t[j++]) != '\0')	/* copy t */
		;
}
