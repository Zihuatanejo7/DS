#define _CRT_SECURE_NO_WARNINGS 1

# include "NodeList.h"

static void visit(ElemType e)
{
	printf("%d\n", e);
}

Status Display(LinkList L)
{
	LinkList p = L->next;
	while (p)
	{
		visit(p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}

Status InitList(LinkList* L)
{ 
	*L = (LinkList)malloc(sizeof(Node));   // 产生头节点

	if ((*L) == NULL)
	{
		return ERROR;
	}

	(*L)->next = NULL;                    // 建立空链表

	return OK;
}

int ListLength(LinkList L)
{
	LinkList p = L;     // 指向头节点
	int i = 0;
	while (p->next != NULL)
	{
		i++;
		p = p->next;
	}
	return i;
}

Status ListEmpty(LinkList L)
{
	return L->next == NULL;
}

Status ClearList(LinkList* L)
{
	LinkList p = *L;
	LinkList q;
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL;

	return OK;
}

Status GetElem(LinkList L, int i, ElemType *pe)
{
	int j = 0;
	LinkList p = L->next;      // 指向第一个节点

	for (j = 0; p != NULL && j < i; j++)
	{
		p = p->next;
	}

	if (p == NULL)
	{
		return ERROR;
	}

	*pe = p->data;

	return OK;
}

Status InsertList(LinkList* L, int i, ElemType e)
{
	int j;
	LinkList p = *L;
	LinkList s = (LinkList)malloc(sizeof(Node));

	for (j = 1; p != NULL && j < i; j++)
	{
		p = p->next;
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

int LocateElem(LinkList L, ElemType e)
{
	LinkList p = L;
	int j = 0;
	while (p != NULL) 
	{
		printf("%d\n", p->data);
		if (p->data == e)
		{
			return j;
		}	
		j++;
		p = p->next;
	}

	if (p == NULL)
	{
		return ERROR;
	}
	return 0;
}

Status ListDelete(LinkList* L, int i, ElemType* pe)
{
	int j;

	LinkList p, q;

	p = *L;

	j = 1;
	while (p->next && j < i)	
	{
		p = p->next;
		++j;
	}
	if (p->next == NULL)
	{
		return ERROR;
	}	      
	q = p->next;
	p->next = q->next;	

	*pe = q->data;      

	free(q);       

	return OK;
}

Status CreateListHead(LinkList* L, int n)
{
	*L = (LinkList)malloc(sizeof(Node));

	srand((unsigned)time(0));

	if ((*L) == NULL)
	{
		return ERROR;   //空间开辟失败
	}
	else
	{
		(*L) ->next = NULL;
	}

	int i = 1;
	for (i = 1; i < n; i++)
	{
		LinkList s = (LinkList)malloc(sizeof(Node));
		if (s == NULL)
		{
			return ERROR;
		}
		else
		{
			s->data = rand() % 100 + 1;
		}

		s->next = (*L)->next;
		(*L)->next = s;
	}

	return OK;
}

Status CreateListTail(LinkList* L,int n)
{
	int i = 0;
	LinkList p, r;
	srand((unsigned)time(0));

	*L = (LinkList)malloc(sizeof(Node));
	
	if ((*L) == NULL)
	{
		return ERROR;   //空间开辟失败
	}
	else
	{
		r = *L;         //  r指向线性表尾部
	}

	for (i = 1; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand() % 100 + 1;
		r->next = p;
		r = r->next;
	}
	r->next = NULL;

	return OK;
}
