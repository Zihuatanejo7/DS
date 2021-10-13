/*
选择排序思路：
1. 在未排序序列中找到最小（大）元素，存放到排序序列的起始位置
2. 从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾
3. 以此类推，直到所有元素均排序完毕
*/

// 选择排序
void sort1(int arr[],int len)
{
    for(int i = 0;i<len;i++)
    {
        int minPos = i;
        
        for (int j =i+1;j<len - 1;j++)     // 从i到N-1找到最小值的下标
        {
            if (arr[j] < arr[minPos])
            {
                minPos = j;
            }
        }
        swap(&arr[minPos],&arr[i]);
    }
}
