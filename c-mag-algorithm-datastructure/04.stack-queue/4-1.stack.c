#include <stdio.h>
#include <stdlib.h>

#define STACK_MAX 10

static int stack[STACK_MAX];
static int top = 0;

void push(int val)
{
	if (top == STACK_MAX)
	{
		printf("�X�^�b�N�����t\n");
		exit(1);
	}
	else
	{
		stack[top] = val;
		top++;
	}
}

int pop(void)
{
	if (top == 0)
	{
		printf("�X�^�b�N�������\n");
		exit(1);
	}
	else
	{
		top--;
		return stack[top];
	}
}

int main(int ac, char** av)
{
	int i;
	int n = 5;

	printf("�X�^�b�N�֐ς݂܂�\n");
	for (i = 0; i < 5; i++)
	{
		push(i);
		printf("%d ", i);
	}
	puts("");

	printf("�X�^�b�N������o���܂�\n");
	for (i = 0; i < 5; i++)
	{
		printf("%d ", pop());
	}
	puts("");

	return 0;
}