// Find number

#include<bits/stdc++.h>

using namespace std;

const int N = 1e4+10;

int arr[N] , n , k;

bool FindNum(int& index)
{
    int l=0 , r=n-1 , mid=0;
    while(l<=r)
    {
        mid = (l+r)>>1;
        if(arr[mid] == k)
        {
            index = mid;
            return true;
        }
        else if(arr[mid] > k)
        {
            r = mid-1;
        }
        else
        {
            l = mid+1;
        }
    }
    return false;
}

int main()
{
    int index;
    scanf("%d%d" , &n , &k);
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d" , &arr[i]);
    }

    if(!FindNum(index))
    {
        printf("没找到");
    }
    else
    {
        printf("找到了，下标为：%d" , index);
    }

    return 0;
}