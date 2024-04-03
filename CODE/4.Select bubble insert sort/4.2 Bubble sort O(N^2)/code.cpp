// Bubble_sort
// 经过一次次的排序 让最大值依次出现在数组末端

#include<bits/stdc++.h>

using namespace std;

const int N = 1e4+10;

int n , arr[N];

void swap(int i , int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void bubble_sort()
{
    for(int time=n-1 ; time>0 ; time--)
    {
        for(int i=0 ; i<time ; i++)
        {
            if(arr[i] > arr[i+1])
            {
                swap(i , i+1);
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

    if(n>=2)
    {
        bubble_sort();
    }

    for(int i=0 ; i<n ; i++)
    {
        printf("%d " , arr[i]);
    }

    return 0;
}