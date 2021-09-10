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

// �ڱ��� pos λ�� ���� e
Status InsertList(sqList* L, int pos, ElemType e)
{
	if (pos < 1 || pos >ListLength(*L) + 1)     // λ���쳣
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

// ��ȡL��posλ�ó�������
Status GetElem(sqList L, int pos, ElemType* e)
{
	if (pos <1 || pos > ListLength(L))   // �쳣����
	{
		return ERROR;
	}

	*e = L.data[pos - 1];
	return OK;
}

// �����ض�Ԫ���±� (��һ���ض�Ԫ���±�)
int LocateElem(sqList L, ElemType e)
{
	if (L.length == 0)   // �ձ�
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

// ��L��Lb�Ľ�Ԫ�ط���L��
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