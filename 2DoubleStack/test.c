#define _CRT_SECURE_NO_WARNINGS 1

# include "DoubleStack.h"

int main()
{
	sqStack s;
	Status i = InitStack(&s);
	int j = 0;
	ElemType e;
	int stackNumber = 1;
	printf("前面入栈：1 后面入栈：2,请选择：");
	scanf("%d", &stackNumber);

	if (i)
	{
		for (j = 0; j < 5; j++)
		{
			PushStack(&s, j, stackNumber);
		}	
	}
	Display(s);

	PopStack(&s, &e, 1);
	Display(s);
	return 0;
}