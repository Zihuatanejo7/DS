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

//  ���������������������
void InThreading(ThrTree T)
{
	if (T)
	{
		InThreading(T->lchild);         //�ݹ�������������

		if (!T->lchild)					// û������
		{
			T->l_Tag = Thread;			// ǰ������
			T->lchild = pre;			// ����ָ��ָ��ǰ��
		}

		if (!pre->rchild)               // ǰ��û���Һ���
		{
			pre->r_Tag = Thread;        // ������� 
			pre->rchild = T;            // ǰ���Һ���ָ��ָ����(��ǰ���T)
		}
		pre = T;                        // ����preָ��T��ǰ��
		InThreading(T->rchild);         // �ݹ������������� */
	}
}

// �������������T,����������������,Thrtָ��ͷ���
Status InOrderThreading(ThrTree* p, ThrTree T)
{
	*p = (ThrTree)malloc(sizeof(Node));   // ͷָ��
	if ((*p) == NULL)
	{
		return ERROR;
	}

	(*p)->l_Tag = Link;      // ��ͷ���
	(*p)->r_Tag = Thread;

	(*p)->rchild = (*p);     // ��ָ���ָ

	if (!T)                  // ����������,����ָ���ָ
	{
		(*p)->lchild = *p;
	}
	else
	{
		(*p)->lchild = T;
		pre = *p;
		InThreading(T);        // ���������������������
		pre->rchild = *p;
		pre->r_Tag = Thread;   //���һ�����������
		(*p)->rchild = pre;
	}
	return OK;
}

// �����������������T(ͷ���)�ķǵݹ��㷨
Status InOrderTraverse_Thr(ThrTree T)
{
	ThrTree p = T->lchild;                 // pָ������
	while (p != T)                 // p == T : ����
	{
		while (p->l_Tag == Link)   // ������
		{
			p = p->lchild;
		}
		printf("%c ", p->data);


		if ('#' == p->data)      // ������������Ϊ�յĽ��
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

