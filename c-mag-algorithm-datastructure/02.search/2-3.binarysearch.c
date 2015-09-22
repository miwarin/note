#include <stdio.h>
#include <stdlib.h>

#define NOT_FOUND (-1)

int BinarySeach(int x, int* a, int left, int right)
{
	int mid;

	while (left <= right)
	{
		mid = (left + right) / 2;
		if (a[mid] == x)
		{
			return mid;
		}
		if (a[mid] < x)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return NOT_FOUND;
}

int main(int ac, char** av)
{
	int i, r;
	int array[] = { 1, 2, 3 };
	int n = sizeof(array) / sizeof(array[0]);

	printf("����T���܂����H\n");
	scanf_s("%d", &i);
	r = BinarySeach(i, array, 0, n - 1);
	if (r == NOT_FOUND)
	{
		printf("%d �͌�����܂���\n", i);
	}
	else
	{
		printf("%d �� %d �Ԗڂł�\n", i, r);

	}
	return 0;
}

