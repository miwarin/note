#include <stdio.h>
#include <stdlib.h>

#define NOT_FOUND (-1)
#define N (10)

int LinearSeach(int x, int* a, int num)
{
	int n = 0;

	/* ”z—ñ‚Ì”ÍˆÍ“à‚Å–Ú“I‚Ì’l‚ð’T‚· */
	while (n < num && a[n] != x)
	{
		n++;
	}
	if (n < num)
	{
		return n;
	}
	return NOT_FOUND;

}

int main(int ac, char** av)
{
	int i, r;
	int array[] = { 3, 1, 2 };
	int n = sizeof(array) / sizeof(array[0]);

	printf("‰½‚ð’T‚µ‚Ü‚·‚©H\n");
	scanf_s("%d", &i);
	r = LinearSeach(i, array, n);
	if (r == NOT_FOUND)
	{
		printf("%d ‚ÍŒ©‚Â‚©‚è‚Ü‚¹‚ñ\n", i);
	}
	else
	{
		printf("%d ‚Í %d ”Ô–Ú‚Å‚·\n", i, r );

	}
	return 0;
}

