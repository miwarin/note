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
		printf("��������͂��Ă�������(0����͂���ƏI��)\n");
		scanf_s("%d", &buf);
		if (buf)
		{
			/* �V�����m�[�h���쐬 */
			newnode = (ListNode*)malloc(sizeof(ListNode));
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

	printf("���͂��ꂽ�͈̂ȉ��̐��ł�\n");
	sum = 0;
	for (thisnode = firstnode; thisnode != NULL; thisnode = thisnode->next)
	{
		printf("%d\t", thisnode->data);
		sum += thisnode->data;
	}
	printf("\n\n�ȏ�̐��̍��v�l�� %d �ł�\n", sum);

	/* �S�m�[�h���폜 */
	for (thisnode = firstnode; thisnode != NULL;)
	{
		removenode = thisnode;
		thisnode = thisnode->next;
		free(removenode);
	}
	return 0;
}

