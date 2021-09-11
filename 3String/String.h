// ´®

# include <stdio.h>
# include <string.h>

# define TRUE 1
# define FALSE 0

# define MAXSIZE 50
# define ERROR 0
# define OK 1

typedef int Status;

Status StrAssign(char dest[], char *ps);

int StrLength(char dest[]);

Status ClearString(char dest[]);

Status StrIsEmpty(char dest[]);

Status StrCopy(char dest[], char src[]);

int StrCompare(char dest[], char src[]);

Status Concat(char dest[], char src1[], char src2[]);

Status SubString(char dest[], char src[], int pos, int len);

Status StrDelete(char dest[], int pos, int len);

Status StrInsert(char dest[], int pos, char src[]);

Status Index(char dest[], char src[], int pos);

Status Replace(char dest[], char src[], char V[]);

Status Display(char dest[]);