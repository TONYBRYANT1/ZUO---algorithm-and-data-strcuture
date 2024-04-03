// CircularQueue 关键在与边界处理
// 同时在队列中的数不超过 N
#include<bits/stdc++.h>

using namespace std;

const int N = 5;
int Queue[N] , l=0 , r=0 , size=0 , Limit=N;

bool IsFull()
{
    return size == Limit;
}

bool IsEmpty()
{
    return size == 0;
}

// 满了不能加
// 边界处理
bool Offer(int x)
{
    if(IsFull())
    {
        return false;
    }
    else
    {
        Queue[r] = x;
        r = r==(Limit-1) ? 0 : (r+1);
        size++;
        return true;  
    }
}

bool Pop()
{
    if(IsEmpty())
    {
        return false;
    }
    else
    {
        l = l==(Limit-1) ? 0 : (l+1);
        size--;
        return true;
    }
}

int Front()
{
    if(IsEmpty())
    {
        return -1;
    }
    else
    {
        return Queue[l];
    }
}

int Rear()
{
    if(IsEmpty())
    {
        return -1;
    }
    else
    {
        int last = r==0 ? (Limit-1) : r-1;
        return Queue[last];
    }
}

int main()
{
    return 0;
}