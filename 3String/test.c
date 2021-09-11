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
		printf("��������MAXSIZE(=%d)\n", MAXSIZE);
	}
	printf("��s1�е�Ԫ��Ϊ:");
	Display(s1);
	printf("\n����Ϊ%d ���շ�%d(1:�� 0:��)\n", StrLength(s1), StrIsEmpty(s1));

	StrCopy(s2, s1);
	printf("��s2�е�Ԫ��Ϊ:");
	Display(s2);

	printf("\n");
	k = StrAssign(s2, "efghijk");
	if (!k)
	{
		printf("��������MAXSIZE(%d)\n", MAXSIZE);
	}
	printf("\n��s2�е�Ԫ��Ϊ:");
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
		printf("��t�нض�\n");
	}
	printf("\n��tΪ: ");
	Display(t);
	
	ClearString(s1);
	printf("\n��Ϊ�մ���,��s1Ϊ: ");
	Display(s1);
	printf("\n����Ϊ%d ���շ�%d(1:�� 0:��)\n", StrLength(s1), StrIsEmpty(s1));
	
	
	i = 2;
	int j = 4;
	k = SubString(s2, t, i, j);
	if (k)
	{
		printf("��T���Ӵ�s2Ϊ: ");
		Display(s2);
	}

	i = 4;
	j = 2;
	StrDelete(t, i, j);
	printf("\nɾ����Ĵ�tΪ: ");
	Display(t);


	i = StrLength(s2) / 2;
	StrInsert(s2, i, t);
	printf("\n�ڴ�s2�ĵ�%d���ַ�֮ǰ���봮t��,��s2Ϊ:", i);
	Display(s2);

	StrAssign(t, "cde");
	i = Index(s2, t, 1);
	printf("\ns2�ĵ�%d����ĸ���t��һ��ƥ��:", i);


	SubString(t, s2, 1, 3);
	printf("\n��tΪ��");
	Display(t);
	Concat(s1, t, t);
	printf("��s1Ϊ��");
	Display(s1);

	Replace(s2, t, s1);
	printf("\n�ô�s1ȡ����s2�кʹ�t��ͬ�Ĳ��ص��Ĵ���,��s2Ϊ: ");
	Display(s2);

	return 0;
}