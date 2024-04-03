// 最小栈

// 随时可以查看当前栈中的最小元素

// 做法：
// 1) 有两栈 1.stk 2.minn
// 2) 两栈同时 push 同时 pop
// 3) 对于 minn : 当 push 的数 x   >   当前 minn 的 top 值
//    push 与 top 值相同的值
// 4) 对于 minn : 当 push 的数 x   <=   当前 minn 的 top 值
//    push x

#include<bits/stdc++.h>

using namespace std;

const int N = 3e4+10;

int stk[N] , minn[N];
int l=0 , r=0;

void Push(int x)
{
    stk[r++] = x;

    r--;

    if((r-l)==0 || x <= minn[r-1])
    {
        minn[r++] = x;
    }
    else
    {
        minn[r++] = minn[r-1];
    }
}

int Pop()
{
    int a = stk[r-1];
    r--;
    return a;
}

int top()
{
    return stk[r-1];
}

int Getmin()
{
    return minn[r-1];
}

int main()
{
    return 0;
}