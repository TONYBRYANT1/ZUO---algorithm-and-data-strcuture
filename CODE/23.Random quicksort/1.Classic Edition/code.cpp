#include<bits/stdc++.h>

using namespace std;

const int N = 5e4+10;
int arr[N] , n;

void swap(int& x , int& y)
{
    int temp = x;
    x = y;
    y = temp;
}

// l...a-1(小于等于x) ~ a...r(大于x)
// 缺点：只能将一个等于x的值放在 a-1 上
// 要想将所有的 x 的元素放在一块，用荷兰国旗问题来解决
int Partition1(int l , int r , int x)
{
    // a为城墙 l...a-1 段的数小于等于x
    // idx 记录与 x 相等的下标，方便将 x 放在 l...a-1 的最后一位
    int a=l , idx=0;

    // i为寻探，遍历当前数段，方便将小于等于x的数放在 a墙左边
    // (关键) 当 arr[i]<=x：swap(arr[i] , arr[a]) ，a++ ，i++
    for(int i=l ; i<=r ; i++)
    {
        if(arr[i]<=x)
        {
            swap(arr[i] , arr[a]);
            if(arr[a] == x)
            {
                idx = a;
            }

            a++;
        }
        else
        {
            // i++
        }
    }

    swap(arr[idx] , arr[a-1]);
    return a-1;
}

//DutchFlagIssue
void Partition2(int l , int r , int x , int& first , int& last)
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

void RandomQuickSort1(int l , int r)
{
    // l==r 无需排序
    // l >r 没有此数段
    if(l>=r)
    {
        return;
    }

    else
    {
        // 随机找一个值，将这个值定位，在将两端分别定位
        int x = arr[l + rand()%(r-l+1)];
        // 将已经定位的值的地址传出
        int mid = Partition1(l , r , x);
        // 继续定位左段
        RandomQuickSort1(l , mid-1);
        // 继续定位右段
        RandomQuickSort1(mid+1 , r);
    }
}

void RandomQuickSort2(int l , int r)
{
    // l==r 无需排序
    // l >r 没有此数段
    if(l>=r)
    {
        return;
    }

    else
    {
        // 随机找一个值，将这个值定位，在将两端分别定位
        int x = arr[l + rand()%(r-l+1)];
        // 如果用全局变量的 first 和 last 小心底层循环改变 first 和 last 的值
        int first , last;
        // 将已经定位的值的地址传出
        Partition2(l , r , x , first , last);
        // 继续定位左段
        RandomQuickSort2(l , first-1);
        // 继续定位右段
        RandomQuickSort2(last+1 , r);
    }
}

int main()
{
    srand((unsigned)time(NULL));
    scanf("%d" , &n);
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d" , &arr[i]);
    }

    RandomQuickSort2(0 , n-1);

    for(int i=0 ; i<n ; i++)
    {
        printf("%d " , arr[i]);
    }

    return 0;
}