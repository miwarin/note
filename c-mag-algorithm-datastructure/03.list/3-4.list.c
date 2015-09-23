#include <stdio.h>
#include <stdlib.h>

typedef struct tagLitNode
{
	struct tagListNode* prev;
	struct tagListNode* next;
	int data;
} ListNode;

int main(int ac, char** av)
{
	int buf, sum;
	ListNode* firstnode;
	ListNode* lastnode;
	ListNode* newnode;
	ListNode* thisnode;
	ListNode* removenode;

	firstnode = lastnode = NULL;

	do
	{
		printf("整数を入力してくだしあ(0を入力すると終了)\n");
		scanf_s("%d", &buf);
		if (buf)
		{
			/* 新しいノードを作成 */
			newnode = (ListNode*)malloc(sizeof(ListNode));
			newnode->data = buf;
			newnode->next = NULL;
			/* すでにあるリストの末尾に新しいノードをつなげる */
			if (lastnode != NULL)
			{
				lastnode->next = newnode;
				newnode->prev = lastnode;
				lastnode = newnode;
			}
			/* これが最初の要素だった場合 */
			else
			{
				firstnode = lastnode = newnode;
				newnode->prev = NULL;
			}
		}
	} while (buf != 0);

	printf("入力されたのは以下の数です\n");
	sum = 0;
	for (thisnode = firstnode; thisnode != NULL; thisnode = thisnode->next)
	{
		printf("%d\t", thisnode->data);
		sum += thisnode->data;
	}
	printf("\n\n以上の数の合計値は %d です\n", sum);

	/* 全ノードを削除 */
	for (thisnode = firstnode; thisnode != NULL;)
	{
		removenode = thisnode;
		thisnode = thisnode->next;
		free(removenode);
	}
	return 0;
}

