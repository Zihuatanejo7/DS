#define _CRT_SECURE_NO_WARNINGS 1

# include "DoubleStack.h"

Status InitStack(sqStack* s) 
{
	s->top1 = -1;
	s->top2 = MAXSIZE;

	return OK;
}

Status ClearStack(sqStack* s)
{
	s->top1 = -1;
	s->top2 = MAXSIZE;

	return OK;
}

int StackLength(sqStack s, int stackNumber)
{
	if ((s.top1 == -1) && (s.top2 == MAXSIZE))
	{
		return 0;
	}

	return s.top1 + 1 + MAXSIZE - s.top2 +1 ;
}

Status GetTop(sqStack s, ElemType* e, int stackNumber)
{
	if (s.top1 == -1 || s.top2 == MAXSIZE)
	{
		return ERROR;
	}

	if (stackNumber == 1)
	{
		*e = s.data[s.top1];
	}

	if (stackNumber == 2)
	{
		*e = s.data[s.top2];
	}

	return OK;
}

Status PushStack(sqStack* s, ElemType e, int stackNumber)
{
	if (s->top1 +1 == s->top2)   //栈满
	{
		return ERROR;
	}

	if (stackNumber == 1)  //前面入栈
	{
		(s->top1)++;
		s->data[s->top1] = e;
	}

	if (stackNumber == 2)  //后面入栈
	{
		(s->top2)--;
		s->data[s->top2] = e;
	}

	return OK;
}

Status PopStack (sqDoubleStack*s,Elemtype *e,int stackNumber)   // stackNumber : 从栈1出栈  还是 从栈2出栈
{
    if ((s->top1 == -1) && (s->top2==MAXSIZE)) // 两栈均为空
    {
        return ERROR;
    }
    
    if(stackNumber == 1)
    {
        if (s->top1 == -1)
        {
            return ERROR;
        }
        *e = s->data[s->top1]  
        s->top1--;
    }
    
    if(stackNumber == 1)
    {
        if (s->top2 == MAXSIZE)
        {
            return ERROR;
        }
        *e = s->data[s->top2];
        s->top2++;
    }
    return OK;
}

Status Display(sqStack s)
{
	if ((s.top1 == -1) && (s.top2 == MAXSIZE))
	{
		return ERROR;
	}

	int i;
	printf("第一个栈中元素为");
	for (i = 0; i <= s.top1; i++)
	{
		printf("%d	", s.data[i]);
	}
	int i = s.top2;
	printf("\n第二个栈中元素为");
	for (j = MAXSIZE; j >i; j--)
	{
		printf("%d	", s.data[j]);
	}

	return OK;
}