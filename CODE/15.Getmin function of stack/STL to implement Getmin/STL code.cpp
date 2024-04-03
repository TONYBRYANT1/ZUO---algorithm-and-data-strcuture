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

stack<int> stk , minn;

int Pop()
{
    int a = stk.top();
    stk.pop();
    minn.pop();
    return a;
}

void push(int x)
{
    stk.push(x);

    if(minn.empty() || x <= minn.top())
    {
        minn.push(x);
    }
    else
    {
        minn.push(minn.top());
    }
}

int top()
{
    return stk.top();
}

int Getmin()
{
    return minn.top();
}

int main()
{
    
    return 0;
}