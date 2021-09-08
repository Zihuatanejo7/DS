#define _CRT_SECURE_NO_WARNINGS 1

# include "Stack.h"

Status InitStack(sqStack* s)
{
	s->top = -1;

	return OK;
}

Status ClearStack(sqStack* s)
{
	s->top = -1;

	return OK;
}

Status StackEmpty(sqStack s)
{
	return s.top == -1 ? TRUE : FALSE;
}

int StackLength(sqStack s)
{
	if (s.top == -1)
	{
		return 0;
	}

	return s.top+1;
}

Status GetTop(sqStack s, ElemType* e)
{
	if (s.top == -1)
	{
		return ERROR;
	}
	*e = s.data[s.top];

	return OK;
}

Status Push(sqStack* s, ElemType e)
{
	if (s->top == MAXSIZE - 1)
	{
		return ERROR;// Õ»Âú
	}

	(s->top)++;
	s->data[s->top] = e;
	
	return OK;
}

Status Pop(sqStack* s, ElemType* e)
{
	if (s->top == -1)
	{
		return ERROR;
	}

	*e = s->data[s->top];
	(s->top)--;

	return OK;
}

Status Display(sqStack s)
{
	if (s.top==-1)
	{
		return ERROR;
	}

	int i = 0;
	for (i = 0; i <= s.top; i++)
	{
		printf("%d	", s.data[i]);
	}
	printf("\n");
	return OK;
}



