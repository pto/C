#include <stdio.h>

#define DISPLAY(type) printf("sizeof(" #type ") is %zu\n", sizeof(type))

/* display size of types in bytes */
main()
{
	DISPLAY(char);
	DISPLAY(short);
	DISPLAY(int);
	DISPLAY(long);
	/* long long is not valid in C89 */
	DISPLAY(float);
	DISPLAY(double);
	DISPLAY(long double);

	return 0;
}
