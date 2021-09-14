# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# define STACK_INIT_SIZE 30
# define OFFSET 5


# define ERROR 0
# define OK 1

typedef int Status;
typedef char ElemType;

typedef struct Stack
{
	int StackSize;
	ElemType* base;
	ElemType* top;
}sqStack;

Status InitStack(sqStack* s);

Status PushStack(sqStack* s, ElemType e);

Status PopStack(sqStack* s, ElemType* e);

void DestroyStack(sqStack* s);

void ClearStack(sqStack* s);

int StackLen(sqStack s);

void DestroyStack(sqStack* s);

void Display(sqStack *s);

