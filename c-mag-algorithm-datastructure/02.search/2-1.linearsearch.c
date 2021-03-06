#include <stdio.h>
#include <stdlib.h>

#define NOT_FOUND (-1)
#define N (10)

int LinearSeach(int x, int* a, int num)
{
	int n = 0;

	/* 配列の範囲内で目的の値を探す */
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

	printf("何を探しますか？\n");
	scanf_s("%d", &i);
	r = LinearSeach(i, array, n);
	if (r == NOT_FOUND)
	{
		printf("%d は見つかりません\n", i);
	}
	else
	{
		printf("%d は %d 番目です\n", i, r );

	}
	return 0;
}

