#include <stdio.h>
#include <stdlib.h>

typedef struct tagTreeNode
{
	int value;
	struct tagTreeNode* left;
	struct tagTreeNode* right;

} TreeNode;

static TreeNode* treeRoot = NULL;

static TreeNode* createNewNode(int num)
{
	TreeNode* treeNew;
	treeNew = (TreeNode*)malloc(sizeof(TreeNode));
	if (treeNew == NULL)
	{
		exit(1);
	}
	treeNew->left = NULL;
	treeNew->right = NULL;
	treeNew->value = num;
	return treeNew;
}

static void insertTree(int num, TreeNode* node)
{
	if (node == NULL)
	{
		treeRoot = createNewNode(num);
		return;
	}
	if (node->value > num)
	{
		if (node->left != NULL)
		{
			insertTree(num, node->left);
		}
		else
		{
			node->left = createNewNode(num);
		}
	}
	else
	{
		if (node->right != NULL)
		{
			insertTree(num, node->right);
		}
		else
		{
			node->right = createNewNode(num);
		}
	}
}

static TreeNode* findValue(TreeNode* node, int val)
{
	if (node->value > val)
	{
		if (node->left == NULL)
		{
			return NULL;
		}
		return findValue(node->left, val);
	}
	if (node->value < val)
	{
		if (node->right == NULL)
		{
			return NULL;
		}
		return findValue(node->right, val);
	}
	return node;
}

static int deleteTree(int val)
{
	TreeNode* node;
	TreeNode* parent;
	TreeNode* left_bigest;
	int direction;

	node = treeRoot;
	parent = NULL;
	direction = 0;

	while (node != NULL && node->value != val)
	{
		if (node->value > val)
		{
			parent = node;
			node = node->left;
			direction = -1;
		}
		else
		{
			parent = node;
			node = node->right;
			direction = 1;
		}
	}
	if (node == NULL)
	{
		return 0;
	}
	if (node->left == NULL || node->right == NULL)
	{
		if (node->left == NULL)
		{
			if (direction == -1)
			{
				parent->left = node->right;
			}
			if (direction == 1)
			{
				parent->right = node->right;
			}
			if (direction == 0)
			{
				treeRoot = node->right;
			}
		}
		else
		{
			if (direction == -1)
			{
				parent->left = node->left;
			}
			if (direction == 1)
			{
				parent->right = node->left;
			}
			if (direction == 0)
			{
				treeRoot = node->left;
			}
		}

		free(node);
	}
	else
	{
		left_bigest = node->left;
		parent = node;
		direction = -1;
		while (left_bigest->right != NULL)
		{
			parent = left_bigest;
			left_bigest = left_bigest->right;
			direction = 1;
		}

		node->value = left_bigest->value;
		if (direction == -1)
		{
			parent->left = left_bigest->left;
		}
		else
		{
			parent->right = left_bigest->left;
		}
		free(left_bigest);
	}
	return 1;
}

static void printTree(int depth, TreeNode* node)
{
	int i;

	if (node == NULL)
	{
		return;
	}
	printTree(depth + 1, node->left);
	for (i = 0; i < depth; i++)
	{
		printf(" ");
	}
	printf("%d\n", node->value);
	printTree(depth + 1, node->right);
}

static void freeTree(TreeNode* node)
{
	if (node == NULL)
	{
		return;
	}

	freeTree(node->left);
	freeTree(node->right);
	free(node);
}

int main(int ac, char** av)
{
	int i, action;

	for (i = 0; i < 10; i++)
	{
		insertTree(rand() % 99 + 1, treeRoot);
	}
	for (;;)
	{
		printTree(0, treeRoot);
		printf("Às‚·‚é‘€ì‚ğ“ü—Í‚µ‚Ä‚­‚¾‚µ‚ \n");
		printf("1:’Ç‰Á 2:ŒŸõ 3:íœ ‚»‚êˆÈŠO:I—¹> ");
		scanf_s("%d", &action);

		switch (action)
		{
		case 1:
			printf("’Ç‰Á‚·‚é”š‚ğ“ü—Í‚µ‚Ä‚­‚¾‚µ‚ (1`100): ");
			scanf_s("%d", &i);
			if (i < 1 || i > 100)
			{
				continue;
			}
			insertTree(i, treeRoot);
			break;
		case 2:
			printf("ŒŸõ‚·‚é”š‚ğ“ü—Í‚µ‚Ä‚­‚¾‚µ‚ : ");
			scanf_s("%d", &i);
			if (findValue(treeRoot, i) != NULL)
			{
				printf("%d‚ğ”­Œ©\n", i);
			}
			else
			{
				printf("%d‚ÍŒ©‚Â‚©‚è‚Ü‚¹‚ñ‚Å‚µ‚½\n", i);

			}
			break;
		case 3:
			printf("íœ‚·‚é”š‚ğ“ü—Í‚µ‚Ä‚­‚¾‚µ‚ : ");
			scanf_s("%d", &i);
			if (deleteTree(i) == 1)
			{
				printf("%d‚ğíœ\n", i);
			}
			else
			{
				printf("%d‚ÍŒ©‚Â‚©‚è‚Ü‚¹‚ñ‚Å‚µ‚½\n", i);

			}
			break;
		default:
			freeTree(treeRoot);
			return 0;
		}
	}
	return 0;
}
