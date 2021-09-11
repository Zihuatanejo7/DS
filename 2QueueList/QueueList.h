// 队列的链式存储

# include <stdio.h>
# include <stdlib.h>

# define ERROR 0
# define OK 1
# define FALSE 0
# define TRUE 1

typedef int Status;
typedef int ElemType;

typedef struct Node
{
	ElemType data;
	struct Node* next;
}Node,*QueuePtr;

typedef struct
{
	QueuePtr front, rear;
}LinkQueue;

Status InitQueue(LinkQueue* s);

Status QueueIsEmpty(LinkQueue s);

int QueueLength(LinkQueue s);

Status GetHead(LinkQueue s, ElemType* e);

// 插入元素
Status EnQueue(LinkQueue* s, ElemType e);

// 删除元素
Status DeQueue(LinkQueue* s, ElemType* e);

Status ClearQueue(LinkQueue* s);

void Display(LinkQueue s);