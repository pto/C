#include <stdio.h>

// Print Fahrenheit-Celsius table for 0, 20, ..., 300 degrees F

int main(void)
{
	int lower = 0;
	int upper = 300;
	int step = 20;

	float fahr = lower;
	while (fahr <= upper) {
		float celsius = 5.0 / 9.0 * (fahr - 32.0);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
	return 0;
}
