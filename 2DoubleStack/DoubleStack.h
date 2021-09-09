# include <stdio.h>

# define MAXSIZE 100

# define OK 1
# define ERROR 0
# define TRUE 1
# define FALSE 0

typedef int ElemType;
typedef int Status;

struct DoubleStack
{
	ElemType data[MAXSIZE];
	int top1;
	int top2;
};

typedef struct DoubleStack sqStack;

Status InitStack(sqStack* s);

Status PushStack(sqStack* s, ElemType e, int stackNumber);

Status PopStack(sqStack* s, ElemType* e, int stackNumber);

Status GetTop(sqStack s, ElemType* e, int stackNumber);

int StackLength(sqStack s, int stackNumber);

Status Display(sqStack s);

Status ClearStack(sqStack* s);