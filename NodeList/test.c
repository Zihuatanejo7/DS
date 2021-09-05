#define _CRT_SECURE_NO_WARNINGS 1
#include "NodeList.h"

int main(void)
{
	LinkList L;
	ElemType e;
	Status i;
	int j, k;

	i = InitList(&L);
	printf("初始化L后：ListLength(L)=%d\n", ListLength(L));
	Display(L);
	printf("ListLength(L)=%d \n", ListLength(L));

	for (j = 1; j <= 10; j++)
	{
		InsertList(&L, j, j);
	}
	Display(L);
	printf("ListLength(L)=%d \n", ListLength(L));

	i = ListEmpty(L);
	printf("L是否空：i=%d(1:是 0:否)\n", i);

	/*i = ClearList(&L);
	printf("清空L后：ListLength(L)=%d\n", ListLength(L));
	i = ListEmpty(L);
	printf("L是否空：i=%d(1:是 0:否)\n", i);*/

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

	k = ListLength(L); 
	for (j = k + 1; j >= k; j--)
	{
		i = ListDelete(&L, j, &e); 
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