#pragma once

# include <stdio.h>
# include <stdlib.h>

# define ERROR 0
# define OK 1

typedef int Status;
typedef char ElemType;

typedef enum 
{
	Link,Thread   // Link 左右孩子指针  Thread 前驱后继
}Tag;

typedef struct Node
{
	ElemType data;
	struct Node* rchild, * lchild;
	Tag l_Tag, r_Tag;
}Node,*ThrTree;

ThrTree pre;   // 上次访问的节点

void CreateThrTree(ThrTree *T);

void InThreading(ThrTree T);

Status InOrderThreading(ThrTree* p, ThrTree T);

Status InOrderTraverse_Thr(ThrTree T);

Status InOrderTraverse_Thr1(ThrTree T);