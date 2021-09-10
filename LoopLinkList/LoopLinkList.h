# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# define OK 1
# define ERROR 0

typedef int ElemType;
typedef int Status;


typedef struct Node
{
	ElemType data;
	struct Node* next;
}Node,*LinkList;

Status InitList(LinkList* L);

int ListLength(LinkList L);

Status InsertList(LinkList* L, int i, ElemType e);

Status DeleteList(LinkList* L, int i, ElemType* e);

Status GetElem(LinkList L, ElemType e);

void Display(LinkList L);


