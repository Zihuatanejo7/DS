#pragma once

# include <stdio.h>
# include <stdlib.h>

typedef char ElemType;

typedef struct Node
{
	ElemType data;
	struct Node* lchild, * rchild;

}Node,*Tree;


void InitBiTree(Tree *T);

void CreateBiTree(Tree* T);

int TreeIsEmpty(Tree T);

void ClearTree(Tree* T);

int TreeDepth(Tree T);

ElemType Root(Tree T);

void PreOrderTraverse(Tree T);

void InOrderTraverse(Tree T);

void PostOrderTraverse(Tree T);