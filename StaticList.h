// 静态链表

# include <stdio.h>

# define MAXSIZE 60

# define OK 1
# define ERROR 0
# define TRUE 1
# define FALSE 0

typedef char ElemType;
typedef int Status;

typedef struct 
{
	ElemType data;
	int cur;
}StaticLinkList[MAXSIZE];


Status InitList(StaticLinkList L);

int ListLength(StaticLinkList L);

Status EmptyIsList(StaticLinkList L);

Status InsertList(StaticLinkList L, int i, ElemType e);

Status DeleteList(StaticLinkList L, int i);

void Display(StaticLinkList L);