// 希尔排序：每一轮按照事先决定的间隔进行插入排序，间隔会依次缩小

void sort1(int arr[],int len)
{
    //  缩小间隔
    for (gap = len/2;gap > 0; gap = gap /2)
    {
        for (int i = gap;i<len;i++)
        {
            int temp = arr[i+1];
            for (int j = gap;j>gap&&temp<arr[j-gap];j = j-gap)
            {
                arr[j] = arr[j - gap];
            }
            
            arr[j] = temp;
        }
    }
}

// 时间复杂度为O(N的1.3次幂)   空间复杂度为O(1)  