#define _CRT_SECURE_NO_WARNINGS 1

# include "LoopLinkList.h"

int main()
{
    LinkList Head = NULL;
    Status i;

    int j = 1;
    ElemType e;

    i = InitList(&Head);
    printf("%d\n", ListLength(Head));
    Display(Head);

    for (j = 1; j <= 10; j++)
    {
        InsertList(&Head, j, j);
    }

    Display(Head);
    printf("\n");
    
    DeleteList(&Head, 2,&e);
    Display(Head);
    printf("\n");

    SearchList(Head, j);
    Display(Head);
    printf("\n");

    return 0;
}

