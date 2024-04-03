#include<bits/stdc++.h>

using namespace std;

static int arr[] = {3 , 4 , 1 , 2 , 9 , 10 , 5 , 0};

static int n=8;

int f(int arr[] , int l , int r)
{
    if(l==r)
    {
        return arr[l];
    }
    else
    {
        int m = (l+r)/2;
        int lmax = f(arr , 0 , m);
        int rmax = f(arr , m+1 , r);
        return max(lmax , rmax);
    }
}

int MaxValue()
{
    return f(arr , 0 , 8);
}

int main()
{
    printf("%d" , MaxValue());
    return 0;
}

// 如何分析？
// 1) 画流程图 递归决策图
// 2) 系统栈(非内存，空间比内存开的小，比较贵，独立区域) 一旦函数需要求一些下一层递归的结果，就会在栈中保存当前状态(所有状态，所有中间变量)
//
// master公式
// T(N) = 2 * T(N/2) + O(1)