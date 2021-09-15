#define _CRT_SECURE_NO_WARNINGS 1

# include <stdio.h>
# include <string.h>

int F[30];

// 顺序查找：随便
int Search1(int *ps, int len,int target)
{
	assert(ps != NULL);
	int i = 0;

	while (i < len)
	{
		if (ps[i] == target)
		{
			return i;
		}
		i++;
	}
	return 0;
}

// 折半查找：表中数据有序
int Search2(int* ps, int len, int target)
{
	int low = 0;
	int high = len - 1;

	while (low <= high)
	{
		int mid = (low + high) / 2;

		if (ps[mid] < target)
		{
			low = mid + 1;
		}
		else if (ps[mid] > target)
		{
			high = low - 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

// 插值查找：表中数据有序，且数据增加或者减少线性
int Search3(int* ps, int len, int target)
{
	int low = 0;
	int high = len - 1;

	while (low <= high)
	{
		int mid = low + (high - low) * (target - ps[low]) / (ps[high] - ps[low]);
		if (target > ps[mid])
		{
			low = mid + 1;
		}
		else if (target < ps[mid])
		{
			high = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	
	return -1;
}

int main(void)
{
	int target = 73;
	int arr[] = { 0,1,16,24,25,35,47,59,62,73,88,99,99};
	int len = sizeof(arr) / sizeof(arr[0]);

	// 顺序查找
	int ret1 = Search1(arr, len, target);
	printf("%d   ", ret1);

	// 折半查找
	int ret2 = Search2(arr, len, target);
	printf("%d   ", ret2);

	// 插值查找
	int ret3 = Search3(arr, len, target);
	printf("%d   ", ret3);

	return 0;
}


