#define _CRT_SECURE_NO_WARNINGS 1

# include "List.h"

int main()
{
	Sqlist L,Lb;
	Status i;
	ElemType e;

	int j,k;
	i= InitList(&L);
	printf("当前表中为%d个元素\n", L.length);

	for (j = 1; j <= 5; j++)
	{
		i = InsertList(&L, j, j);
	}
	DisplayList(L);
	printf("当前表中为%d个元素\n", L.length);

	i = ListEmpty(L);
	printf("L是否空：i=%d(1:是 0:否)\n", i);

	i = ClearList(&L);
	i = ListEmpty(L);
	printf("L是否空：i=%d(1:是 0:否)\n", i);

	for (j = 1; j <= 10; j++)
	{
		InsertList(&L, j, j);
	}
	DisplayList(L);
	printf("当前表中为%d个元素\n", L.length);

	InsertList(&L, 1, 0);
	DisplayList(L);
	printf("当前表中为%d个元素\n", L.length);

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

	k = ListLength(L);
	for (j = 5; j <= 6; j++)
	{
		ListDelete(&L, j, &e); 
		printf("删除第%d个的元素值为：%d\n", j, e);
	}
	DisplayList(L);
	printf("当前表中为%d个元素\n", L.length);


	i = InitList(&Lb);
	for (j = 1; j <= 15; j++)
	{
		InsertList(&Lb, j, 2 * j);
	}
	DisplayList(Lb);
	printf("当前表中为%d个元素\n", Lb.length);

	unionL(&L, Lb);
	printf("依次输出合并了Lb的L的元素：");
	ListTraverse(L);
	return 0;
}