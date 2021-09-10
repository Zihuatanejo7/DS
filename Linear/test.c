#define _CRT_SECURE_NO_WARNINGS 1

# include "LinearList.h"

int main()
{

    sqList L,Lb;
    Status i;
    ElemType e;

    i = InitList(&L);
    printf("��ʼ��L��L.length=%d\n", L.length);


    int j,k;
    for (j = 1; j <= 5; j++)
    {
        i = InsertList(&L, j, j);
    }
    i = ListIsEmpty(L);
    printf("\nL�Ƿ�գ�i=%d(1:�� 0:��)\n", i);
    printf("\nL��Ŀǰ��%d��Ԫ�أ�\n", ListLength(L));
    printf("\n���е�Ԫ��Ϊ:");
    Display(L);


    i = ClearList(&L);
    printf("\n���L��L.length=%d\n", L.length);
    i = ListIsEmpty(L);
    printf("\nL�Ƿ�գ�i=%d(1:�� 0:��)\n", i);


    for (j = 1; j <= 10; j++)
    {
        InsertList(&L, j, 3*j);
    }   
    printf("\n���е�Ԫ��Ϊ:");
    Display(L);
    printf("\nL.length=%d \n", L.length);

    InsertList(&L, 1, 0);
    printf("��L�ı�ͷ����0��L.data=");
    Display(L);
    printf("\nL.length=%d \n", L.length);

    GetElem(L, 5, &e);
    printf("��5��Ԫ�ص�ֵΪ��%d\n", e);


    for (j = 3; j <= 4; j++)
    {
        k = LocateElem(L, j);
        if (k)
            printf("\n��%d��Ԫ�ص�ֵΪ%d\n", k, j);
        else
            printf("\nû��ֵΪ%d��Ԫ��\n", j);
    }


    k = ListLength(L); 
    for (j = k + 1; j >= k; j--)
    {
        i = DeleteList(&L, j, &e); /* ɾ����j������ */
        if (i == ERROR)
            printf("\nɾ����%d������ʧ��\n", j);
        else
            printf("\nɾ����%d����Ԫ��ֵΪ��%d\n", j, e);
    }
    printf("\n�������L��Ԫ�أ�");
    Display(L);

    j = 5;
    DeleteList(&L, j, &e); // ɾ����5������ 
    printf("ɾ����%d����Ԫ��ֵΪ��%d\n", j, e);

    printf("�������L��Ԫ�أ�");
    Display(L);

    //����һ����10������Lb
    i = InitList(&Lb);
    for (j = 6; j <= 15; j++)
    {
        i = InsertList(&Lb, 1, 100+j);
    }
    printf("\n�������Lb��Ԫ�أ�");
    Display(Lb);
    

    sqList L1;
    InitList(&L1);
    Intersection(&L1,L, Lb);
    printf("L1 = ");
    Display(L1);
    
    unionL(&L, Lb);
    printf("��������ϲ���Lb��L��Ԫ�أ�");
    Display(L);

    return 0;
}
