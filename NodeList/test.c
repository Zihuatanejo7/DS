#define _CRT_SECURE_NO_WARNINGS 1

# include "NodeList.h"

int main()
{
    LinkList L;
    Status i;
    ElemType e;
    int j, k;

    i = InitList(&L);
    printf("��ʼ��L��ListLength(L)=%d\n", ListLength(L));
    for (j = 1; j <= 5; j++)
    {
        i = InsertList(&L, 1, j);
    }
    printf("Ŀǰ�����е�Ԫ��Ϊ:");
    Display(L);
    i = ListIsEmpty(L);
    printf("\nL�Ƿ�գ�i=%d(1:�� 0:��)\n", i);
    printf("\nListLength(L)=%d \n", ListLength(L));

    i = ClearList(&L);
    printf("\n���L��ListLength(L)=%d\n", ListLength(L));
    i = ListIsEmpty(L);
    printf("\nL�Ƿ�գ�i=%d(1:�� 0:��)\n", i);

    for (j = 1; j <= 10; j++) 
    {
        InsertList(&L, j, j);
    }
    printf("Ŀǰ�����е�Ԫ��Ϊ:");
    Display(L);

    printf("\nListLength(L)=%d \n", ListLength(L));

    GetElem(L, 5, &e);
    printf("��5��Ԫ�ص�ֵΪ��%d\n", e);


    for (j = 3; j <= 4; j++)
    {
        k = LocateElem(L, j);
        if (k)
        {
            printf("��%d��Ԫ�ص�ֵΪ%d\n", k, j);
        }    
        else
        {
            printf("û��ֵΪ%d��Ԫ��\n", j);
        }    
    }

    k = ListLength(L); // kΪ�� 
    for (j = k + 1; j >= k; j--)
    {
        i = DeleteList(&L, j, &e); // ɾ����j������
        if (i == ERROR)
        {
            printf("ɾ����%d������ʧ��\n", j);
        }  
        else
        {
            printf("ɾ����%d����Ԫ��ֵΪ��%d\n", j, e);
        }       
    }
    printf("�������L��Ԫ�أ�");
    Display(L);

    j = 5;
    DeleteList(&L, j, &e);     // ɾ����5������
    printf("\nɾ����%d����Ԫ��ֵΪ��%d\n", j, e);

    printf("�������L��Ԫ�أ�");
    Display(L);

    i = ClearList(&L);
    printf("\n���L��ListLength(L)=%d\n", ListLength(L));

    CreateListHead(&L, 20);
    printf("���崴��L��Ԫ��(ͷ�巨)��");
    Display(L);

    i = ClearList(&L);
    printf("\nɾ��L��ListLength(L)=%d\n", ListLength(L));
    CreateListTail(&L, 20);
    printf("���崴��L��Ԫ��(β�巨)��");
    Display(L);

    return 0;
}