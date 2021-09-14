#define _CRT_SECURE_NO_WARNINGS 1

#define _CRT_SECURE_NO_WARNINGS 1

# include "BinThrTree.h"

void CreateThrTree(ThrTree* T)
{
	ElemType c;
	scanf("%c", &c);

	if ('#' == c)
	{
		*T = NULL;
	}
	else
	{
		*T = (ThrTree)malloc(sizeof(Node));
		if (!(*T))
		{
			exit(0);
		}

		(*T)->data = c;
		CreateThrTree(&(*T)->lchild);
		if ((*T)->lchild)
		{
			(*T)->l_Tag = Link;
		}

		CreateThrTree(&(*T)->rchild);
		if ((*T)->rchild)
		{
			(*T)->r_Tag = Link;
		}
	}

}

//  中序遍历进行中序线索化
void InThreading(ThrTree T)
{
	if (T)
	{
		InThreading(T->lchild);         //递归左子树线索化

		if (!T->lchild)					// 没有左孩子
		{
			T->l_Tag = Thread;			// 前驱线索
			T->lchild = pre;			// 左孩子指针指向前驱
		}

		if (!pre->rchild)               // 前驱没有右孩子
		{
			pre->r_Tag = Thread;        // 后继线索 
			pre->rchild = T;            // 前驱右孩子指针指向后继(当前结点T)
		}
		pre = T;                        // 保持pre指向T的前驱
		InThreading(T->rchild);         // 递归右子树线索化 */
	}
}

// 中序遍历二叉树T,并将其中序线索化,Thrt指向头结点
Status InOrderThreading(ThrTree* p, ThrTree T)
{
	*p = (ThrTree)malloc(sizeof(Node));   // 头指针
	if ((*p) == NULL)
	{
		return ERROR;
	}

	(*p)->l_Tag = Link;      // 建头结点
	(*p)->r_Tag = Thread;

	(*p)->rchild = (*p);     // 右指针回指

	if (!T)                  // 若二叉树空,则左指针回指
	{
		(*p)->lchild = *p;
	}
	else
	{
		(*p)->lchild = T;
		pre = *p;
		InThreading(T);        // 中序遍历进行中序线索化
		pre->rchild = *p;
		pre->r_Tag = Thread;   //最后一个结点线索化
		(*p)->rchild = pre;
	}
	return OK;
}

// 中序遍历二叉线索树T(头结点)的非递归算法
Status InOrderTraverse_Thr(ThrTree T)
{
	ThrTree p = T->lchild;                 // p指向根结点
	while (p != T)                 // p == T : 空树
	{
		while (p->l_Tag == Link)   // 有左孩子
		{
			p = p->lchild;
		}
		printf("%c ", p->data);


		if ('#' == p->data)      // 访问其左子树为空的结点
		{
			return ERROR;
		}

		while (p->r_Tag == Thread && p->rchild != T)
		{
			p = p->rchild;
			printf("%c   \n", p->data);
		}

		p = p->rchild;
	}
	return OK;
}

