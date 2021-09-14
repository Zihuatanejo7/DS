#pragma once

# include <stdio.h>
# include <stdlib.h>

# define ERROR 0
# define OK 1

typedef int Status;
typedef char ElemType;

typedef enum 
{
	Link,Thread   // Link ���Һ���ָ��  Thread ǰ�����
}Tag;

typedef struct Node
{
	ElemType data;
	struct Node* rchild, * lchild;
	Tag l_Tag, r_Tag;
}Node,*ThrTree;

ThrTree pre;   // �ϴη��ʵĽڵ�

void CreateThrTree(ThrTree *T);

void InThreading(ThrTree T);

Status InOrderThreading(ThrTree* p, ThrTree T);

Status InOrderTraverse_Thr(ThrTree T);

Status InOrderTraverse_Thr1(ThrTree T);