#define _CRT_SECURE_NO_WARNINGS 1

# include "LoopLinkList.h"

Status InitList(LinkList* L)
{
	srand((unsigned)time(0));

	*L = (LinkList)malloc(sizeof(Node));  // 头结点
	if ((*L) == NULL)
	{
		return ERROR;
	}

	(*L)->data = rand() % 100 + 1;
	(*L)->next = *L;    // 

	return OK;
}

int ListLength(LinkList L)
{
	LinkList p = L->next;
	int j = 0;
	while (p != L)
	{
		j++;
		p = p->next;
	}
	return j;
}

Status InsertList(LinkList* L, int i, ElemType e)
{
	if (i < 1 || i > ListLength(*L) + 1)
	{
		return ERROR;
	}

	LinkList p = *L;
	int j = 0;
	for (j = 1; j < i; j++)
	{
		p = p->next;
	}

	LinkList s = (LinkList)malloc(sizeof(Node));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

/*循环单链表的删除,删除错误返回0，删除成功返回1，用e返回被删除的元素*/
Status DeleteList(LinkList* L, int i, ElemType* e)
{
	int j = 1;
	LinkList p, q;
	p = *L;

	if (i<1 || p->next == *L || i>ListLength(*L))
	{
		return ERROR;
	}

	while (p->next != *L && j < i)
	{
		p = p->next;
		j++;
	}

	q = p->next;
	*e = q->data;
	p->next = q->next;
	free(q);                          
	return OK;
}

Status GetElem(LinkList L, ElemType e)
{
	if (L->next == L)
	{
		return ERROR;
	}

	LinkList p = L;
	int j = 0;
	while (p->next != L)
	{
		if (p->data == e)
		{
			break;
		}
		p = p->next;
		j++;
	}
	return j;
}

void Display(LinkList L)
{
	if (L->next == L)
	{
		return ;
	}

	LinkList p = L->next;
	while (p != L)
	{
		printf("%d   ", p->data);
		p = p->next;
	}
	printf("\n");
}