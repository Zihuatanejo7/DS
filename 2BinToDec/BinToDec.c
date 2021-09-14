#define _CRT_SECURE_NO_WARNINGS 1

# include "BinToDec.h"

Status InitStack(sqStack* s)
{
	s->base = (ElemType*)malloc(sizeof(ElemType) * STACK_INIT_SIZE);
	if (s->base == NULL) 
	{
		return ERROR;
	}
	s->top = s->base;
	s->StackSize = STACK_INIT_SIZE;

	return OK;
}

Status PushStack(sqStack* s, ElemType e)
{
	if (s->top - s->base >= s->StackSize) //Õ»ÇøÂú
	{
		ElemType* p = (ElemType*)realloc(s->base, sizeof(ElemType) * (STACK_INIT_SIZE + OFFSET));
		if (p != NULL)
		{
			s->base = p;
			free(p);
			s->StackSize = s->StackSize + OFFSET;
			s->top = s->base + s->StackSize;
		}
	}
	*(s->top) = e;
	(s->top)++;
	
	return OK;
}

Status PopStack(sqStack* s, ElemType* e)
{
	if (s->top == s->base)
	{
		return ERROR;  // Õ»¿Õ
	}
	s->top--;
	*e = *(s->top);
	
	return OK;
}

void ClearStack(sqStack* s)
{
	s->base = s->top;
}

int StackLen(sqStack s)
{
	return s.top - s.base;
}

void DestroyStack(sqStack* s)
{
	int len = StackLen(*s);
	int i = 0;
	for (i = 0; i < len; i++)
	{
		free(s->top);
		s->top--;
	}
	s->top = s->base = NULL;
	s->StackSize = 0;
}

void Display(sqStack *s)
{
	ElemType* p = s->top;
	int i;
	int j = StackLen(*s);
	for (i = 0; i < j; i++)
	{
		p--;
		printf("%c\n", *p);
	}
}
