// 计算数组的小和
// 总答案 = 左答案 + 右答案 + 左跨右答案

#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
const int N = 1e5+10;
int arr[N] , help[N] , n; // arr[j]*2 会出现溢出

// 跨左右产生的累加和，左侧有序，右侧有序，让左右整体有序
// arr[l...m] arr[m+1...r]
LL Merge(int l , int m , int r)
{
    // 统计部分
    // 4 6 7 7     5 6 6 8
    //   i         j

    // 4 6 7 7     5 6 6 8
    //     i         j

    // 4 6 7 7     5 6 6 8
    //     i           j

    // 4 6 7 7     5 6 6 8
    //         i         j

    // i的左侧小于等于当前数字
    LL ans=0 , sum=0;
    int i=l , j=m+1;
    for( ; j<=r ; j++)
    {
        while(i<=m && arr[i]<=arr[j])
        {
            sum+=arr[i++];
        }
        ans+=sum;
    }
    
    // 正常merge
    int p=l , a=l , b=m+1;
    while(a<=m && b<=r)
    {
        help[p++] = arr[a]<=arr[b] ? arr[a++] : arr[b++];
    }

    while(a<=m)
    {
        help[p++] = arr[a++];
    }

    while(b<=r)
    {
        help[p++] = arr[b++];
    }

    for(int i=l ; i<=r ; i++)
    {
        arr[i] = help[i];
    }

    return ans;
}

// 返回 arr[l...r]范围上，小和的累加和，同时请把arr[l...r]变有序
LL SmallSum(int l , int r)
{
    if(l==r)
    {
        return 0;
    }
    else
    {
        int m = (l+r)/2;
        return SmallSum(l , m) + SmallSum(m+1 , r) + Merge(l , m , r);
    }
}

int main()
{
    scanf("%d" , &n);
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d" , &arr[i]);
    }

    cout << SmallSum(0 , n-1) << endl;

    return 0;
}