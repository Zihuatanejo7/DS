#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef char ElemType;
typedef int Status;

typedef struct Node
{
    ElemType data;
    struct Node* prior;
    struct Node* next;
}Node;

typedef struct Node* LinkList;

Status InitList(LinkList* L);

void Caesar(LinkList* L, int i);
