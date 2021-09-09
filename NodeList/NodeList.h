// 线性表的链式存储结构

# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# define OK 1
# define ERROR 0
# define TRUE 1
# define FALSE 0

typedef int Status;
typedef int ElemType;

typedef struct Node
{
	ElemType data;
	struct Node* next;

}Node;

typedef struct Node* LinkList;

Status Display(LinkList L);

Status InitList(LinkList* L);

int ListLength(LinkList L);

Status ListEmpty(LinkList L);

Status ClearList(LinkList* L);

Status GetElem(LinkList L,int i, ElemType *pe);

Status InsertList(LinkList* L, int i, ElemType e);

int LocateElem(LinkList L, ElemType e);

Status ListDelete(LinkList* L, int i, ElemType* pe);

Status CreateListHead(LinkList* L, int n);

Status CreateListTail(LinkList* L, int n);
