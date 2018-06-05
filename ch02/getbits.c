#include <stdio.h>
#include <stdlib.h>

unsigned getbits(unsigned x, int p, int n);

main(int argc, char *argv[])
{
	unsigned value;
	int position;
	int bits;

	if (argc != 4) {
		fprintf(stderr, "usage: getbits <value> <position> <bit count>\n");
		return 1;
	}

	value = strtoul(argv[1], NULL, 0);
	position = atoi(argv[2]);
	bits = atoi(argv[3]);

	if (bits > position+1) {
		fprintf(stderr, "getbits: too many bits for the position\n");
		return 1;
	}

	if (bits < 0 || position < 0) {
		fprintf(stderr, "getbits: position and bit count cannot be negative\n");
		return 1;
	}

	printf("%d bit%s in value 0x%x starting at position %d %s value 0x%x\n",
		bits, (bits == 1)?"":"s", value, position, (bits == 1)?"has":"have",
		getbits(value, position, bits));

	return 0;
}

/* getbits:  get n bits from position p */
unsigned getbits(unsigned x, int p, int n)
{
	return (x >> (p+1-n)) & ~(~0 << n);
}
