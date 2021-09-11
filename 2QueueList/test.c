#define _CRT_SECURE_NO_WARNINGS 1

# include "QueueList.h"


int main()
{
	LinkQueue s;
	ElemType e;

	Status i = InitQueue(&s);
	if (i)
		printf("成功地构造了一个空队列!\n");

	printf("\n是否空队列？%d(1:空 0:否) \n", QueueIsEmpty(s));

	printf("\n队列的长度为%d\n", QueueLength(s));

	EnQueue(&s, -5);
	EnQueue(&s, 5);
	EnQueue(&s, 10);
	printf("\n插入3个元素(-5,5,10)后,队列的长度为%d\n", QueueLength(s));

	printf("\n是否空队列？%d(1:空 0:否)  ", QueueIsEmpty(s));
	printf("\n队列的元素依次为：");
	Display(s);

	i = GetHead(s, &e);
	if (i == OK)
	{
		printf("队头元素是：%d\n", e);
	}	

	DeQueue(&s, &e);
	printf("删除了队头元素%d\n", e);
	Display(s);

	i = GetHead(s, &e);
	if (i == OK)
	{
		printf("新的队头元素是：%d\n", e);
	}
		
	ClearQueue(&s);
	printf("清空队列后,q.front=%u q.rear=%u q.front->next=%u\n", s.front, s.rear, s.front->next);

	return 0;
}
