#define _CRT_SECURE_NO_WARNINGS 1

# include "KMP.h"

Status StrAssign(char dest[], char* ps)
{
	if (strlen(ps) > MAXSIZE)
	{
		return ERROR;
	}

	dest[0] = strlen(ps);
	int i = 1;
	while (i <= dest[0])
	{
		dest[i] = ps[i - 1];
		i++;
	}

	return OK;
}

int Index(char dest[], char src[], int pos)
{
	int i = pos;
	int j = 1;
	while (i <= dest[0] && j <= src[0])
	{
		if (dest[i] == src[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 2;
			j = 1;
		}
	}

	if (j > src[0])
	{
		return i - src[0];
	}
	else
	{
		return 0;
	}
}

void get_next(char T[], int* next)
{
	int i = 1;
	int j = 0;
	next[1] = 0;
	while (i <= T[0])
	{
		if (j == 0 || T[i] == T[j]) 
		{
			j++;
			i++;
			next[i] = j;
		}
		else
		{
			j = next[j];
		}
	}
}

int Index_KMP(char dest[], char src[], int pos)
{
	int next[255];

	if (pos <1 || pos > dest[0])
	{
		return ERROR;
	}

	get_next(src, next);

	int i = pos;
	int j = 1;
	while (i <= dest[0] && j <= src[0])
	{
		if (j==0 || dest[i] == src[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}

	if (j > src[0])
	{
		return i - src[0];
	}
	else
	{
		return 0;
	}

	return OK;
}


//  输出Next数组值
void NextDisplay(int next[], int length)
{
	int i;
	for (i = 1; i <= length; i++)
	{
		printf("%d", next[i]);
	}
	printf("\n");
}


void Display(char dest[])
{
	int i = 1;
	while (i <= dest[0])
	{
		printf("%c	", dest[i]);
		i++;
	}
	printf("\n");
}