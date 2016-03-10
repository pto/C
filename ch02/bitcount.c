#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int bitcount(unsigned x);

main(int argc, char *argv[])
{
	unsigned long in_value;
	unsigned value;

	if (argc != 2) {
		fputs("usage: bitcount <value>", stderr);
		return 1;
	}

	errno = 0;
	value = in_value = strtoul(argv[1], NULL, 0);
	if (value != in_value) {
		fputs("bitcount: number too large", stderr);
		return 1;
	}
	if (errno != 0) {
		perror("bitcount");
		return 1;
	}

	printf("0x%x has %d bits set\n", value, bitcount(value));

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
