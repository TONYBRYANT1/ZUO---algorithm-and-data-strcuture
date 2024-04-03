// Select sort
// 在 i ~ n-1 范围上找最小 放在 i 上 i++ 缩小范围
#include<bits/stdc++.h>

using namespace std;

const int N = 1e4+10;

int arr[N] , n;

void swap(int i , int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void select_sort()
{
    for(int i=0 ; i<n ; i++)
    {
        int minindex = i; // i ~ n-1 上最小值的位置
        for(int j=i+1 ; j<n ; j++)
        {
            if(arr[j] < arr[minindex])
            {
                minindex = j;
            }
        }
        swap(i , minindex);
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
        select_sort();
    }
    
    for(int i=0 ; i<n ; i++)
    {
        printf("%d " , arr[i]);
    }
    return 0;
}