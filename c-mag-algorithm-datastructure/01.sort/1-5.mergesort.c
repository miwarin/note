#include <stdio.h>
#include <stdlib.h>

#define N 3
static int sort[N] = { 3, 1, 2 };
static int buffer[N];

void MergeSort(int n, int x[])
{
	int i, j, k, m;

	if (n <= 1)
	{
		return;
	}
	m = n / 2;

	/* ブロックを前半と後半に分ける */
	MergeSort(m, x);
	MergeSort(n - m, x + m);

	/* マージ操作 */
	for (i = 0; i < m; i++)
	{
		buffer[i] = x[i];
	}
	j = m;
	i = k = 0;
	while (i < m && j < n)
	{
		if (buffer[i] <= x[j])
		{
			x[k++] = buffer[i++];
		}
		else
		{
			x[k++] = x[j++];
		}
	}
	while (i < m)
	{
		x[k++] = buffer[i++];
	}
}

int main(int ac, char** av)
{
	int i;
	int n = N;

	printf("\nソート開始\n");
	MergeSort(n, sort);

	printf("\nソート終了\n");
	for (i = 0; i < n; i++)
	{
		printf("%d\n", sort[i]);
	}
	return 0;
}
