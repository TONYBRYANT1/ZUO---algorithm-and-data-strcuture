// 每放一张牌在手上 就和这张牌和前面一张牌 比大小
#include<bits/stdc++.h>

const int N = 1e4+10;

int arr[N] , n;

void swap(int i , int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void insert_sort()
{
    for(int i=0 ; i<n ; i++) // 插入第 i 张牌
    {
        for(int j=i-1 ; j>=0 ; j--) // j=i-1 , j+1  当arr[j+1] < arr[j] 那么就换牌
        {
            if(arr[j+1] < arr[j])
            {
                swap(j , j+1);
            }
        }
    }
}

using namespace std;

int main()
{
    scanf("%d" , &n);
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d" , &arr[i]);
    }

    if(n>=2)
    {
        insert_sort();
    }

    for(int i=0 ; i<n ; i++)
    {
        printf("%d " , arr[i]);
    }
    return 0;
}