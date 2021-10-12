/*
选择排序思路：
1. 比较相邻的元素。如果第一个比第二个大，就交换他们两个。
2. 对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对。这步做完后，最后的元素会是最大的数
*/


}

// 冒泡排序
void sort1 (int arr[],int len)
{
    for (int i = 0;i<len;i++)
    {
        for (j = 0;j<N-1-i;j++)
        {
            if (arr[j]>arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
            }
        }
        
    }  	
}

// 冒泡排序（改进版）
void sort2 (int arr[],int len)
{
    for (int i = 0;i<len;i++)
    {
        // 数组是否有序标志
        int flag = 0；
             
        for (j = 0;j<N-1-i;j++)
        {
            if (arr[j]>arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
                flag = 1；
            }
        }
        
        // 数组已经有序
        if(flag == 0)
        {
            break;
        }
        
    }  	
}
// 时间复杂度最差:O(N^2)  最好为O(N)    空间复杂度为O（1）