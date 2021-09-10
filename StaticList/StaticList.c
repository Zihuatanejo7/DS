#define _CRT_SECURE_NO_WARNINGS 1

# include "StaticList.h"

Status InitList(StaticLinkList L)
{
	int i = 0;
	for (i = 0; i < MAXSIZE - 1; i++)
	{
		L[i].cur = i+1;
	}
	L[MAXSIZE - 1].cur = 0;

	return OK;
}

int ListLength(StaticLinkList L)
{
	int i = L[MAXSIZE - 1].cur;
	int j = 0;
	while (i)
	{
		i = L[i].cur;
		j++;
	}

	return j;
}

Status EmptyIsList(StaticLinkList L)
{
	return L[MAXSIZE - 1].cur == 0 ? TRUE : FALSE;
}

static int Malloc_SSL(StaticLinkList L)
{
	int i = L[0].cur;
	if (L[0].cur)
	{
		L[0].cur = L[i].cur;
	}

	return i;
}

Status InsertList(StaticLinkList L, int i, ElemType e)
{
	int k = MAXSIZE - 1;
	int l = 0;

	if (i < 1 || i > ListLength(L) + 1)  // “Ï≥£¥¶¿Ì
	{
		return ERROR;
	}

	int j = Malloc_SSL(L);

	if (j)
	{
		L[j].data = e;
		for (l = 1; l < i; l++)
		{
			k = L[k].cur;
		}
		L[j].cur = L[k].cur;
		L[k].cur = j;

		return OK;
	}

	return ERROR;

}

static void Free_SSL(StaticLinkList L, int k)
{
	L[k].cur = L[0].cur;
	L[0].cur = k;
}

Status DeleteList(StaticLinkList L, int i)
{
	if (i < 1 || i>ListLength(L) || EmptyIsList(L))
	{
		return ERROR;
	}

	int k = MAXSIZE - 1;
	int l = 1;
	for (l = 1; l < i; l++)
	{
		k = L[k].cur;
	}
	int j = L[k].cur;
	L[k].cur = L[j].cur;
	Free_SSL(L, j);
	return OK;
}

void Display(StaticLinkList L)
{
	if (ListLength(L) == 0)
	{
		return ;
	}

	int k = MAXSIZE - 1;

	while (L[k].cur)
	{
		k = L[k].cur;
		printf("%c  ", L[k].data);
	}

}