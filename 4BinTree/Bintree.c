#define _CRT_SECURE_NO_WARNINGS 1

# include "BinTree.h"

void InitBiTree(Tree* T)
{
	*T = NULL;
}

// 按照前遍历的方法创建二叉树
void CreateBiTree(Tree* T)
{
	ElemType c;
	scanf("%c", &c);
	if ('#' == c)
	{
		*T = NULL;
	}
	else
	{
		*T = (Tree)malloc(sizeof(Node));
		(*T)->data = c;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
	}
}

int TreeIsEmpty(Tree T)
{
	return T == NULL ? 1 : 0;
}

void ClearTree(Tree* T)
{
	if (*T)
	{
		if ((*T)->lchild)
		{
			ClearTree(&(*T)->lchild);
		}

		if ((*T)->rchild)
		{
			ClearTree(&(*T)->rchild);
		}

		free(*T);
		*T = NULL;
	}
}

ElemType Root(Tree T)
{
	if (!T)
	{
		return '#';
	}
	else
	{
		return T->data;
	}
	
}

int TreeDepth(Tree T)
{
	int i, j;

	if (!T)
	{
		return 0;
	}
	
	if (T->lchild)
	{
		i = TreeDepth(T->lchild);
	}
	else
	{
		i = 0;
	}
		
	if (T->rchild)
	{
		j = TreeDepth(T->rchild);
	}
	else
	{
		j = 0;
	}
		
	return i > j ? i + 1 : j + 1;
}

void PreOrderTraverse(Tree T)
{
	if (T)
	{
		printf("%c  ", T->data);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
	else
	{
		return;
	}
}

void InOrderTraverse(Tree T)
{
	if (T)
	{
		InOrderTraverse(T->lchild);
		printf("%c", T->data);
		InOrderTraverse(T->rchild);
	}
	else
	{
		return;
	}
}

void PostOrderTraverse(Tree T)
{
	if (T)
	{
		PostOrderTraverse(T->lchild);
		printf("%c", T->data);
		PostOrderTraverse(T->rchild);
	}
}