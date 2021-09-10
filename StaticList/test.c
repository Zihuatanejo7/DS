#define _CRT_SECURE_NO_WARNINGS 1

# include "StaticList.h"

int main()
{
    StaticLinkList L;
    Status i;
    i = InitList(L);
    printf("初始化L后：L.length=%d\n", ListLength(L));

    i = InsertList(L, 1, 'F');
    i = InsertList(L, 1, 'E');
    i = InsertList(L, 1, 'D');
    i = InsertList(L, 1, 'B');
    i = InsertList(L, 1, 'A');
    printf("\n在L的表头依次插入FEDBA后：\nL.data=");
    Display(L);

    i = InsertList(L, 3, 'C');
    printf("\n在L的“B”与“D”之间插入“C”后：\nL.data=");
    Display(L);
  
    i = DeleteList(L, 2);
    printf("\n在L的删除“A”后：\nL.data=");
    Display(L);
    
    return 0;
}