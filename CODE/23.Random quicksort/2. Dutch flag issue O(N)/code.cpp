#include<bits/stdc++.h>

using namespace std;

const int N = 5e4+10;
int arr[N] , n , x;

void swap(int& x , int& y)
{
    int temp = x;
    x = y;
    y = temp;
}

// 作用： 大于x           等于x         小于x
//      l...a-1         a...b        b+1...r
void DutchFlagIssue(int l , int r , int x , int& first , int& last)
{
    int a=l , b=r , i=l;
    while(i<=b)
    {
        if(arr[i]<x)
        {
            swap(arr[i] , arr[a]);
            a++ , i++;
        }
        else if(arr[i]>x)
        {
            swap(arr[i] , arr[b]);
            b--; // i 不++
            // 因为交换之后 arr[i] 的值还没有判断
        }
        else
        {
            i++;
        }
    }
    
    first = a , last = b;
}

int main()
{
    scanf("%d" , &n);
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d" , &arr[i]);
    }

    int first , last , x;
    scanf("%d" , &x);
    DutchFlagIssue(0 , n-1 , x , first , last);

    printf("first=%d last=%d\n" , first , last);
    for(int i=0 ; i<n ; i++)
    {
        printf("%d " , arr[i]);
    }

    return 0;
}