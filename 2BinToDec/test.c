#define _CRT_SECURE_NO_WARNINGS 1

# include "BinToDec.h"

int main()
{
	sqStack s;
	ElemType c;
	int sum = 0, i;
	InitStack(&s);

	printf("����������������ԣ��Ž���");
	scanf("%c", &c);
	while (c != '#')
	{
		PushStack(&s, c);
		scanf("%c", &c);
	}
	getchar();

	Display(&s);

	int len = StackLen(s);
	printf("\n��ǰջ�ĳ���Ϊ%d\n", len);

	for (i = 0; i < len; i++)
	{
		PopStack(&s, &c);
		printf("%d\n", c - 48);
		sum = sum + (c - 48) * pow(2, i);
	}
	printf("\n���Ľ��Ϊ%d", sum);
	return 0;
}