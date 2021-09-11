#define _CRT_SECURE_NO_WARNINGS 1

# include "StackList.h"

int main()
{
    LinkStack s;
    int j;
    ElemType e;

    if (InitStack(&s) == OK)
    {
        for (j = 1; j <= 5; j++)
        {
            PushStack(&s, j);
        }
    }        
    printf("ջ��Ԫ������Ϊ��");
    Display(s);
    
    PopStack(&s, &e);
    printf("������ջ��Ԫ�� e=%d\n", e);

    printf("ջ�շ�%d(1:�� 0:��)\n", StackIsEmpty(s));
    GetTop(s, &e);
    printf("ջ��Ԫ�� e=%d ջ�ĳ���Ϊ%d\n", e, StackLength(s));
    ClearStack(&s);
    printf("���ջ��ջ�շ�%d(1:�� 0:��)\n", StackIsEmpty(s));

    return 0;
}