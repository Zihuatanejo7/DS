//  ���Ա��˳��洢�ṹ - ����

# include <stdio.h>

# define MAXSIZE 50       // ���Ա���󳤶�

# define ERROR 0
# define OK 1

# define TRUE 1
# define FALSE 0
typedef int ElemType;
typedef int Status;

typedef struct
{
	ElemType data[MAXSIZE];
	int length;        // ��ǰ���Ա���
}sqList;

// ��ʼ������
Status InitList(sqList *L);

// ��
int ListLength(sqList L);

// ���Ƿ�Ϊ��
Status ListIsEmpty(sqList L);

//����Ԫ��
Status InsertList(sqList* L, int pos, ElemType e);

// ɾ��Ԫ��
Status DeleteList(sqList* L, int pos, ElemType* e);

// ���ȫ��Ԫ��
Status ClearList(sqList* L);

// ��ʾԪ��
Status Display(sqList L);

// ��ȡ�ض�Ԫ��
Status GetElem(sqList L, int pos, ElemType* e);

// �����ض�Ԫ���±�
int LocateElem(sqList L, ElemType e);

// ��L��Lb�Ľ�Ԫ�ط���L��
void Intersection(sqList* L1, sqList La,sqList Lb);

void unionL(sqList* L, sqList Lb);