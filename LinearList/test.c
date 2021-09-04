#define _CRT_SECURE_NO_WARNINGS 1

# include "List.h"

int main()
{
	Sqlist L,Lb;
	Status i;
	ElemType e;

	int j,k;
	i= InitList(&L);
	printf("��ǰ����Ϊ%d��Ԫ��\n", L.length);

	for (j = 1; j <= 5; j++)
	{
		i = InsertList(&L, j, j);
	}
	DisplayList(L);
	printf("��ǰ����Ϊ%d��Ԫ��\n", L.length);

	i = ListEmpty(L);
	printf("L�Ƿ�գ�i=%d(1:�� 0:��)\n", i);

	i = ClearList(&L);
	i = ListEmpty(L);
	printf("L�Ƿ�գ�i=%d(1:�� 0:��)\n", i);

	for (j = 1; j <= 10; j++)
	{
		InsertList(&L, j, j);
	}
	DisplayList(L);
	printf("��ǰ����Ϊ%d��Ԫ��\n", L.length);

	InsertList(&L, 1, 0);
	DisplayList(L);
	printf("��ǰ����Ϊ%d��Ԫ��\n", L.length);

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

	k = ListLength(L);
	for (j = 5; j <= 6; j++)
	{
		ListDelete(&L, j, &e); 
		printf("ɾ����%d����Ԫ��ֵΪ��%d\n", j, e);
	}
	DisplayList(L);
	printf("��ǰ����Ϊ%d��Ԫ��\n", L.length);


	i = InitList(&Lb);
	for (j = 1; j <= 15; j++)
	{
		InsertList(&Lb, j, 2 * j);
	}
	DisplayList(Lb);
	printf("��ǰ����Ϊ%d��Ԫ��\n", Lb.length);

	unionL(&L, Lb);
	printf("��������ϲ���Lb��L��Ԫ�أ�");
	ListTraverse(L);
	return 0;
}