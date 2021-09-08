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
	printf("表中元素依次为:");
	Display(s);

	Pop(&s, &e);
	printf("%d\n", e);

	Pop(&s, &e);
	printf("%d\n", e);

	Pop(&s, &e);
	printf("%d\n", e);

	printf("栈是否为空：%d(1:空 0:否)\n", StackEmpty(s));

	GetTop(s, &e);
	printf("%d\n", e);

	printf("栈顶元素 e=%d 栈的长度为%d\n", e, StackLength(s));
	ClearStack(&s);
	printf("清空栈后，栈空否：%d(1:空 0:否)\n", StackEmpty(s));

	return 0;
}