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

	/* ���X�g�֒ǉ� */
	do
	{
		printf("��������͂��Ă�������(0����͂���ƏI��)\n");
		scanf_s("%d", &buf);
		if (buf)
		{
			/* �V�����m�[�h���쐬 */
			newnode = (struct ListNode*)malloc(sizeof(ListNode));
			newnode->data = buf;
			newnode->next = NULL;
			/* ���łɂ��郊�X�g�̖����ɐV�����m�[�h���Ȃ��� */
			if (lastnode != NULL)
			{
				lastnode->next = newnode;
				newnode->prev = lastnode;
				lastnode = newnode;
			}
			/* ���ꂪ�ŏ��̗v�f�������ꍇ */
			else
			{
				firstnode = lastnode = newnode;
				newnode->prev = NULL;
			}
		}
	} while (buf != 0);

	/* ���X�g������ */
	do
	{
		printf("��������l����͂��Ă�������\n");
		scanf_s("%d", &buf);
		if (buf != 0)
		{
			for (thisnode = firstnode; thisnode != NULL; thisnode = thisnode->next)
			{
				if(thisnode->data == buf)
				{
					printf("���͂��ꂽ�l�̂Ȃ��� %d ��������܂����B�m�[�h���폜���܂�\n", buf);
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
				printf("%d �͓��͂���Ă��Ȃ����A���邢�͂��łɍ폜����Ă��܂�\n", buf);
			}

		}
	} while (buf != 0);

	/* �S�m�[�h���폜 */
	for (thisnode = firstnode; thisnode != NULL;)
	{
		removenode = thisnode;
		thisnode = thisnode->next;
		free(removenode);
	}
	return 0;
}
