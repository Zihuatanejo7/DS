#define _CRT_SECURE_NO_WARNINGS 1

# include "String.h"

Status StrAssign(char dest[], char* ps)
{
	if (strlen(ps) >= MAXSIZE)
	{
		return ERROR;
	}

	dest[0] = strlen(ps);

	int i = 1;
	while (i <= dest[0])
	{
		dest[i] = *(ps + i - 1);
		i++;
	}
	return OK;
}

int StrLength(char dest[])
{
	return dest[0];
}

Status StrIsEmpty(char dest[])
{
	return dest[0] == 0 ? TRUE : FALSE;
}

Status StrCopy(char dest[], char src[])
{
	dest[0] = src[0];

	int i = 1;
	while (i <= dest[0])
	{
		dest[i] = src[i];
		i++;
	}

	return OK;
}

Status ClearString(char dest[])
{
	dest[0] = 0; 
	return OK;
}

int StrCompare(char dest[], char src[])
{
	int i = 1;
	while (i <= dest[0] && i <= src[0])
	{
		if (dest[i] != src[i])
		{
			return dest[i] - src[i];
		}
	}

	return dest[0] - src[0];
}

Status Concat(char dest[], char src1[], char src2[])
{
	if (src1[0] + src2[0] <= MAXSIZE)      // 完全嵌入
	{
		dest[0] = src1[0] + src2[0];

		int i = 1;
		while (i <= dest[0])
		{
			for (i; i <= src1[0]; i++)
			{
				dest[i] = src1[i];
			}

			for (i; i <= dest[0]; i++)
			{
				dest[i] = src2[i - src1[0]];
			}
		}
		return OK;
	}
	else                                  // 不完全嵌入
	{
		dest[0] = MAXSIZE;

		int i = 1;
		while (i <= dest[0])
		{
			for (i; i <= src1[0]; i++) 
			{
				dest[i] = src1[i];
			}

			for (i; i <= dest[0]; i++)
			{
				dest[i] = src2[i - src1[0]];
			}
		}
		return ERROR;
	}
}

Status SubString(char dest[], char src[], int pos, int len)
{
	if (pos < 1 || pos >src[0] || len > src[0] - pos + 1 || len <0)
	{
		return ERROR;
	}

	dest[0] = len;

	int i = 1;
	while (len--)
	{
		dest[i] = src[pos + i-1];
		i++;
	}
	return OK;
}

Status StrDelete(char dest[], int pos, int len)
{
	if (pos < 1 || pos >dest[0] || len > dest[0] - pos + 1)
	{
		return ERROR;
	}

	int i;
	for (i = pos + len; i <= dest[0]; i++)
	{
		dest[i - len] = dest[i];
	}	
	dest[0] = dest[0] -  len;
	return OK;
}

Status StrInsert(char dest[], int pos, char src[])
{
	if (pos < 1 || pos > dest[0])
	{
		return ERROR;
	}

	int i;
	
	if (dest[0] + src[0] <= MAXSIZE)   // 完全嵌入
	{
		for (i = dest[0]; i >= pos; i--)
		{
			dest[i+src[0]] = dest[i];
		}

		for (i = pos; i <= pos + src[0]; i++)
		{
			dest[i] = src[i - pos + 1];
		}
		dest[0] = dest[0] + src[0];

		return OK;
	}
	else                               // 不完全嵌入
	{
		for (i = MAXSIZE; i >= pos; i--)
		{
			dest[i] = dest[i-dest[0]];
		}

		for (i = pos; i <= pos + MAXSIZE - dest[0]; i++)
		{
			dest[i] = src[i - pos + 1];
		}

		dest[0] = MAXSIZE;
		return ERROR;
	}
}

Status Index(char dest[], char src[], int pos)
{
	if (pos < 1 || pos > dest[0] || src[0] > dest[0])
	{
		return ERROR;
	}

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
		return ERROR;
	}
}

Status Replace(char dest[], char src[], char V[])
{
	int i = 1; 
	if (StrIsEmpty(src)) 
		return ERROR;
	do
	{
		i = Index(dest, src, i); 
		if (i) 
		{
			StrDelete(dest, i, StrLength(src)); 
			StrInsert(dest, i, V); 
			i += StrLength(V); 
		}
	} while (i);
	return OK;
}

Status Display(char dest[])
{
	if (!dest[0])
	{
		return ERROR;
	}

	int i = 1;
	while (i <= dest[0])
	{
		printf("%c ", dest[i]);
		++i;
	}
	return OK;
}