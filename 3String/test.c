#define _CRT_SECURE_NO_WARNINGS 1

# include "String.h"

int main()
{
	Status k;
	char t[MAXSIZE + 1];
	char s1[MAXSIZE + 1];
	char s2[MAXSIZE + 1];

	k = StrAssign(s1, "abcdABCDabcd");
	if (!k)
	{
		printf("串长超过MAXSIZE(=%d)\n", MAXSIZE);
	}
	printf("串s1中的元素为:");
	Display(s1);
	printf("\n串长为%d 串空否？%d(1:是 0:否)\n", StrLength(s1), StrIsEmpty(s1));

	StrCopy(s2, s1);
	printf("串s2中的元素为:");
	Display(s2);

	printf("\n");
	k = StrAssign(s2, "efghijk");
	if (!k)
	{
		printf("串长超过MAXSIZE(%d)\n", MAXSIZE);
	}
	printf("\n串s2中的元素为:");
	Display(s2);
	

	int i = StrCompare(s1, s2);
	if (i > 0)
		printf(" s1 > s2\n");
	else if (i == 0)
		printf(" s1 = s2\n");
	else
		printf(" s1 < s2\n");

	k = Concat(t, s1, s2);
	if (k == FALSE)
	{
		printf("串t有截断\n");
	}
	printf("\n串t为: ");
	Display(t);
	
	ClearString(s1);
	printf("\n清为空串后,串s1为: ");
	Display(s1);
	printf("\n串长为%d 串空否？%d(1:是 0:否)\n", StrLength(s1), StrIsEmpty(s1));
	
	
	i = 2;
	int j = 4;
	k = SubString(s2, t, i, j);
	if (k)
	{
		printf("串T的子串s2为: ");
		Display(s2);
	}

	i = 4;
	j = 2;
	StrDelete(t, i, j);
	printf("\n删除后的串t为: ");
	Display(t);


	i = StrLength(s2) / 2;
	StrInsert(s2, i, t);
	printf("\n在串s2的第%d个字符之前插入串t后,串s2为:", i);
	Display(s2);

	StrAssign(t, "cde");
	i = Index(s2, t, 1);
	printf("\ns2的第%d个字母起和t第一次匹配:", i);


	SubString(t, s2, 1, 3);
	printf("\n串t为：");
	Display(t);
	Concat(s1, t, t);
	printf("串s1为：");
	Display(s1);

	Replace(s2, t, s1);
	printf("\n用串s1取代串s2中和串t相同的不重叠的串后,串s2为: ");
	Display(s2);

	return 0;
}