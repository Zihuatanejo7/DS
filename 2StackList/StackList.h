# include <stdio.h>
# include <stdlib.h>

typedef int Status;
typedef int ElemType;

# define OK 1
# define ERROR 0
# define TRUE 1
# define FALSE 0

typedef struct Node
{
	ElemType data;
	struct Node* next;
}Node,*LinkStackPtr;

typedef struct
{
	LinkStackPtr top;
	int count;
}LinkStack;

Status InitStack(LinkStack* s);

Status ClearStack(LinkStack* s);

int StackLength(LinkStack s);

Status StackIsEmpty(LinkStack s);

Status GetTop(LinkStack s, ElemType* e);

//»Î’ª
Status PushStack(LinkStack* s, ElemType e);

// ≥ˆ’ª
Status PopStack(LinkStack* s, ElemType* e);

Status Display(LinkStack s);