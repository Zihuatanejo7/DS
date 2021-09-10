#define _CRT_SECURE_NO_WARNINGS 1

# include "LinearList.h"

int main()
{

    sqList L,Lb;
    Status i;
    ElemType e;

    i = InitList(&L);
    printf("初始化L后：L.length=%d\n", L.length);


    int j,k;
    for (j = 1; j <= 5; j++)
    {
        i = InsertList(&L, j, j);
    }
    i = ListIsEmpty(L);
    printf("\nL是否空：i=%d(1:是 0:否)\n", i);
    printf("\nL中目前有%d个元素！\n", ListLength(L));
    printf("\n表中的元素为:");
    Display(L);


    i = ClearList(&L);
    printf("\n清空L后：L.length=%d\n", L.length);
    i = ListIsEmpty(L);
    printf("\nL是否空：i=%d(1:是 0:否)\n", i);


    for (j = 1; j <= 10; j++)
    {
        InsertList(&L, j, 3*j);
    }   
    printf("\n表中的元素为:");
    Display(L);
    printf("\nL.length=%d \n", L.length);

    InsertList(&L, 1, 0);
    printf("在L的表头插入0后：L.data=");
    Display(L);
    printf("\nL.length=%d \n", L.length);

    GetElem(L, 5, &e);
    printf("第5个元素的值为：%d\n", e);


    for (j = 3; j <= 4; j++)
    {
        k = LocateElem(L, j);
        if (k)
            printf("\n第%d个元素的值为%d\n", k, j);
        else
            printf("\n没有值为%d的元素\n", j);
    }


    k = ListLength(L); 
    for (j = k + 1; j >= k; j--)
    {
        i = DeleteList(&L, j, &e); /* 删除第j个数据 */
        if (i == ERROR)
            printf("\n删除第%d个数据失败\n", j);
        else
            printf("\n删除第%d个的元素值为：%d\n", j, e);
    }
    printf("\n依次输出L的元素：");
    Display(L);

    j = 5;
    DeleteList(&L, j, &e); // 删除第5个数据 
    printf("删除第%d个的元素值为：%d\n", j, e);

    printf("依次输出L的元素：");
    Display(L);

    //构造一个有10个数的Lb
    i = InitList(&Lb);
    for (j = 6; j <= 15; j++)
    {
        i = InsertList(&Lb, 1, 100+j);
    }
    printf("\n依次输出Lb的元素：");
    Display(Lb);
    

    sqList L1;
    InitList(&L1);
    Intersection(&L1,L, Lb);
    printf("L1 = ");
    Display(L1);
    
    unionL(&L, Lb);
    printf("依次输出合并了Lb的L的元素：");
    Display(L);

    return 0;
}
