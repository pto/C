#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *reps_s = getenv("reps");
	int reps = reps_s ? atoi(reps_s) : 10;

	char *msg = getenv("msg");
	if (!msg)
		msg = "Hi!";

	for (int i = 0; i < reps; i++)
		printf("%s\n", msg);

	exit(EXIT_SUCCESS);
}
