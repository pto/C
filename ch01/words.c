#include <stdio.h>

const int IN = 1;
const int OUT = 0;

int main(void)
{
	int state = OUT;
	int nl = 0, nw = 0, nc = 0;
	int c;

	while ((c = getchar()) != EOF) {
		++nc;
		if (c == '\n')
			++nl;
		if (c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if (state == OUT) {
			state = IN;
			++nw;
		}
	}

	printf("%d %d %d\n", nl, nw, nc);
}
