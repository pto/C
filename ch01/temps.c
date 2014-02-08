#include <stdio.h>

// Print Fahrenheit-Celsius table

const int lower = 0;	// Range for temperatures in degrees F
const int upper = 300;
const int step = 20;

int main(void)
{
	for (int fahr = lower; fahr <= upper; fahr += step) {
		float celsius = 5.0 / 9.0 * (fahr - 32.0);
		printf("%3d %6.1f\n", fahr, celsius);
	}

	return 0;
}
