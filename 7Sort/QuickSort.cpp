/*
在区间中随机挑选一个元素作基准，将小于基准的元素放在基准之前，大于基准的元素放在基准之后，再分别对小数区与大数区进行排序。

快速排序思路：
1. 选取第一个数为基准
2. 将比基准小的数交换到前面，比基准大的数交换到后面
3. 对左右区间重复第二步，直到各区间只有一个数
*/

// 快速排序（递归）
void sort1(int arr[],int left,int right)
{
    if (left > right)
        return ;
    
    int i= left;
    int j = right;
    
    while (i != j)
    {
        int pivot = arr[j];
        
        while (i < j && arr[i]<=pivot)
        {
            i++;
        }
        
        while (i < j && arr[j] > pivot)
        {
            j--;
        }
        
        if (i < j)
        {
            swap(&arr[i],&arr[j]);
        }
    }
    
    arr[i] = pivot;
    
    sort(arr,left,i-1;);
    sort(arr,i+1,right);
}

