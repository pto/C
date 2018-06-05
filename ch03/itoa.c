#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

void reverse(char s[]);
void itoa(int n, char s[]);

main(int argc, char *argv[])
{
	long lvalue;
	int value;
	char buf[BUFSIZ];

	if (argc != 2) {
		fprintf(stderr, "usage: itoa <number>\n");
		return 1;
	}

	errno = 0;
	value = lvalue = strtol(argv[1], NULL, 0);
	if (errno != 0) {
		perror("itoa");
		return 1;
	}
	if (value != lvalue) {
		fprintf(stderr, "itoa: number too large\n");
		return 1;
	}

	itoa(value, buf);

	printf("%s\n", buf);	
}

/* itoa:  convert n to characters in s */
void itoa(int n, char s[])
{
	int i, sign;

	if ((sign = n) < 0)  /* record sign */
		n = -n;		  /* make n positive */
	i = 0;
	do {	   /* generate digits in reverse order */
		s[i++] = n % 10 + '0';   /* get next digit */
	} while ((n /= 10) > 0);	 /* delete it */
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}


/* reverse:  reverse string s in place */
void reverse(char s[])
{
	int c, i, j;

	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i], s[i] = s[j], s[j] = c;
	}
}
