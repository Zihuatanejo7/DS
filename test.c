#define _CRT_SECURE_NO_WARNINGS 1

# include "StaticList.h"

int main()
{
    StaticLinkList L;
    Status i;
    i = InitList(L);
    printf("��ʼ��L��L.length=%d\n", ListLength(L));

    i = InsertList(L, 1, 'F');
    i = InsertList(L, 1, 'E');
    i = InsertList(L, 1, 'D');
    i = InsertList(L, 1, 'B');
    i = InsertList(L, 1, 'A');
    printf("\n��L�ı�ͷ���β���FEDBA��\nL.data=");
    Display(L);

    i = InsertList(L, 3, 'C');
    printf("\n��L�ġ�B���롰D��֮����롰C����\nL.data=");
    Display(L);
  
    i = DeleteList(L, 2);
    printf("\n��L��ɾ����A����\nL.data=");
    Display(L);
    
    return 0;
}