// 用队列实现栈
#include<bits/stdc++.h>

using namespace std;

int Pop(queue<int>& que)
{
    int a = que.front();
    que.pop();
    return a;
}

int top(queue<int>& que)
{
    return que.front();
}

bool IsEmpty(queue<int>& que)
{
    return que.empty();
}

// 每加一个数，先把数push，然后将(头元素从头出从尾进) 运行 n次
void push(queue<int>& que , int x)
{
    int n = que.size();
    que.push(x);
    
    //从头弹出 从尾巴进入 运行 n 次
    while(n--)
    {
        int a = que.front();
        que.pop();
        que.push(a);
    }
}

int mian()
{
    queue<int> que;
    return 0;
}