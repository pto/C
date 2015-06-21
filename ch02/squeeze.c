#include <stdio.h>

void squeeze(char s[], int c);

main(int argc, char *argv[])
{
	if (argc != 3) {
		printf("usage: squeeze <string to squeeze> <character to remove>\n");
		return 1;
	}

	squeeze(argv[1], argv[2][0]);
	printf("%s\n", argv[1]);

	return 0;
}

/* squeeze:  delete all c from s */
void squeeze(char s[], int c)
{
	int i, j;

	for (i = j = 0; s[i] != '\0'; i++)
		if (s[i] != c)
			s[j++] = s[i];
	s[j] = '\0';
}
