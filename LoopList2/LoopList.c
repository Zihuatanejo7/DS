#define _CRT_SECURE_NO_WARNINGS 1
# include "LoopList.h"

Status InitList(LinkList* pNode)
{
    if ((*pNode)==NULL)
    {
        *pNode = (LinkList)malloc(sizeof(node));    // 头结点
        if ((*pNode) == NULL)
        {
            return ERROR;
        }
        (*pNode)->data = NULL;
        (*pNode)->next = (*pNode);    // 循环链表  表中只有一个头结点
    }
    return OK;
}

int ListLength(LinkList pNode)
{
    LinkList p = pNode;
    int j = 0;
    while (p->next != pNode)
    {
        p = p->next;
        j++;
    }
    return j;
}

Status InsertList(LinkList* pNode, int i, ElemType e)
{
    LinkList p = *pNode;
    
    if (i < 1 || i>ListLength(*pNode)+1)
    {
        return ERROR;
    }

    int j = 0;
    for (j = 1; j < i; j++)
    {
        p = p->next;
    }

    LinkList temp = (LinkList)malloc(sizeof(node));
    temp->data = e;

    temp->next = p->next;
    p->next = temp;
    return OK;
}

Status DeleteList(LinkList* pNode, int i)
{
    LinkList p = *pNode;

    int j = 1;
    for (j = 1; j < i; j++)
    {
        p = p->next;
    }

    LinkList q = p->next;
    p->next=q->next;
    free(q);

    return OK;
}

Status SearchList(LinkList pNode, ElemType e)
{
    LinkList target;

    int i = 1;
    for (target = pNode; target->data != e && target->next != pNode; ++i)
    {
        target = target->next;
    }

    if (target->next == pNode)
    {
        return ERROR;
    } 

    return i;
}

void Display(LinkList pNode)
{
    LinkList temp = pNode->next;

    printf("***********链表中的元素******************\n");
    do
    {
        printf("%4d ", temp->data);
    } while ((temp = temp->next) != pNode);

    printf("\n");
}