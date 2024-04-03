#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 5e4+10;
int arr[N] , help[N] , n;

LL Merge(int l , int m , int r)
{
    // 求左跨右答案
    int i=l , j=m+1;
    LL sum=0 , ans=0;
    for( ; i<=m ; i++)
    {
        while(j<=r && (LL)arr[i] > (LL)(arr[j]<<1))
        {
            sum+=1;
            j++;
        }
        ans+=sum;
    }

    // 左段有序 右端有序 ---> 使整体有序

    int a=l , b=m+1 , p=l;
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

LL ReversePair(int l , int r)
{
    if(l==r)
    {
        return 0;
    }
    else
    {
        int m = (l+r)/2;
        return ReversePair(l , m) + ReversePair(m+1 , r) + Merge(l , m , r);
    }
}

int main()
{
    scanf("%d" , &n);
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d" , &arr[i]);
    }

    cout << ReversePair(0 , n-1) << endl;

    return 0;
}