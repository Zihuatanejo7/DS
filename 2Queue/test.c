#define _CRT_SECURE_NO_WARNINGS 1

# include "Queue.h"

int main()
{
	sqQueue s;
	ElemType e;

	InitQueue(&s);
	printf("初始化队列后，队列空否？%u(1:空 0:否)\n", QueueIsEmpty(s));

	int j = 1;
	for (j = 1; j <= 20; j++)
	{
		EnQueue(&s, 2*j);
	}
	printf("队列长度为: %d\n", QueueLength(s));
	printf("现在队列空否？%u(1:空 0:否)\n", QueueIsEmpty(s));
	Display(s);


	int i = 1;
	for (i = 1; i <= 10; i++)
	{
		DeQueue(&s, &e);
		printf("删除的元素是%d,插入的元素:%d \n", e, e + 1000);
		e = e + 1000;
		EnQueue(&s, e);
	}
	printf("现在队列中的元素为: \n");
	Display(s);

	j = GetHead(s, &e);
	if (j)
	{
		printf("现在队头元素为: %d\n", e);
	}
		
	ClearQueue(&s);
	printf("清空队列后, 队列空否？%u(1:空 0:否)\n", QueueIsEmpty(s));

	return 0;
}