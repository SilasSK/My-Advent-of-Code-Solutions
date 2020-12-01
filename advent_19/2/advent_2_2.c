
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX_DIGITS 10

double mass_to_fuel(double mass)
{
	double fuel = (floor(mass / 3) - 2);
	
	if (fuel <= 0) {
		return 0;
	} else {
		return fuel + mass_to_fuel(fuel);
	}
}

int main()
{
	double fuel_sum = 0;

	/* Read in numbers */
	char number_str[MAX_DIGITS];
	while (fgets(number_str, MAX_DIGITS, stdin))
		fuel_sum += mass_to_fuel( atof(number_str) );
	

	printf("%lf\n", fuel_sum);

	return (0);
}