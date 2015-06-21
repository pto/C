#include <stdio.h>
#include <string.h>

void squeeze(char s[], int c);

main(int argc, char *argv[])
{
	char target[BUFSIZ];

	if (argc != 3) {
		printf("usage: squeeze <string to squeeze> <character to remove>\n");
		return 1;
	}

	strncpy(target, argv[1], BUFSIZ);
	squeeze(target, argv[2][0]);
	printf("%s\n", target);

	return 0;
}

/* squeeze: delete all c from s */
void squeeze(char s[], int c)
{
	int i, j;

	for (i = j = 0; s[i] != '\0'; i++)
		if (s[i] != c)
			s[j++] = s[i];
	s[j] = '\0';
}
