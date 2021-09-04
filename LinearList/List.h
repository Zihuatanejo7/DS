# include <stdio.h>

# define MAXSIZE 30      //线性表最大存储容量

# define OK 1
# define ERROR 0
# define TRUE 1
# define FALSE 0

typedef int Status;

typedef int ElemType;      // 表中元素实际类型

typedef struct
{
	ElemType data[MAXSIZE];     // data: 表内首元素地址
	int length;                 // length： 当前表的长度
}Sqlist;


// 初始化函数
Status InitList(Sqlist* L);

// 插入元素
Status InsertList(Sqlist* L, int i, ElemType e);

// 获得元素
Status GetElem(Sqlist L, int i,ElemType* pe);

// 显示元素
Status DisplayList(Sqlist L);

// 判断是否为空表
Status ListEmpty(Sqlist L);

// 清空线性表
Status ClearList(Sqlist* L);

// 定位特定元素
Status LocateElem(Sqlist L, ElemType e);

// 返回表长
int ListLength(Sqlist L);

// 删除元素
Status ListDelete(Sqlist* L, int i, ElemType* pe);

// 合并元素
Status UnionList(Sqlist* La, Sqlist Lb);
