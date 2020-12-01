
#include <stdio.h>
#include <stdlib.h>

#define MAX_DIGITS 10
#define MAX_NUMBERS 1000
#define TARGET 2020

/* Count the number of lines in stdin, without affecting the file position */
int count_lines()
{
	long int fpos = ftell(stdin);

	char str[MAX_DIGITS];
	int l = 0;
	while (fgets(str, MAX_DIGITS, stdin))
		l++;

	fseek(stdin, fpos, SEEK_SET); /* Reset file position to before call */
	return l - 1;
}

int long_cmp(const void *int1_void, const void *int2_void)
{
	long int1 = *(const long*)int1_void;
	long int2 = *(const long*)int2_void;

	return int1 < int2 ? -1 : (int1 == int2 ? 0 : 1);
}

int main() {
	/* Allocate memory for each number */
	int num_numbers = count_lines();
	long *numbers = malloc((num_numbers + 1) * sizeof(long));

	/* Read in numbers */
	char number_str[MAX_DIGITS];
	int n = 0;
	while (fgets(number_str, MAX_DIGITS, stdin))
		numbers[n++] = atol(number_str);

	/* Sort numbers */
	qsort(numbers, num_numbers, sizeof(long), long_cmp);

	/* Find numbers that add to TARGET */
	int i, j, k = 0;

	/* Check each number i */
	for (i = 0; i < num_numbers - 2; i++)
	{
		if (numbers[i] > TARGET - 2 * numbers[1])
			break;

		for (j = i + 1; j < num_numbers - 1; j++)
		{
			if (numbers[i] + numbers[j] > TARGET - numbers[2])
				break;

			for (k = j + 1; k < num_numbers; k++)
			{
				if (numbers[i] + numbers[j] + numbers[k] == TARGET)
					break;
				else if (numbers[i] + numbers[j] + numbers[k] > TARGET)
					break;
			}

			if (numbers[i] + numbers[j] + numbers[k] == TARGET)
				break;
		}

		if (numbers[i] + numbers[j] + numbers[k] == TARGET)
				break;
	}

	printf("i = %d, j = %d, k = %d\n", i, j, k);
	printf("%ld, %ld, %ld\n", numbers[i], numbers[j], numbers[k]);
	printf("%ld + %ld + %ld = %ld\n", numbers[i], numbers[j], numbers[k], numbers[i] + numbers[j] + numbers[k]);
	printf("%ld * %ld * %ld = %ld\n", numbers[i], numbers[j], numbers[k], numbers[i] * numbers[j] * numbers[k]);

	return (0);
}