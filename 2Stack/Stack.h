# include <stdio.h>
# include <stdlib.h>

# define MAXSIZE 20

# define OK 1
# define ERROR 0
# define TRUE 1
# define FALSE 0

typedef int ElemType;
typedef int Status;

struct Stack
{
	int top;
	ElemType data[MAXSIZE];
};

typedef struct Stack sqStack;

Status InitStack(sqStack* s);

Status ClearStack(sqStack* s);

Status StackEmpty(sqStack s);

int StackLength(sqStack s);

Status GetTop(sqStack s, ElemType* e);

Status Push(sqStack* s, ElemType e);

Status Pop(sqStack* s, ElemType* e);

Status Display(sqStack s);
