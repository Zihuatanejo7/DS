#define _CRT_SECURE_NO_WARNINGS 1

# include "Stack.h"
int main()
{
	sqStack s;
	ElemType e;
	Status i = InitStack(&s);
	int j = 0;
	if (i)
	{
		for (j = 0; j < MAXSIZE - 5; j++)
		{
			Push(&s, 2 * j);
		}
	}
	printf("����Ԫ������Ϊ:");
	Display(s);

	Pop(&s, &e);
	printf("%d\n", e);

	Pop(&s, &e);
	printf("%d\n", e);

	Pop(&s, &e);
	printf("%d\n", e);

	printf("ջ�Ƿ�Ϊ�գ�%d(1:�� 0:��)\n", StackEmpty(s));

	GetTop(s, &e);
	printf("%d\n", e);

	printf("ջ��Ԫ�� e=%d ջ�ĳ���Ϊ%d\n", e, StackLength(s));
	ClearStack(&s);
	printf("���ջ��ջ�շ�%d(1:�� 0:��)\n", StackEmpty(s));

	return 0;
}