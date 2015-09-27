#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char* english;
	char* japanese;
} WORDSET;

typedef struct
{
	WORDSET** data;
	unsigned int size;
} HASHTABLE;

static unsigned int MakeHash2(char* str, unsigned int hashmax)
{
	unsigned int n, length, hash, weight;
	length = strlen(str);
	for (n = weight = hash = 0; n < length; n++, weight++)
	{
		/* �d���� 256^7 �܂œ��B������ꏄ���Č��ɖ߂� */
		if (weight > 7)
		{
			weight = 0;
		}

		/* (4 * weight) �� 256^weight �Ɠ��� */
		hash += (int)str[n] << (4 * weight);
	}
	return hash % hashmax;
}

/* firsthash �̈ʒu�����܂��Ă�����ăn�b�V�����邽�߂̊֐�

firsthash ���� k^2 �������ɂ���󂫈ʒu��T��
([k>�n�b�V���\�T�C�Y�̔���]�ƂȂ����炻��ȍ~�̒T���͖���)

�󂫈ʒu���Ȃ���� -1 ��Ԃ�
*/
static unsigned int ReHash(HASHTABLE* hashtable, unsigned int firsthash)
{
	unsigned int hashval, k;

	for (k = 1; k <= hashtable->size / 2; k++)
	{
		hashval = (firsthash + k * k) % hashtable->size;
		if (hashtable->data[hashval] == NULL)
		{
			return hashval;
		}
	}
	return -1;
}

static void AddDataToMap(HASHTABLE* hashtable, WORDSET* newdata)
{
	unsigned int hashval;

	hashval = MakeHash2(newdata->english, hashtable->size);
	if (hashtable->data[hashval] != NULL)
	{
		hashval = ReHash(hashtable, hashval);
		if (hashval == -1)
		{
			printf("%s ���}�b�v�ɑ}�����悤�Ƃ������󂫈ʒu���Ȃ�����\n", newdata->english);
			return;
		}
	}
	hashtable->data[hashval] = newdata;
}

static char* GetDataFromMap(HASHTABLE* hashtable, char* key)
{
	unsigned int hashval, k;
	WORDSET* word;

	hashval = MakeHash2(key, hashtable->size);
	for (k = 0; k <= hashtable->size / 2; k++)
	{
		word = hashtable->data[(hashval + k * k) % hashtable->size];
		if (word != NULL)
		{
			if(strcmp(key, word->english) == 0)
			{
				return word->japanese;
			}
		}
	}
	return NULL;
}

/* �n�b�V���e�[�u������f�[�^���폜����
   �폜�����f�[�^��Ԃ� */
static WORDSET* DeleteDataFromMap(HASHTABLE* hashtable, char* key)
{
	unsigned int hashval, k;
	WORDSET* word;

	hashval = MakeHash2(key, hashtable->size);
	for (k = 0; k <= hashtable->size / 2; k++)
	{
		word = hashtable->data[(hashval + k * k) % hashtable->size];
		if (word != NULL)
		{
			if (strcmp(key, word->english) == 0)
			{
				hashtable->data[(hashval + k * k) % hashtable->size] = NULL;
				return word;
			}
		}
	}
	return NULL;
}

static void InitHashTable(HASHTABLE* hashtable, unsigned int size)
{
	hashtable->data = (WORDSET**)malloc(sizeof(WORDSET*) * size);
	memset(hashtable->data, NULL, sizeof(WORDSET*) * size);
	hashtable->size = size;
}

static void CleanupHashTable(HASHTABLE* hashtable)
{
	free(hashtable->data);
	hashtable->size = 0;
}

static void PrintAllData(HASHTABLE* hashtable)
{
	unsigned int n;

	for (n = 0; n < hashtable->size; n++)
	{
		if (hashtable->data[n] != NULL)
		{
			printf("%d:\t%s\t%s\n", n, hashtable->data[n]->english, hashtable->data[n]->japanese);
		}
	}
}

int main(int ac, char** av)
{
	unsigned int n;
	char key[64], *japanese;
	HASHTABLE hashtable;
	WORDSET* wordfound;
	WORDSET words[] = 
	{
		{ "dolphin", "�C���J" },
		{ "beluga", "�V���C���J" },
		{ "granpus", "�V���`" },
		{ "medusa", "�C��" },
		{ "otter", "�J���E�\" },
	};

	InitHashTable(&hashtable, 503);

	for (n = 0; n < 5; n++)
	{
		AddDataToMap(&hashtable, &words[n]);
	}

	do
	{
		puts("�ǂ̑���������Ȃ��܂����H (1:���� 2:�폜 3:�S�\�� 0:�I��");
		scanf_s("%d", &n);
		switch (n)
		{
		case 1:
			puts("��������p�P�����͂��Ă�������");
			scanf_s("%s", key, 64);
			japanese = GetDataFromMap(&hashtable, key);
			if (japanese != NULL)
			{
				printf("%s �̘a��� %s �ł�\n", key, japanese);
			}
			else
			{
				printf("%s �͌�����܂���ł���\n", key);
			}
			break;
		case 2:
			puts("�폜����p�P�����͂��Ă�������");
			scanf_s("%s", key, 64);
			wordfound = DeleteDataFromMap(&hashtable, key);
			if (wordfound != NULL)
			{
				printf("%s ���폜���܂���\n", key);
			}
			else
			{
				printf("%s �͌�����܂���ł���\n", key);
			}
			break;
		case 3:
			PrintAllData(&hashtable);
			break;

		default:
			break;
		}
	} while (n != 0);

	CleanupHashTable(&hashtable);
	return 0;
}
