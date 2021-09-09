// 循环链表2

#include <stdio.h>
#include <stdlib.h>

# define ERROR 0
# define OK 1

typedef int ElemType;
typedef int Status;

typedef struct node
{
    ElemType data;
    struct node* next;
}node;

typedef struct node* LinkList;

Status InitList(LinkList* pNode);

Status DeleteList(LinkList* pNode, int i);

Status InsertList(LinkList* pNode, int i,ElemType e);

Status SearchList(LinkList pNode, ElemType e);

int ListLength(LinkList pNode);

void Display(LinkList pNode);
