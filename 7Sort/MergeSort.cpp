// 归并排序：把数据分为两段，从两段中逐个选最小的元素移入新数据段的末尾。可从上到下或从下到上进行。

void sort1(int arr1[],int len1,int arr2[],int len2)
{
    int* pnew = new int[len1 + len2];
    
    int i = 0;
    int j = 0;
    int k = 0;
    while(i < len1 && j<len2)
    {
        if (arr1[i] <= arr2[j])
        {
            pnew[k] = arr1[i];
            i++;
            k++;
        }
        else
        {
            pnew[k] = arr2[j];
            j++;
            k++;
        }
    }
    
    while(i < len1)
    {
        pnew[k++] = arr1[i++];
    }
    
    while(j < len1)
    {
        pnew[k++] = arr1[j++];
    }
}

// 时间复杂度为O(NlogN)   空间复杂度为O（N）   稳定