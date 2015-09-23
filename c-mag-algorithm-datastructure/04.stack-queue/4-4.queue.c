#include <stdio.h>
#include <stdlib.h>

#define QUEUE_MAX (5+1)
#define QUEUE_EMPTY (-1)

static int queue[QUEUE_MAX];
static int first = 0;
static int last = 0;

static void enqueue(int val)
{
	if ((last + 1) % QUEUE_MAX == first)
	{
		puts("キューが満杯");
	}
	else
	{
		queue[last] = val;
		last = (last + 1) % QUEUE_MAX;
	}
}

static int dequeue(void)
{
	int ret;
	if (first == last)
	{
		return QUEUE_EMPTY;
	}
	else
	{
		ret = queue[first];
		first = (first + 1) % QUEUE_MAX;
		return ret;
	}
}

int main(int ac, char** av)
{
	int i;
	int n = 5;

	puts("キューへ入れます");
	for (i = 0; i < 5; i++)
	{
		enqueue(i);
		printf("%d ", i);
	}
	puts("");

	puts("キューから取り出します");
	for (i = 0; i < 5; i++)
	{
		printf("%d ", dequeue());
	}
	puts("");

	return 0;

}
