#define _CRT_SECURE_NO_WARNINGS 1

# include "StackList.h"

Status InitStack(LinkStack* s)
{
	s->top = (LinkStackPtr)malloc(sizeof(Node));   // Í·Ö¸Õë
	if (s->top == NULL)
	{
		return ERROR;
	}
	s->top = NULL;
	s->count = 0;

	return OK;
}

Status ClearStack(LinkStack* s)
{
	LinkStackPtr p = s->top;
	LinkStackPtr q;
	while (p)
	{
		q = p;
		p = p->next;
		free(q);
	}
	s->count = 0;
	return OK;
}

int StackLength(LinkStack s)
{
	return s.count;
}

Status StackIsEmpty(LinkStack s)
{
	return s.count == 0 ? TRUE : FALSE;
}

Status GetTop(LinkStack s, ElemType* e)
{
	if (StackIsEmpty(s))
	{
		return ERROR;
	}
	*e = (s.top)->data;
	return OK;
}

Status PushStack(LinkStack* s, ElemType e)
{
	LinkStackPtr p = (LinkStackPtr)malloc(sizeof(Node));
	if (p == NULL)
	{
		return ERROR;
	}
	p->data = e;
	p->next = s->top;
	s->top = p;
	s->count++;
	return OK;
}

Status PopStack(LinkStack* s, ElemType* e)
{
	if (s->count == 0)
	{
		return ERROR;
	}

	LinkStackPtr p = s->top;
	*e = p->data;
	p = p->next;
	free(p);

	s->count--; 
	return OK;
}

Status Display(LinkStack s)
{
	if (!s.count)
	{
		return ERROR;
	}

	int j = 1;
	while (j <= s.count)
	{
		printf("%d   ", (s.top)->data);
		s.top = (s.top)->next;
		j++;
	}
	printf("\n");
	return OK;
}