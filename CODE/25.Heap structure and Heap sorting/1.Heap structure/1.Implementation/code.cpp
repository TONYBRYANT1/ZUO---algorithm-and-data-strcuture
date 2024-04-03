// 维持大根堆
#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+10;
int arr[N] , size , n;

void swap(int& x , int& y)
{
    int temp = x;
    x = y;
    y = temp;
}

// 往上看
//                左
//          左           右
//                   左      i
// 两种情况：
// 1）堆区填入新数：因为下面没有子结点，所以只考虑当前的数是否影响了父结点
// 2）改变原有的数 且 原数据变大：子结点仍然斗不过当前结点，但当前结点可能影响其父节点
void HeapInsert(int i)
{
    while(arr[i] > arr[(i-1)/2])
    {
        swap(arr[i] , arr[(i-1)/2]);
        i = (i-1)/2;
    }
}

// 往下看
//                 i
//          左            右
//      左      右     左     右 
// 一种情况：
// 1）改变原有的数 且 原数据变小：当前结点仍然斗不过其父节点，其子节点可能比当前结点强
void Heapify(int i)
{
    // 有没有左孩子？
    int l = (i<<1)+1; // 优先级 '+' > '<<'
    // 有左孩子
    while(l<size)
    {
        // 有没有右孩子？左孩子和右孩子之中谁最强？
        //
        //                       
        //          -- 有右孩子 --- best = arr[l]>arr[l+1] ? l : l+1
        //         -             
        // 有左孩子
        //         - 
        //          -- 没右孩子 --- best = l

        int best=0;
        // 有右孩子 
        if(l+1<size)
        {
            best = arr[l]>arr[l+1] ? l : l+1;
        }
        else
        {
            best = l;
        }
        // 合二为一：best = (l+1<size)&&(arr[l+1]>arr[l]) ? l+1 : l;

        // 找到了 子孩子 的孩子王
        // 看看能不能干过孩子王
        best = arr[best]>arr[i] ? best : i;

        // 孩子王干不过当前结点
        if(best == i)
        {
            break;
        }
        // 孩子王比当前结点强
        else
        {
            swap(arr[i] , arr[best]);
            // 当前节点更换之后，将结点换到下一层
            i = best;
            // 如此往复
            l = (i<<1)+1;
        }
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

    for(int i=0 ; i<7 ; i++)
    {
        printf("%d " , arr[i]);
    }
    cout << endl;

    for(int i=0 ; i<n ; i++)
    {
        HeapInsert(i);
    }

    for(int i=0 ; i<7 ; i++)
    {
        printf("%d " , arr[i]);
    }
    cout << endl;


    return 0;
}