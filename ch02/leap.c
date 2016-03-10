#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

main(int argc, char *argv[])
{
	int year;

	if (argc != 2) {
		printf("usage: leap <year>\n");
		return 1;
	}

	errno = 0;
	year = strtol(argv[1], NULL, 0);
	if (errno != 0) {
		perror("strtol");
		return 1;
	}

	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		printf("%d is a leap year\n", year);
	else
		printf("%d is not a leap year\n", year);

	return 0;
}
