#define _CRT_SECURE_NO_WARNINGS 1

# include "List.h"

static void visit(ElemType e)
{
	printf("%d\n",e);
}

Status InitList(Sqlist* L)
{
	L->length = 0;

	return OK;
}

Status ListEmpty(Sqlist L)
{
	return L.length == 0 ? TRUE : FALSE;
}

Status ClearList(Sqlist* L)
{
	L->length = 0;

	return OK;
}

int ListLength(Sqlist L)
{
	return L.length;
}

Status GetElem(Sqlist L, int i,ElemType* pe)
{
	if (L.length ==0 || i < 1 || i> L.length)
	{
		return ERROR;
	}

	*pe = L.data[i - 1];

	return OK;
}

Status InsertList(Sqlist* L, int i, ElemType e)
{
	int j = 0;

	if (L->length == MAXSIZE)
	{
		return ERROR;
	}

	if (i < 1 || i>L->length + 1)
	{
		return ERROR;
	}

	for (j = L->length; j >= i; j--)
	{
		L->data[j] = L->data[j-1];
	}

	L->data[i - 1] = e;
	L->length++;

	return OK;
}

Status DisplayList(Sqlist L)
{
	int i;
	for (i = 0; i < L.length; i++)
	{
		visit(L.data[i]);
	}
	printf("\n");
	return OK;
}

int  LocateElem(Sqlist L, ElemType e)
{
	int i;
	if (L.length == 0)
	{
		return 0;
	}

	for (i = 0; i < L.length; i++)
	{
		if (L.data[i] == e)
		{
			break;
		}
	}

	if (i == L.length)
	{
		return 0;
	}

	return i + 1;
}

Status ListDelete(Sqlist* L, int i, ElemType* pe)
{
	int j;
	if (L->length == 0)
	{
		return ERROR;
	}
	if (i < 1 || i > L->length)
	{
		return ERROR;
	}

	*pe = L->data[i - 1];

	for (j = i ; j <= L->length; j++)
	{
		L->data[j - 1] = L->data[j];
	}

	L->length--;

	return OK;
}

Status UnionList(Sqlist* La, Sqlist Lb)
{
	int i = 0;
	ElemType e;
	int len_a = La->length;
	int len_b = Lb.length;
	for (i = 1; i <= len_b; i++)
	{
		GetElem(Lb, i, &e);
		if (!LocateElem(*La, e))
		{
			InsertList(La, len_a++, e);
		}
	}

	return OK;
}
