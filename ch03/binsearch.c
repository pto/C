#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b);
int binsearch(int x, int v[], int n);

main(int argc, char *argv[])
{
	int a[BUFSIZ];
	int target;
	int i;

	if (argc < 3) {
		fprintf(stderr,
			"usage: binsearch <target> <numbers to search>\n");
		return 1;
	}
	target = atoi(argv[1]);
    
	if (argc - 2 > BUFSIZ) {
		fprintf(stderr, "binsearch: too many arguments\n");
		return 1;
	}

	for (i = 0; i < argc - 2; i++)
		a[i] = atoi(argv[i + 2]);

	qsort(a, argc - 2, sizeof a[0], compare);

	printf("Sorted: ");
	for (i = 0; i < argc - 2; i++)
		printf("%d ", a[i]);
	printf("\nResult: %d\n", binsearch(target, a, argc - 2));

	return 0;
}

int compare(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}

/* binsearch:  find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low+high) /  2;
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else    /* found match */
			return mid;
	}
	return -1;   /* no match */
}
