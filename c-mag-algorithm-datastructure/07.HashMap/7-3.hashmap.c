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
		/* 重率が 256^7 まで到達したら一巡して元に戻す */
		if (weight > 7)
		{
			weight = 0;
		}

		/* (4 * weight) は 256^weight と同じ */
		hash += (int)str[n] << (4 * weight);
	}
	return hash % hashmax;
}

/* firsthash の位置が埋まっていたら再ハッシュするための関数

firsthash から k^2 だけ後ろにある空き位置を探す
([k>ハッシュ表サイズの半分]となったらそれ以降の探索は無駄)

空き位置がなければ -1 を返す
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
			printf("%s をマップに挿入しようとしたが空き位置がなかった\n", newdata->english);
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

/* ハッシュテーブルからデータを削除する
   削除したデータを返す */
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
		{ "dolphin", "イルカ" },
		{ "beluga", "シロイルカ" },
		{ "granpus", "シャチ" },
		{ "medusa", "海月" },
		{ "otter", "カワウソ" },
	};

	InitHashTable(&hashtable, 503);

	for (n = 0; n < 5; n++)
	{
		AddDataToMap(&hashtable, &words[n]);
	}

	do
	{
		puts("どの操作をおこないますか？ (1:検索 2:削除 3:全表示 0:終了");
		scanf_s("%d", &n);
		switch (n)
		{
		case 1:
			puts("検索する英単語を入力してくだしあ");
			scanf_s("%s", key, 64);
			japanese = GetDataFromMap(&hashtable, key);
			if (japanese != NULL)
			{
				printf("%s の和訳は %s です\n", key, japanese);
			}
			else
			{
				printf("%s は見つかりませんでした\n", key);
			}
			break;
		case 2:
			puts("削除する英単語を入力してくだしあ");
			scanf_s("%s", key, 64);
			wordfound = DeleteDataFromMap(&hashtable, key);
			if (wordfound != NULL)
			{
				printf("%s を削除しました\n", key);
			}
			else
			{
				printf("%s は見つかりませんでした\n", key);
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
