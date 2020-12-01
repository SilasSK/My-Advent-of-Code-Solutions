
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX_DIGITS 10

/* Count the number of lines in stdin, without affecting the file position */
int count_lines()
{
	long int fpos = ftell(stdin);

	char str[MAX_DIGITS];
	int l = 0;
	while (fgets(str, MAX_DIGITS, stdin))
		l++;

	fseek(stdin, fpos, SEEK_SET); /* Reset file position to before call */
	return l;
}

double mass_to_fuel(double mass)
{
	return floor(mass / 3) - 2;
}

int main()
{
	/* Allocate memory for each number */
	int num_numbers = count_lines();
	long *numbers = malloc((num_numbers) * sizeof(long));

	/* Read in numbers */
	char number_str[MAX_DIGITS];
	int n = 0;
	while (fgets(number_str, MAX_DIGITS, stdin))
		numbers[n++] = atol(number_str);

	double fuel_sum = 0;
	for (int i = 0; i < num_numbers; i++)
		fuel_sum += mass_to_fuel(numbers[i]);
	

	printf("%lf\n", fuel_sum);

	return (0);
}