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
	if (s->top1 +1 == s->top2)   //ջ��
	{
		return ERROR;
	}

	if (stackNumber == 1)  //ǰ����ջ
	{
		(s->top1)++;
		s->data[s->top1] = e;
	}

	if (stackNumber == 2)  //������ջ
	{
		(s->top2)--;
		s->data[s->top2] = e;
	}

	return OK;
}

Status PopStack (sqDoubleStack*s,Elemtype *e,int stackNumber)   // stackNumber : ��ջ1��ջ  ���� ��ջ2��ջ
{
    if ((s->top1 == -1) && (s->top2==MAXSIZE)) // ��ջ��Ϊ��
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
	printf("��һ��ջ��Ԫ��Ϊ");
	for (i = 0; i <= s.top1; i++)
	{
		printf("%d	", s.data[i]);
	}
	int i = s.top2;
	printf("\n�ڶ���ջ��Ԫ��Ϊ");
	for (j = MAXSIZE; j >i; j--)
	{
		printf("%d	", s.data[j]);
	}

	return OK;
}