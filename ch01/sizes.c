#include <stdio.h>

#define DISPLAY(type) printf("sizeof(" #type ") is %zu\n", sizeof(type))

int main(void)
{
	DISPLAY(int);
	DISPLAY(float);
	DISPLAY(char);
	DISPLAY(short);
	DISPLAY(long);
	DISPLAY(long long);
	DISPLAY(double);
	DISPLAY(long double);

	return 0;
}
