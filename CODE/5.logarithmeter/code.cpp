#include<bits/stdc++.h>

using namespace std;

const int N = 100;
const int V = 1000;
const int TestTime = 50000;

int arr0[N] , arr1[N] , arr2[N] , arr3[3];

void RandomArr0(int n , int v)
{
    for(int i=0 ; i<n ; i++)
    {
        arr0[i] = rand()%v+1;
    }
}

void InitializeArr(int arr[] , int n)
{
    for(int i=0 ; i<n ; i++)
    {
        arr[i] = arr0[i];
    }
}

void Swap(int i , int j , int arr[])
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void SelectSort(int arr[] , int n)
{
    for(int i=0 ; i<n ; i++)
    {
        int minindex = i;
        for(int j=i ; j<n ; j++)
        {
            if(arr[j] < arr[minindex])
            {
                minindex = j;
            }
        }
        Swap(i , minindex , arr);
    }
}

void BubbleSort(int arr[] , int n)
{
    for(int i=n-1 ; i>0 ; i--)
    {
        for(int j=0 ; j<i ; j++)
        {
            if(arr[j] > arr[j+1])
            {
                Swap(j , j+1 , arr);
            }
        }
    }
}

void InsertSort(int arr[] , int n)
{
    for(int i=0 ; i<n ; i++)
    {
        for(int j=i-1 ; j>=0 ; j--)
        {
            if(arr[j+1] < arr[j])
            {
                Swap(j , j+1 , arr);
            }
        }
    }
}

void PrintArr(int arr[] , int n)
{
    for(int i=0 ; i<n ; i++)
    {
        printf("%d " , arr[i]);
    }
    printf("\n");
}

bool SameArr(int arr1[] , int arr2[] , int n)
{
    for(int i=0 ; i<n ; i++)
    {
        if(arr1[i] != arr2[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    printf("测试开始\n");

    srand(time(0));
    for(int i=0 ; i<TestTime ; i++)
    {
        int n = rand()%N+1; // n[1 , 100]
        RandomArr0(n , V);  
        InitializeArr(arr1 , n);
        InitializeArr(arr2 , n);
        InitializeArr(arr3 , n);
        SelectSort(arr1 , n);
        BubbleSort(arr2 , n);
        InsertSort(arr3 , n);
        if(!SameArr(arr1 , arr2 , n) || !SameArr(arr1 , arr3 , n) || !SameArr(arr2 , arr3 , n))
        {
            printf("出错了");
        }
        // 当有错了
        // 打印是什么例子，出错的
        // 打印三个功能，各自排序成什么样了
        // 可能要把例子带入，每个方法，去debug!
    }

    printf("测试结束");
    return 0;
}