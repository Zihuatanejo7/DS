#define _CRT_SECURE_NO_WARNINGS 1

# include "DoubleLoopList.h"

int main()
{
    LinkList L;
    int i, n;

    InitList(&L);

    printf("������һ��������");
    scanf("%d", &n);
    printf("\n");

    Caesar(&L, n);
    for (i = 0; i < 26; i++)
    {
        L = L->next;
        printf("%c", L->data);
    }
    return 0;
}
