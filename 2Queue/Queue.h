// 顺序队列

# include <stdio.h>

# define MAXSIZE 50
# define OK 1
# define ERROR 0
# define TRUE 1
# define FALSE 0


typedef int ElemType;
typedef int Status;

typedef struct Queue
{
	ElemType data[MAXSIZE];
	int front;
	int rear;
}sqQueue;

Status InitQueue(sqQueue* s);

Status QueueIsEmpty(sqQueue s);

int QueueLength(sqQueue s);

Status GetHead(sqQueue s, ElemType* e);

Status ClearQueue(sqQueue* s);

// 插入数据
Status EnQueue(sqQueue *s, ElemType e);

// 删除数据
Status DeQueue(sqQueue* s, ElemType *e);


Status Display(sqQueue s);