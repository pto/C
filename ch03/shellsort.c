#include <stdio.h>
#include <stdlib.h>

void shellsort(int v[], int n);

main(int argc, char *argv[])
{
	int a[BUFSIZ];
	int i;

	if (argc < 2) {
		fprintf(stderr, "usage: shellsort <numbers to sort>\n");
		return 1;
	}

	if (argc - 1 > BUFSIZ) {
		fprintf(stderr, "shellsort: too many arguments\n");
		return 1;
	}

	for (i = 0; i < argc - 1; i++) {
		a[i] = atoi(argv[i + 1]);
	}

	shellsort(a, argc - 1);

	for (i = 0; i < argc - 1; i++) {
		printf("%5d", a[i]);
		putchar((i%10 == 9 || i == argc - 2)? '\n':' ');
	}

	return 0;
}

/* shellsort:  sort v[0]...v[n-1] into increasing order */
void shellsort(int v[], int n)
{
	int gap, i, j, temp;

	for (gap = n/2; gap > 0; gap /= 2)
		for (i = gap; i < n; i++)
			for (j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap) {
				temp = v[j];
				v[j] = v[j+gap];
				v[j+gap] = temp;
			}
}
