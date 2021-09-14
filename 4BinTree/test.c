#define _CRT_SECURE_NO_WARNINGS 1

# include "BinTree.h"

int main()
{
	int i;
	Tree T;
	ElemType e;
	InitBiTree(&T);

	// StrAssign(str, "ABDH#K###E##CFI###G#J##");

	CreateBiTree(&T);
	printf("����ն�������,���շ�%d(1:�� 0:��) �������=%d\n", TreeIsEmpty(T), TreeDepth(T));
	e = Root(T);
	printf("�������ĸ�Ϊ: %c\n", e);


	printf("\nǰ�����������:");
	PreOrderTraverse(T);

	printf("\n�������������:");
	InOrderTraverse(T);

	printf("\n�������������:");
	PostOrderTraverse(T);

	ClearTree(&T);
	printf("\n�����������,���շ�%d(1:�� 0:��) �������=%d\n", TreeIsEmpty(T), TreeDepth(T));
	i = Root(T);
	if (!i)
		printf("���գ��޸�\n");

	return 0;
}