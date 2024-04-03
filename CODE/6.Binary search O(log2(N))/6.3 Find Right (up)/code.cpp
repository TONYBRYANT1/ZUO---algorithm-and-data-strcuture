// Find Right 找 <=x 最右边的值

#include<bits/stdc++.h>

using namespace std;

const int N = 1e4+10;

int arr[N] , n , x;

bool FindRight(int& index)
{
    int l=0 , r=n-1 , mid=0;
    while(l<=r)
    {
        mid = l + (r-l)/2;
        if(arr[mid] <= x)
        {
            index = mid;
            l = mid+1;
        }
        else
        {
            r = mid-1;
        }
    }
    if(arr[index] <= x)
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

    if(!FindRight(index))
    {
        printf("没找到 <=x 的最右位置");
    }
    else
    {
        printf("找到了 <=x 的最右位置，值为%d，下标为%d" , arr[index] , index);
    }
    return 0;
}