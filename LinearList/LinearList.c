#define _CRT_SECURE_NO_WARNINGS 1

# include "LinearList.h"

Status InitList(sqList *L)
{
	L->length = 0;

	return OK;
}

int ListLength(sqList L)
{
	return L.length;
}

Status ListIsEmpty(sqList L)
{
	return L.length == 0 ? TRUE : FALSE;
}

Status ClearList(sqList* L)
{
	if (ListIsEmpty(*L))
	{
		return OK;
	}
	else
	{
		L->length = 0;
		return OK;
	}
}

// 在表中 pos 位置 插入 e
Status InsertList(sqList* L, int pos, ElemType e)
{
	if (pos < 1 || pos >ListLength(*L) + 1)     // 位置异常
	{
		return ERROR;
	}

	int i;
	for (i = ListLength(*L) ; i >= pos; i--)
	{
		L->data[i] = L->data[i - 1];
	}
	L->data[pos - 1] = e;
	L->length++;

	return OK;
}

Status DeleteList(sqList* L, int pos, ElemType* e)
{
	if (pos < 1 || pos > ListLength(*L))
	{
		return ERROR;
	}

	*e = L->data[pos - 1];
	int i = pos;
	for (i; i <= ListLength(*L); i++)
	{
		L->data[i - 1] = L->data[i];
	}
	L->length--;
	return OK;
}

// 读取L中pos位置出的数据
Status GetElem(sqList L, int pos, ElemType* e)
{
	if (pos <1 || pos > ListLength(L))   // 异常处理
	{
		return ERROR;
	}

	*e = L.data[pos - 1];
	return OK;
}

// 返回特定元素下标 (第一个特定元素下标)
int LocateElem(sqList L, ElemType e)
{
	if (L.length == 0)   // 空表
	{
		return 0;
	}

	int i = 1;
	while (i <= ListLength(L))
	{
		if (L.data[i] == e)
		{
			break;
		}
		i++;
	}

	if (i > ListLength(L))
	{
		return 0;
	}

	return i;
}

// 将L和Lb的交元素放入L中
void Intersection(sqList* L1, sqList La,sqList  Lb)
{
	ElemType e;
	int len2 = Lb.length;
	int i = 1;

	int pos = 1;
	for (i; i <= len2; i++)
	{
		GetElem(Lb, i, &e);
		if (LocateElem(La, e))
		{
			InsertList(L1, pos++, e);
		}
	}
}

void unionL(sqList* L, sqList Lb)
{
	ElemType e;
	int i = 1;
	int len1 = L->length;
	int len2 = Lb.length;

	for (i; i <= len2; i++)
	{
		GetElem(Lb, i, &e);
		if (!LocateElem(*L, e))
		{
			InsertList(L, ++len1, e);
		}
	}

}

Status Display(sqList L)
{
	if (ListIsEmpty(L))
	{
		return ERROR;
	}

	int i = 1;
	while (i <= ListLength(L))
	{
		printf("%d	", L.data[i - 1]);
		i++;
	}
	printf("\n");
	return OK;
}