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
    printf("���е�Ԫ��Ϊ:");
    Display(L);

    InsertList(&L, 6,66);
    printf("��λ��%d����ֵ��\n", 6);
    Display(L);

    for (j = 5; j >= 1; j--)
    {
        DeleteList(&L, j, &e);
    }
    printf("���е�Ԫ��Ϊ:");
    Display(L);

    printf("Ԫ������λ�ã�%d\n", GetElem(L, 66));
    return 0;
}