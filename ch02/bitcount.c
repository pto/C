#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int bitcount(unsigned x);

main(int argc, char *argv[])
{
	unsigned long in_value;
	unsigned value;
	unsigned result;

	if (argc != 2) {
		fprintf(stderr, "usage: bitcount <value>\n");
		return 1;
	}

	errno = 0;
	value = in_value = strtoul(argv[1], NULL, 0);
	if (errno != 0) {
		perror("bitcount");
		return 1;
	}
	if (value != in_value) {
		fprintf(stderr, "bitcount: number too large\n");
		return 1;
	}

	result = bitcount(value);
	printf("0x%x has %d bit%s set\n", value, result, (result==1)?"":"s");

	return 0;
}

/* bitcount:  count 1 bits in x */
int bitcount(unsigned x)
{
	int b;

	for (b = 0; x != 0; x >>= 1)
		if (x & 01)
			b++;
	return b;
}
