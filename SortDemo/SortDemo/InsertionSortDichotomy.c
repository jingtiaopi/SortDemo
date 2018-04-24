//
//  InsertionSortDichotomy.c
//  SortDemo
//
//  Created by TP on 2018/4/23.
//  Copyright © 2018年 TP. All rights reserved.
//

#include <stdio.h>

/*
 对于插入排序，如果比较操作的代价比交换操作大的话，可以采用二分查找法来减少比较操作的次数，我们称为二分插入排序
 */


// 分类 -------------- 内部比较排序
// 数据结构 ---------- 数组
// 最差时间复杂度 ---- O(n^2)
// 最优时间复杂度 ---- O(nlogn)
// 平均时间复杂度 ---- O(n^2)
// 所需辅助空间 ------ O(1)
// 稳定性 ------------ 稳定

void InsertionSortDichotomy(int A[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int get = A[i];                    // 右手抓到一张扑克牌
        int left = 0;                    // 拿在左手上的牌总是排序好的，所以可以用二分法
        int right = i - 1;                // 手牌左右边界进行初始化
        while (left <= right)            // 采用二分法定位新牌的位置
        {
            int mid = (left + right) / 2;
            if (A[mid] > get)
                right = mid - 1;
            else
                left = mid + 1;
        }
        for (int j = i - 1; j >= left; j--)    // 将欲插入新牌位置右边的牌整体向右移动一个单位
        {
            A[j + 1] = A[j];
        }
        A[left] = get;                    // 将抓到的牌插入手牌
    }
}


int main()
{
    int A[] = { 5, 2, 9, 4, 7, 6, 1, 3, 8 };// 从小到大二分插入排序
    int n = sizeof(A) / sizeof(int);
    InsertionSortDichotomy(A, n);
    printf("二分插入排序结果：");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}
