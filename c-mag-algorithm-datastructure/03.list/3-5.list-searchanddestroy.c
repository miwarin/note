#include <stdio.h>
#include <stdlib.h>

typedef struct tagListNode
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

	/* リストへ追加 */
	do
	{
		printf("整数を入力してくだしあ(0を入力すると終了)\n");
		scanf_s("%d", &buf);
		if (buf)
		{
			/* 新しいノードを作成 */
			newnode = (struct ListNode*)malloc(sizeof(ListNode));
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

	/* リストを検索 */
	do
	{
		printf("検索する値を入力してくだしあ\n");
		scanf_s("%d", &buf);
		if (buf != 0)
		{
			for (thisnode = firstnode; thisnode != NULL; thisnode = thisnode->next)
			{
				if(thisnode->data == buf)
				{
					printf("入力された値のなかに %d が見つかりました。ノードを削除します\n", buf);
					if (thisnode->prev != NULL)
					{
						thisnode->prev->next = thisnode->next;
					}
					else
					{
						firstnode = thisnode->next;
					}

					if (thisnode->next != NULL)
					{
						thisnode->next->prev = thisnode->prev;
					}
					free(thisnode);
					break;

				}
			}

			if (thisnode == NULL)
			{
				printf("%d は入力されていないか、あるいはすでに削除されています\n", buf);
			}

		}
	} while (buf != 0);

	/* 全ノードを削除 */
	for (thisnode = firstnode; thisnode != NULL;)
	{
		removenode = thisnode;
		thisnode = thisnode->next;
		free(removenode);
	}
	return 0;
}
