#define _CRT_SECURE_NO_WARNINGS 1

# include "QueueList.h"

Status InitQueue(LinkQueue* s)
{
	s->front = (QueuePtr)malloc(sizeof(Node));
	if (!s->front)
	{
		return ERROR;
	}
	s->rear = s->front;
	s->rear->next = NULL;

	return OK;
}

Status QueueIsEmpty(LinkQueue s)
{
	return s.front == s.rear ? TRUE : FALSE;
}

int QueueLength(LinkQueue s)
{
	QueuePtr p = s.front;
	int j = 0;
	while (p != s.rear)
	{
		j++;
		p = p->next;
	}
	return j;
}

Status GetHead(LinkQueue s, ElemType* e)
{
	if (s.front == s.rear)
	{
		return ERROR;
	}

	QueuePtr p =  s.front->next;
	*e = p->data;;
	return OK;
}

Status EnQueue(LinkQueue* s, ElemType e)
{
	QueuePtr p = (QueuePtr)malloc(sizeof(Node));
	if (p == NULL)
	{
		return ERROR;
	}
	p->data = e;
	p->next = NULL;
	s->rear->next = p;
	s->rear = p;

	return OK;
}

Status DeQueue(LinkQueue* s, ElemType* e)
{
	if (s->front == s->rear)
	{
		return ERROR;
	}
	QueuePtr p = s->front->next;
	*e = p->data;
	s->front->next = p->next;

	if (s->rear == p)
	{
		s->front = s->rear;
	}
	free(p);
	return OK;
}

Status ClearQueue(LinkQueue* s)
{
	QueuePtr p, q;
	s->rear = s->front;
	p = s->front->next;
	s->front->next = NULL;

	while (p)
	{
		q = p;
		p = p->next;
		free(q);
	}

	return OK;
}

void Display(LinkQueue s)
{
	QueuePtr p = s.front;
	while (p != s.rear)
	{
		p = p->next;
		printf("%d    ", p->data);
	}
}