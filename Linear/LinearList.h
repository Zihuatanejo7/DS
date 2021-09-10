//  线性表的顺序存储结构 - 数组

# include <stdio.h>

# define MAXSIZE 50       // 线性表最大长度

# define ERROR 0
# define OK 1

# define TRUE 1
# define FALSE 0
typedef int ElemType;
typedef int Status;

typedef struct
{
	ElemType data[MAXSIZE];
	int length;        // 当前线性表长度
}sqList;

// 初始化函数
Status InitList(sqList *L);

// 表长
int ListLength(sqList L);

// 表是否为空
Status ListIsEmpty(sqList L);

//插入元素
Status InsertList(sqList* L, int pos, ElemType e);

// 删除元素
Status DeleteList(sqList* L, int pos, ElemType* e);

// 清空全部元素
Status ClearList(sqList* L);

// 显示元素
Status Display(sqList L);

// 获取特定元素
Status GetElem(sqList L, int pos, ElemType* e);

// 返回特定元素下标
int LocateElem(sqList L, ElemType e);

// 将L和Lb的交元素放入L中
void Intersection(sqList* L1, sqList La,sqList Lb);

void unionL(sqList* L, sqList Lb);