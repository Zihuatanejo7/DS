#define _CRT_SECURE_NO_WARNINGS 1

# include "BinThrTree.h"

int main()
{
	ThrTree p, T;

	printf("�밴ǰ�����������(��:'ABDH##I##EJ###CF##G##')\n");


	CreateThrTree(&T);                       // ��ǰ�����������

	InOrderThreading(&p, T);                 // �������,������������������ 

	printf("�������(���)����������:\n");

	InOrderTraverse_Thr(p); /* �������(���)���������� */

	printf("\n");

	return 0;
}