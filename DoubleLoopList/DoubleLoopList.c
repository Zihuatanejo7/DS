#define _CRT_SECURE_NO_WARNINGS 1

# include "DoubleLoopList.h"

Status InitList(LinkList* L)
{
    LinkList p, q;
    int i;
    *L = (LinkList)malloc(sizeof(Node));
    if ((*L)==NULL)
    {
        return ERROR;
    }

    (*L)->next = (*L)->prior = NULL;    //空表  前驱 后驱 都为NULL

    p = (*L);
    for (i = 0; i < 26; i++)
    {
        q = (LinkList)malloc(sizeof(Node));
        if (q==NULL)
        {
            return ERROR;
        }

        q->data = 'A' + i;

        q->prior = p;
        q->next = p->next;
        p->next = q;
        p = q;
    }

    p->next = (*L)->next;
    (*L)->next->prior = p;

    return OK;
}


void Caesar(LinkList* L, int i)
{
    if (i > 0)
    {
        do
        {
            (*L) = (*L)->next;
        } while (--i);
    }
    if (i < 0)
    {
        i = i - 1;
        (*L) = (*L)->next;
        do
        {
            (*L) = (*L)->prior;
        } while (++i);
    }
}