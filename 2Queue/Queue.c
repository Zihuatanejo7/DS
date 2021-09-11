#define _CRT_SECURE_NO_WARNINGS 1

# include "Queue.h"

Status InitQueue(sqQueue* s)
{
	s->front = 0;
	s->rear = 0;

	return OK;
}

Status QueueIsEmpty(sqQueue s)
{
	return s.rear == s.front ? TRUE : FALSE;
}

int QueueLength(sqQueue s) 
{
	return (s.rear - s.front + MAXSIZE)%MAXSIZE;
}

Status GetHead(sqQueue s, ElemType* e)
{
	if (s.rear == s.front)
	{
		return ERROR;
	}

	*e = s.data[s.front];
	return OK;
}

Status ClearQueue(sqQueue* s)
{
	s->front = s->rear = 0;
	return OK;
}

Status EnQueue(sqQueue *s, ElemType e)
{
	if ((s->rear + 1) % MAXSIZE == s->front)   //������  ��Ϊʱѭ�����У�����MAXSIZE -1 ��Ԫ��
	{
		return ERROR;
	}

	s->data[s->rear] = e;
	s->rear = (s->rear+1)%MAXSIZE;

	return OK;
}

Status DeQueue(sqQueue* s, ElemType* e)
{
	*e = s->data[s->front];
	s->front = (s->front + 1) % MAXSIZE;

	return OK;
}


Status Display(sqQueue s)
{
	if (s.front == s.rear)  // ���п�
	{
		return ERROR;
	}
	int len = (s.rear - s.front + MAXSIZE) % MAXSIZE;
	int j = s.front;

	while (len--)
	{
		printf("%d   ", s.data[j]);
		j = (j + 1) % MAXSIZE;
	}
	
	return OK;
}