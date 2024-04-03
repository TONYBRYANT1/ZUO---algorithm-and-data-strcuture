// Find left 找大于等 x 的最小值

#include<bits/stdc++.h>

using namespace std;

const int N = 1e4+10;

int arr[N] , n , x;

bool FindLeft(int& index)
{
    int l=0 , r=n-1 , mid=0;
    while(l<=r) 
    {
        //mid = (l+r) >> 1;
        mid = l + (r-l)/2;// 因为 l , r 的单位是 int，l+r 可能会爆
        if(arr[mid] >= x)
        {
            index = mid;
            r = mid-1;
        }
        else
        {
            l = mid+1;
        }
    }
    if(arr[index] >= x)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int index;
    scanf("%d%d" , &n , &x);
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d" , &arr[i]);
    }

    if(!FindLeft(index))
    {
        printf("未找到>=x的最右位置");
    }
    else
    {
        printf("找到了>=x的最右位置，值为%d，下标为%d" , arr[index] , index);
    }
    return 0;
}

