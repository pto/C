#include <stdio.h>
#include <stdlib.h>

int binsearch(int x, int v[], int n);

main(int argc, char *argv[])
{
	int a[BUFSIZ];
	int target;
    int previous;
	int i;

	if (argc < 3) {
		printf("usage: binsearch <target> <sorted numbers to search>\n");
		return 1;
	}
	target = atoi(argv[1]);
    
	for (i = 0; i < argc - 2; i++) {
		if (i > BUFSIZ - 1) {
			printf("binsearch: too many arguments\n");
			return 1;
		}
		a[i] = atoi(argv[i + 2]);
	}

    previous = a[0];
    for (i = 1; i < argc - 2; i++) {
        if (a[i] < previous) {
            printf("binsearch: array not sorted\n");
            return 1;
        }
        previous = a[i];
    }

	printf("%d\n", binsearch(target, a, argc - 1));

	return 0;
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
