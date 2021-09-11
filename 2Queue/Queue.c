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
	if ((s->rear + 1) % MAXSIZE == s->front)   //队列满  因为时循环队列，最多存MAXSIZE -1 个元素
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
	if (s.front == s.rear)  // 队列空
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