#include<bits/stdc++.h>

using namespace std;

const int N = 3e4+10;
int arr[N] , help[N] , n;

void RigionSort(int l , int m , int r)
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

// Time complexity : O(n*log2(n))
// for() -> logn
// while() -> n

void MergeSort(int l , int r)
{
    // 步伐 1 2 4 8 16
    for(int step=1 ; step<n ; step <<= 1) // 当步伐达到 一步多~两步 时 就可以排好整个数组
    {
        // 初始化 l=0;
        l=0;
        while(l<n) // l<n 保证了一定会有左段，但是不一定有右段
        {
            int m = step+l-1; // m - l + 1  = step
            if(m+1>n-1) // 没有右段 终止本次循环
            {
                break;
            }
            else
            {
                r = m + step; // r - m - 1 + 1 = step
                r = min(r , n-1);
                RigionSort(l , m , r);
                l = r+1;
            }
        }
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
        printf("%d" , arr[i]);
    }
    return 0;
}