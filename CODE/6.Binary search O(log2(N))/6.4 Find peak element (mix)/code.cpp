#include<bits/stdc++.h>

using namespace std;

const int N = 1010;

int arr[N] , n;

int FindPeakElement()
{
    if(arr[0] > arr[1])
    {
        return 0;
    }
    if(arr[n-1] > arr[n-2])
    {
        return n-1;
    }

    int l=1 , r=n-2 , mid=0 , ans=-1;
    while(l<=r)
    {
        mid = l+(r-l)/2;
        if(arr[mid] > arr[mid+1] && arr[mid] > arr[mid-1])
        {
            return mid;
        }
        else if(arr[mid] > arr[mid-1])
        {
            l = mid+1;
        }
        else
        {
            r = mid-1;
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

    if(n>=2)
    {
        printf("%d" , FindPeakElement());
    }
    else
    {
        printf("%d" , arr[0]);
    }    
    return 0;
}