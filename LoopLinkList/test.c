#define _CRT_SECURE_NO_WARNINGS 1

# include "LoopLinkList.h"

int main()
{
    LinkList L = NULL;
    ElemType e;
    InitList(&L);
    printf("\n");

    int j = 1;
    for (j; j<=10; j++)
    {
        InsertList(&L, j, j);
    }
    printf("表中的元素为:");
    Display(L);

    InsertList(&L, 6,66);
    printf("在位置%d插入值后：\n", 6);
    Display(L);

    for (j = 5; j >= 1; j--)
    {
        DeleteList(&L, j, &e);
    }
    printf("表中的元素为:");
    Display(L);

    printf("元素所在位置：%d\n", GetElem(L, 66));
    return 0;
}