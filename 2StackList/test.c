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
    printf("Õ»ÖÐÔªËØÒÀ´ÎÎª£º");
    Display(s);
    
    PopStack(&s, &e);
    printf("µ¯³öµÄÕ»¶¥ÔªËØ e=%d\n", e);

    printf("Õ»¿Õ·ñ£º%d(1:¿Õ 0:·ñ)\n", StackIsEmpty(s));
    GetTop(s, &e);
    printf("Õ»¶¥ÔªËØ e=%d Õ»µÄ³¤¶ÈÎª%d\n", e, StackLength(s));
    ClearStack(&s);
    printf("Çå¿ÕÕ»ºó£¬Õ»¿Õ·ñ£º%d(1:¿Õ 0:·ñ)\n", StackIsEmpty(s));

    return 0;
}