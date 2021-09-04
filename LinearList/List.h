# include <stdio.h>

# define MAXSIZE 30      //���Ա����洢����

# define OK 1
# define ERROR 0
# define TRUE 1
# define FALSE 0

typedef int Status;

typedef int ElemType;      // ����Ԫ��ʵ������

typedef struct
{
	ElemType data[MAXSIZE];     // data: ������Ԫ�ص�ַ
	int length;                 // length�� ��ǰ��ĳ���
}Sqlist;


// ��ʼ������
Status InitList(Sqlist* L);

// ����Ԫ��
Status InsertList(Sqlist* L, int i, ElemType e);

// ���Ԫ��
Status GetElem(Sqlist L, int i,ElemType* pe);

// ��ʾԪ��
Status DisplayList(Sqlist L);

// �ж��Ƿ�Ϊ�ձ�
Status ListEmpty(Sqlist L);

// ������Ա�
Status ClearList(Sqlist* L);

// ��λ�ض�Ԫ��
Status LocateElem(Sqlist L, ElemType e);

// ���ر�
int ListLength(Sqlist L);

// ɾ��Ԫ��
Status ListDelete(Sqlist* L, int i, ElemType* pe);

// �ϲ�Ԫ��
Status UnionList(Sqlist* La, Sqlist Lb);
