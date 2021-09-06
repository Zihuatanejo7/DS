#define _CRT_SECURE_NO_WARNINGS 1

# include "LoopLinkList.h"

Status InitList(LinkList* pNode)
{
    srand((unsigned)time(0));

    if ((*pNode) == NULL)
    {
        *pNode = (LinkList)malloc(sizeof(Node));
        if ((*pNode) == NULL)
        {
            return ERROR;
        }
        (*pNode)->data = rand() % 100 + 1;
        (*pNode)->next = *pNode;
    }
   
    return OK;
}

int ListLength(LinkList pNode)
{
    int j = 0;
    LinkList p = pNode;
    while (p->next != pNode)
    {
        j++;
        p = p->next;
    }
    return j;
}

Status InsertList(LinkList* pNode, int i, ElemType e)
{
    LinkList p = *pNode;
    if (i < 1)
    {
        return ERROR;
    }

    int j = 0;
    for (j = 1; j < i; j++)
    {
        p = p->next;
    }

    LinkList s = (LinkList)malloc(sizeof(Node));

    s->data = e;
    s->next = p->next;
    p->next = s;

    return OK;
}

Status DeleteList(LinkList* pNode, int i, ElemType* pe)
{
    LinkList target,temp;
    int j = 1;
    if (i == 1)
    {
        for (target = (*pNode); target->next != (*pNode); target = target->next);
        temp = (*pNode);
        *pe = temp->data;
        *pNode = (*pNode)->next;
        target->next = *pNode;
        free(temp);
    }
    else
    {
        target = *pNode;
        for (j = 1; j < i ; ++j)
        {
            target = target->next;
        }
        temp = target->next;
        *pe = temp->data;
        target->next = temp->next;
        free(temp);
    }

    return OK;
}

int SearchList(LinkList pNode, int elem)
{
    LinkList target;
    int i = 1;
    for (target = pNode; target->data != elem && target->next != pNode; ++i)
    {
        target = target->next;
    }
    if (target->next == pNode)
    {
        return 0;
    }
    else
    {
        return i;
    }
}

void Display(LinkList pNode)
{
    LinkList temp = pNode->next;
    printf("***********链表中的元素******************\n");
    do
    {
        printf("%4d ", temp->data);
        temp = temp->next;
    }while (temp != pNode);

    printf("\n");
}