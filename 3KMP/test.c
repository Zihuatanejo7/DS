#define _CRT_SECURE_NO_WARNINGS 1

# include "KMP.h"

int main()
{
	char s1[MAXSIZE]; 
	char s2[MAXSIZE];

	StrAssign(s1, "000000000200000000020000000001");
	printf("主串为: ");
	Display(s1);

	printf("\n");
	StrAssign(s2, "000000001");
	printf("子串为: ");
	Display(s2);
	printf("\n");

	printf("\n");
	printf("主串和子串在第%d个字符处首次匹配（朴素模式匹配算法）\n", Index(s1, s2, 1));
	printf("主串和子串在第%d个字符处首次匹配（KMP算法） \n", Index_KMP(s1, s2, 1));

	return 0;
}