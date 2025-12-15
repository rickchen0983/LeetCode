#include "MergeSortedArray.h"
#include "../../ListLib/List.h"
#include <stdlib.h>
#include <stdio.h>

void merge(int *nums1, int m, int *nums2, int n);

void MergeSortedArray_Main(void)
{
    int array1[6] = {1, 2, 3, 0, 0, 0};
    int dataLength1 = sizeof(array1) / sizeof(array1[0]);
    int *ptrArray1 = array1;
    int array2[3] = {2, 5, 6};
    int dataLength2 = sizeof(array2) / sizeof(array2[0]);
    int *ptrArray2 = array2;
    merge(ptrArray1, 3, ptrArray2, 3);
    for (int i = 0; i < dataLength1; i++)
    {
        printf("%d ", array1[i]);
    }
}

void merge(int *nums1, int m, int *nums2, int n)
{
    int i = m - 1;     // nums1 有效元素的最後一個
    int j = n - 1;     // nums2 的最後一個
    int k = m + n - 1; // nums1 總長度的最後一個

    // 從後面開始合併
    while (i >= 0 && j >= 0)
    {
        if (nums1[i] > nums2[j])
        {
            nums1[k] = nums1[i];
            i--;
        }
        else
        {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    // 如果 nums2 還有剩，直接補到 nums1 前面
    while (j >= 0)
    {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}
