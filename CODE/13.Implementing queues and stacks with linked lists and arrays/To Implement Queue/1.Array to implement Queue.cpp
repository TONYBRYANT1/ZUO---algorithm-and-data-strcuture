// 当算法题目中说明了总共有多少数据 N 入队时可以用 arr 实现队列
#include<bits/stdc++.h>

using namespace std;

const int N = 1e3+10;

int Queue[N] , l=0 , r=0;

// 判空
bool IsEmpty()
{
    if(l==r)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 尾加
void offer(int num)
{
    Queue[r++] = num;
}

// 头取
int Poll()
{
    return Queue[l++];
}

// 头看
int Head()
{
    return Queue[l];
}

// 尾看
int Tail()
{
    return Queue[--r];
}

int size()
{
    return r-l;
}

int main()
{
    return 0;
}