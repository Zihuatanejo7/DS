#define _CRT_SECURE_NO_WARNINGS 1

# include "QueueList.h"


int main()
{
	LinkQueue s;
	ElemType e;

	Status i = InitQueue(&s);
	if (i)
		printf("�ɹ��ع�����һ���ն���!\n");

	printf("\n�Ƿ�ն��У�%d(1:�� 0:��) \n", QueueIsEmpty(s));

	printf("\n���еĳ���Ϊ%d\n", QueueLength(s));

	EnQueue(&s, -5);
	EnQueue(&s, 5);
	EnQueue(&s, 10);
	printf("\n����3��Ԫ��(-5,5,10)��,���еĳ���Ϊ%d\n", QueueLength(s));

	printf("\n�Ƿ�ն��У�%d(1:�� 0:��)  ", QueueIsEmpty(s));
	printf("\n���е�Ԫ������Ϊ��");
	Display(s);

	i = GetHead(s, &e);
	if (i == OK)
	{
		printf("��ͷԪ���ǣ�%d\n", e);
	}	

	DeQueue(&s, &e);
	printf("ɾ���˶�ͷԪ��%d\n", e);
	Display(s);

	i = GetHead(s, &e);
	if (i == OK)
	{
		printf("�µĶ�ͷԪ���ǣ�%d\n", e);
	}
		
	ClearQueue(&s);
	printf("��ն��к�,q.front=%u q.rear=%u q.front->next=%u\n", s.front, s.rear, s.front->next);

	return 0;
}
