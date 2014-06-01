#include <stdio.h>

/* print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300 */

main()
{
	int fahr, celsius;
	int lower, upper, step;
	for (int fahr = lower; fahr <= upper; fahr += step) {
		float celsius = 5.0 / 9.0 * (fahr - 32.0);
		printf("%3d %6.1f\n", fahr, celsius);
	}

	return 0;
}
