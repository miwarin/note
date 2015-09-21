#include <stdio.h>
#include <stdlib.h>

#define N 3
static int sort[N] = { 3, 1, 2 };

void QuickSort(int bottom, int top, int* data)
{
	int lower, upper, div, temp;

	if (bottom >= top)
	{
		return;
	}
	/* �擪�̒l���u�K���Ȓl�v�Ƃ��� */
	div = data[bottom];
	for (lower = bottom, upper = top; lower < upper;)
	{
		while (lower <= upper && data[lower] <= div)
		{
			lower++;
		}
		while (lower <= upper && data[upper] > div)
		{
			upper--;
		}
		if (lower < upper)
		{
			temp = data[lower];
			data[lower] = data[upper];
			data[upper] = temp;
		}
		/* �ŏ��ɑI�������l�𒆉��Ɉړ����� */
		temp = data[bottom];
		data[bottom] = data[upper];
		data[upper] = temp;
		QuickSort(bottom, upper - 1, data);
		QuickSort(upper + 1, top, data);
	}
}

int main(int ac, char** av)
{
	int i;
	//srand( ( unsigned int )time( NULL ) );

	//printf("�\�[�g����\n");
	//for( i = 0; i < N; i++ )
	//{
	//  sort[ i ] = rand();
	//  printf("%d\n", sort[ i ]);
	//}
	printf("\n�\�[�g�J�n\n");
	QuickSort(0, N - 1, sort);


	printf("\n�\�[�g�I��\n");
	for (i = 0; i < N; i++)
	{
		printf("%d\n", sort[i]);
	}
	return 0;
}
