#define _CRT_SECURE_NO_WARNINGS 1

# include "NodeList.h"

// L ： 头指针  LinkList *  Node**
// *L:  头结点  LinkList   Node*
Status InitList(LinkList* L)
{
	*L = (LinkList)malloc(sizeof(Node));     // 头结点
	if (*L == NULL)
	{
		return ERROR;   // 空间开辟失败
	}
	(*L)->next = NULL;

	return OK;
}

int ListLength(LinkList L)
{
	LinkList p = L->next;
	int j = 0;
	while (p)
	{
		j++;
		p = p->next;
	}
	return j;
}

Status ListIsEmpty(LinkList L)
{
	return	L->next == NULL ? TRUE : FALSE;
}

Status ClearList(LinkList* L)
{
	LinkList p = (*L)->next;
	LinkList q;
	while (p)
	{
		q = p;
		p = p->next;
		free(q);
	}
	(*L)->next = NULL;
	return OK;
}

Status GetElem(LinkList L, int i, ElemType* e)
{
	if (ListIsEmpty(L) || i<1||i>ListLength(L))
	{
		return ERROR;
	}

	LinkList p = L->next;
	int j = 1;
	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	*e = p->data;
	return OK;
}

Status LocateElem(LinkList L, ElemType e)
{
	LinkList p = L->next;

	int j = 1;
	while (p)
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

Status InsertList(LinkList* L, int i, ElemType e)
{
	LinkList s = (Node*)malloc(sizeof(Node));
	if (s == NULL)
	{
		return ERROR;
	}
		
	int j = 1;
	LinkList p = *L;   
	while (p != NULL && j < i)
	{
		p = p->next;
		j++;
	}
	
	if (p == NULL)
	{
		return ERROR;
	}

	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

Status DeleteList(LinkList* L, int i, ElemType *e)
{
	if (ListIsEmpty(*L) || i < 1 || i>ListLength(*L))
	{
		return ERROR;
	}

	LinkList p = *L;    // 第一个节点

	int j = 1;
	while (p->next&&j<i)
	{
		p = p->next;
		j++;
	}

	if (p->next == NULL)
	{
		return ERROR;
	}

	LinkList q = p->next;
	*e = q->data;
	p->next = q->next;
	free(q);
	return OK;
}

Status CreateListHead(LinkList* L, int n)
{
	*L = (LinkList)malloc(sizeof(Node));
	if ((*L) == NULL)
	{
		return ERROR;
	}
	(*L)->next = NULL;

	srand((unsigned)time(0));
	int i = 0;
	while (i < n)
	{
		LinkList s = (Node*)malloc(sizeof(Node));
		if (s == NULL)
		{
			return ERROR;
		}
		s->data = rand() % 100 + 1;
		s->next = (*L)->next;
		(*L)->next = s;

		i++;
	}
	return OK;
}

Status CreateListTail(LinkList* L, int n)
{
	srand((unsigned)time(0));

	LinkList s,  r;

	*L = (LinkList)malloc(sizeof(Node));
	r = *L;

	int i = 0;
	while (i < n)
	{
		s = (LinkList)malloc(sizeof(Node));
		if (s == NULL)
		{
			return ERROR;
		}
		s->data = rand() % 100 + 1;
		r->next = s;
		r = s;

		i++;
	}
	r->next = NULL;
}

Status Display(LinkList L)
{
	if (ListIsEmpty(L))
	{
		return ERROR;
	}

	LinkList p = L->next;  
	while (p)
	{
		printf("%d	", p->data);
		p = p->next;
	}

	return OK;
}