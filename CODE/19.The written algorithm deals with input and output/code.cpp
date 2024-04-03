// 全局变量 和 (全局 or not)静态变量 储存在相邻地址段，但静态变量会受作用域的影响(虽然是等到整个程序完成再被消灭)
#include<bits/stdc++.h>

using namespace std;

const int N = 5e4+10;
int arr[N] , help[N];

// 归并排序递归版
// 假设 l...r 一共 n 个数
// T(n) = 2 * T(n/2) + O(n)
// a = 2 , b = 2 , c = 1
// 根据 master 公式，时间复杂度O(n * log2(n)) 

void Merge(int l , int m , int r)
{
    int i=l;
    int a=l;
    int b=m+1;
    while(a<=m || b<=r)
    {
        help[i++] = arr[a]<=arr[b] ? arr[a++] : arr[b++];
    }

    // 当其中一端的数填完时，必有一个越界，一个不越界

    while(a<=m)
    {
        help[i++] = arr[a++];
    }
    while(b<=r)
    {
        help[i++] = arr[b++];
    }

    // 当 help 填满之后 更新 arr
}

void MergeSort1(int l , int r)
{
    if(l == r)
    {
        return;
    }
    else
    {
        int m = (l+r)/2;
        MergeSort1(l , m);
        MergeSort1(m+1 , r);
        Merge(l , m , r); // 段与段之间排序
    }
}

int main()
{
    int n;
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d" , &arr[i]);
    }
    
    MergeSort1(0 , n-1);

    for(int i=0 ; i<n ; i++)
    {
        printf("%d " , arr[i]);
    }

    return 0;
}