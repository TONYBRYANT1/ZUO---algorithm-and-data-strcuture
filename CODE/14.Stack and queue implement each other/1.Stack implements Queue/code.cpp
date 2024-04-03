// 用栈实现队列

// 复杂度：每个数均摊下来是 O(1)的 
// 每个数最多 进一次 In Out
// 每个数最多 出一次 In Out

// 方法：用两个栈 in & out

// 要求：
// 1) out 空了再倒数据
// 2) 如果要倒数据 in 要倒完

#include<bits/stdc++.h>

using namespace std;

// 1) Out空 才能往里倒数据
// 2) 如果倒数据，In 必须倒完
void In_to_Out(stack<int>& In , stack<int>& Out)
{
    if(Out.empty())
    {
        while(!In.empty())
        {
            Out.push(In.top());
            In.pop();
        }
    }
}

// 先往 In 中放数据，再看能不能倒到 Out 中
void Push(stack<int>& In , stack<int>& Out , int x)
{
    In.push(x);
    In_to_Out(In , Out);
}

int Pop(stack<int>& In , stack<int>& Out)
{
    In_to_Out(In , Out);
    int a = Out.top();
    Out.pop();
    return a;
}

int Peek(stack<int>& In , stack<int>& Out)
{
    In_to_Out(In , Out);
    return Out.top();
}

bool In_Out_Empty(stack<int>& In , stack<int>& Out)
{
    return In.empty() && Out.empty();
}

int main()
{
    stack<int> In , Out;
    
    return 0;
}