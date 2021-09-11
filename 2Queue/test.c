#define _CRT_SECURE_NO_WARNINGS 1

# include "Queue.h"

int main()
{
	sqQueue s;
	ElemType e;

	InitQueue(&s);
	printf("��ʼ�����к󣬶��пշ�%u(1:�� 0:��)\n", QueueIsEmpty(s));

	int j = 1;
	for (j = 1; j <= 20; j++)
	{
		EnQueue(&s, 2*j);
	}
	printf("���г���Ϊ: %d\n", QueueLength(s));
	printf("���ڶ��пշ�%u(1:�� 0:��)\n", QueueIsEmpty(s));
	Display(s);


	int i = 1;
	for (i = 1; i <= 10; i++)
	{
		DeQueue(&s, &e);
		printf("ɾ����Ԫ����%d,�����Ԫ��:%d \n", e, e + 1000);
		e = e + 1000;
		EnQueue(&s, e);
	}
	printf("���ڶ����е�Ԫ��Ϊ: \n");
	Display(s);

	j = GetHead(s, &e);
	if (j)
	{
		printf("���ڶ�ͷԪ��Ϊ: %d\n", e);
	}
		
	ClearQueue(&s);
	printf("��ն��к�, ���пշ�%u(1:�� 0:��)\n", QueueIsEmpty(s));

	return 0;
}