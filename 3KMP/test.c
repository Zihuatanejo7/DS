#define _CRT_SECURE_NO_WARNINGS 1

# include "KMP.h"

int main()
{
	char s1[MAXSIZE]; 
	char s2[MAXSIZE];

	StrAssign(s1, "000000000200000000020000000001");
	printf("����Ϊ: ");
	Display(s1);

	printf("\n");
	StrAssign(s2, "000000001");
	printf("�Ӵ�Ϊ: ");
	Display(s2);
	printf("\n");

	printf("\n");
	printf("�������Ӵ��ڵ�%d���ַ����״�ƥ�䣨����ģʽƥ���㷨��\n", Index(s1, s2, 1));
	printf("�������Ӵ��ڵ�%d���ַ����״�ƥ�䣨KMP�㷨�� \n", Index_KMP(s1, s2, 1));

	return 0;
}