#include <stdio.h>
#include <stdlib.h>

int sort[] = { 3, 1, 2 };
int n = sizeof(sort) / sizeof(sort[0]);

int compare(const void* arg1, const void* arg2)
{
	return (*((int*)arg1) - *((int*)arg2));
}


int main(int ac, char** av)
{
	int i;

	printf("\nソート開始\n");
	qsort(sort, n, sizeof(sort[0]), compare);

	printf("\nソート終了\n");
	for (i = 0; i < n; i++)
	{
		printf("%d\n", sort[i]);
	}
	return 0;
}



