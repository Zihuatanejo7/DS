#define _CRT_SECURE_NO_WARNINGS 1

# include "NodeList.h"

int main()
{
    LinkList L;
    Status i;
    ElemType e;
    int j, k;

    i = InitList(&L);
    printf("初始化L后：ListLength(L)=%d\n", ListLength(L));
    for (j = 1; j <= 5; j++)
    {
        i = InsertList(&L, 1, j);
    }
    printf("目前链表中的元素为:");
    Display(L);
    i = ListIsEmpty(L);
    printf("\nL是否空：i=%d(1:是 0:否)\n", i);
    printf("\nListLength(L)=%d \n", ListLength(L));

    i = ClearList(&L);
    printf("\n清空L后：ListLength(L)=%d\n", ListLength(L));
    i = ListIsEmpty(L);
    printf("\nL是否空：i=%d(1:是 0:否)\n", i);

    for (j = 1; j <= 10; j++) 
    {
        InsertList(&L, j, j);
    }
    printf("目前链表中的元素为:");
    Display(L);

    printf("\nListLength(L)=%d \n", ListLength(L));

    GetElem(L, 5, &e);
    printf("第5个元素的值为：%d\n", e);


    for (j = 3; j <= 4; j++)
    {
        k = LocateElem(L, j);
        if (k)
        {
            printf("第%d个元素的值为%d\n", k, j);
        }    
        else
        {
            printf("没有值为%d的元素\n", j);
        }    
    }

    k = ListLength(L); // k为表长 
    for (j = k + 1; j >= k; j--)
    {
        i = DeleteList(&L, j, &e); // 删除第j个数据
        if (i == ERROR)
        {
            printf("删除第%d个数据失败\n", j);
        }  
        else
        {
            printf("删除第%d个的元素值为：%d\n", j, e);
        }       
    }
    printf("依次输出L的元素：");
    Display(L);

    j = 5;
    DeleteList(&L, j, &e);     // 删除第5个数据
    printf("\n删除第%d个的元素值为：%d\n", j, e);

    printf("依次输出L的元素：");
    Display(L);

    i = ClearList(&L);
    printf("\n清空L后：ListLength(L)=%d\n", ListLength(L));

    CreateListHead(&L, 20);
    printf("整体创建L的元素(头插法)：");
    Display(L);

    i = ClearList(&L);
    printf("\n删除L后：ListLength(L)=%d\n", ListLength(L));
    CreateListTail(&L, 20);
    printf("整体创建L的元素(尾插法)：");
    Display(L);

    return 0;
}