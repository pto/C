#include <stdio.h>
#include <stdlib.h>

int bitcount(unsigned x);

main(int argc, char *argv[])
{
	unsigned value;

	if (argc != 2) {
		printf("usage: bitcount <value>\n");
		return 1;
	}

	value = strtoul(argv[1], NULL, 0);
	printf("%d\n", bitcount(value));

	return 0;
}

/* bitcount:  count 1 bits in n */
int bitcount(unsigned x)
{
	int b;

	for (b = 0; x != 0; x >>= 1)
		if (x & 01)
			b++;
	return b;
}
