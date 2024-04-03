// 堆排序
#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+10;
int arr[N] , n , size=0;

void swap(int& x , int& y)
{
    int temp = x;
    x = y;
    y = temp;
}

void HeapInsert(int i)
{
    while(arr[i] > arr[(i-1)/2])
    {
        swap(arr[i] , arr[(i-1)/2]);
        i = (i-1)/2;
    }
}

void Heapify(int i)
{
    int l = (i<<1)+1; // 左孩子
    // 有左孩子
    while(l<=size-1)
    {
        int best = (l+1<=size-1)&&(arr[l+1] > arr[l]) ? l+1 : l;
        best = arr[best] > arr[i] ? best : i;
        if(best == i)
        {
            break;
        }
        else
        {
            swap(arr[i] , arr[best]);
            i = best;
            l = (i<<1)+1;
        }
    }
}

// 自上而下建立大根堆 Time Complexity：O(N * log2(N))
void HeapSort1()
{
    // 自上而下建立大根堆 
    // Time complexity：O(N * log2(N))
    // log2(1) + log2(2) + log2(3) + ... + log2(N-1) + log2(N) 收敛于 O(N * log2(N))
    for(int i=0 ; i<n ; i++)
    {
        HeapInsert(i);
    }

    // 将最大值放在最后，维护大根堆
    // Time complexity：O(N * log2(N))
    // log2(N-1) + log2(N-2) + log2(N-3) +...+ log2(1) + log2(0) 收敛于 O(N * log2(N))
    while(size)
    {
        swap(arr[0] , arr[size-1]);
        size--; // 隐藏最大值
        Heapify(0); // 维护大根堆
    }
}

// 自下而上建立大根堆 Time Complexity：O(N)
void HeapSort2()
{
    // 自下而上建立大根堆
    for(int i=n-1 ; i>=0 ; i--)
    {
        Heapify(0);
    }

    // 将最大值放在最后，维护大根堆
    // Time complexity：O(N * log2(N))
    // log2(N-1) + log2(N-2) + log2(N-3) +...+ log2(1) + log2(0) 收敛于 O(N * log2(N))
    while(size)
    {
        swap(arr[0] , arr[size-1]);
        size--; // 隐藏最大值
        Heapify(0); // 维护大根堆
    }
}

int main()
{
    scanf("%d" , &n);
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d" , &arr[i]);
        size++;
    }

    HeapSort2();

    for(int i=0 ; i<n ; i++)
    {
        printf("%d " , arr[i]);
    }
    return 0;
}