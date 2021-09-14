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
	printf("构造空二叉树后,树空否？%d(1:是 0:否) 树的深度=%d\n", TreeIsEmpty(T), TreeDepth(T));
	e = Root(T);
	printf("二叉树的根为: %c\n", e);


	printf("\n前序遍历二叉树:");
	PreOrderTraverse(T);

	printf("\n中序遍历二叉树:");
	InOrderTraverse(T);

	printf("\n后序遍历二叉树:");
	PostOrderTraverse(T);

	ClearTree(&T);
	printf("\n清除二叉树后,树空否？%d(1:是 0:否) 树的深度=%d\n", TreeIsEmpty(T), TreeDepth(T));
	i = Root(T);
	if (!i)
		printf("树空，无根\n");

	return 0;
}