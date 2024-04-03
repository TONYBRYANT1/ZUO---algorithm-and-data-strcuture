// 归并排序递归版
// 假设 l...r 上一共 n 个数

// master公式
// T(N) = 2*T(N/2) + O(N)
// a=2 , b=2 , c=1
// logb(a) == c
// time complexity : O(N * log2(N))
// space complexity : O(N) --- 辅助数组 help[N]

#include<bits/stdc++.h>

using namespace std;

const int N = 5e4+10;
int arr[N] , help[N] , n;

// time complexity : O(N)
void RegionSort(int l , int m , int r)
{
    int i=l;
    int a=l;
    int b=m+1;
    while(a<=m && b<=r)
    {
        help[i++] = arr[a]<=arr[b] ? arr[a++] : arr[b++];
    }

    while(a<=m)
    {
        help[i++] = arr[a++];
    }
    while(b<=r)
    {
        help[i++] = arr[b++];
    }

    for(int i=l ; i<=r ; i++)
    {
        arr[i] = help[i];
    }
}

void MergeSort(int l , int r)
{   
    // base case
    if(l==r)
    {
        // return arr[l];
        return;
    }
    // normal case
    else
    {
        int m = (l+r)/2;
        MergeSort(l , m);
        MergeSort(m+1 , r);
        // 排列确定区域的元素
        RegionSort(l , m , r);
        return;
    }
}

int main()
{   
    scanf("%d" , &n);
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d" , &arr[i]);
    }

    MergeSort(0 , n-1);

    for(int i=0 ; i<n ; i++)
    {
        printf("%d " , arr[i]);
    }

    return 0;
}