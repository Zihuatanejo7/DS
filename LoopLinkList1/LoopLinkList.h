#include <stdio.h>
#include <stdlib.h>
# include <time.h>

# define OK 1
# define ERROR 0
# define TRUE 1
# define FALSE 0

typedef int Status;
typedef int ElemType;

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

typedef struct Node* LinkList;

Status InitList(LinkList* pNode);

Status InsertList(LinkList* pNode, int i,ElemType e);

Status DeleteList(LinkList* pNode, int i,ElemType *pe);

int SearchList(LinkList pNode, int i);

void Display(LinkList pNode);

int ListLength(LinkList pNode);