#define _CRT_SECURE_NO_WARNINGS 1

# include "BinThrTree.h"

int main()
{
	ThrTree p, T;

	printf("请按前序输入二叉树(如:'ABDH##I##EJ###CF##G##')\n");


	CreateThrTree(&T);                       // 按前序产生二叉树

	InOrderThreading(&p, T);                 // 中序遍历,并中序线索化二叉树 

	printf("中序遍历(输出)二叉线索树:\n");

	InOrderTraverse_Thr(p); /* 中序遍历(输出)二叉线索树 */

	printf("\n");

	return 0;
}