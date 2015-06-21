#include <stdio.h>
#include <stdlib.h>

unsigned getbits(unsigned x, int p, int n);

main(int argc, char *argv[])
{
	unsigned value;
	int position;
	int bits;

	if (argc != 4) {
		printf("usage: getbits <value> <position> <bit count>\n");
		return 1;
	}

	value = strtoul(argv[1], NULL, 0);
	position = atoi(argv[2]);
	bits = atoi(argv[3]);

	printf("0x%x\n", getbits(value, position, bits));

	return 0;
}

/* getbits:  get n bits from position p */
unsigned getbits(unsigned x, int p, int n)
{
	return (x >> (p+1-n)) & ~(~0 << n);
}
