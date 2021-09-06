#define _CRT_SECURE_NO_WARNINGS 1

# include "LoopList.h"

int main()
{
    LinkList pHead = NULL;

    InitList(&pHead);
    printf("%d\n", ListLength(pHead));
    Display(pHead);

    int j;
    for (j = 1; j <= 10; j++)
    {
        InsertList(&pHead, j,j);
    }
    printf("%d\n", ListLength(pHead));
    Display(pHead);

    DeleteList(&pHead, 10);
    printf("%d\n", ListLength(pHead));
    Display(pHead);
    
    return 0;
}

