// 线性表的链式存储结构

# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# define OK 1
# define ERROR 0
# define TRUE 1
# define FALSE 0

typedef int ElemType;
typedef int Status;

typedef struct Node
{
	ElemType data;
	struct Node* next;
}Node,*LinkList;

Status InitList(LinkList* L);

int ListLength(LinkList L);

Status ListIsEmpty(LinkList L);

Status ClearList(LinkList* L);

Status GetElem(LinkList L, int i, ElemType* e);

Status LocateElem(LinkList L, ElemType e);

Status InsertList(LinkList* L, int i, ElemType e);

Status DeleteList(LinkList* L, int i, ElemType *e);

Status CreateListHead(LinkList* L, int n);

Status CreateListTail(LinkList* L, int n);

Status Display(LinkList L);


