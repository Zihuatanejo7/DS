// KMP �㷨

# include <stdio.h> 
# include <string.h>

# define OK 1
# define ERROR 0

# define MAXSIZE 80 

typedef int Status;		
typedef int ElemType;	

Status StrAssign(char dest[], char* ps);

// ����ģʽƥ��
int Index(char dest[], char src[], int pos);

// KMPģʽƥ��
void get_next(char T[], int* next);

int Index_KMP(char dest[], char src[], int pos);

void Display(char dest[]);
