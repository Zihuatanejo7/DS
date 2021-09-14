#define _CRT_SECURE_NO_WARNINGS 1

# include "BinToDec.h"

int main()
{
	sqStack s;
	ElemType c;
	int sum = 0, i;
	InitStack(&s);

	printf("请输入二进制数，以＃号结束");
	scanf("%c", &c);
	while (c != '#')
	{
		PushStack(&s, c);
		scanf("%c", &c);
	}
	getchar();

	Display(&s);

	int len = StackLen(s);
	printf("\n当前栈的长度为%d\n", len);

	for (i = 0; i < len; i++)
	{
		PopStack(&s, &c);
		printf("%d\n", c - 48);
		sum = sum + (c - 48) * pow(2, i);
	}
	printf("\n最后的结果为%d", sum);
	return 0;
}