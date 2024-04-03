#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

class Stack_Sortor
{
private:
    stack<int> stk;

private:   
    // 函数功能：
    // 不改变数据，返回栈的深度
    int stk_deep()
    {
        if(stk.empty())
        {
            return 0;
        }

        int num = stk.top();
        stk.pop();
        int deep = stk_deep()+1;
        stk.push(num);
        return deep;
    }

    // 函数功能：
    // 已经知道栈有 deep 层
    // 从栈顶开始，往下数 deep 层，返回 deep 层里的最大值：
    int stk_maxx(int deep)
    {
        if(deep==0)
        {
            return INT_MIN;
        }

        int num = stk.top();
        stk.pop();
        int rest_maxx = stk_maxx(deep-1);
        int maxx = max(rest_maxx , num);
        stk.push(num);

        return maxx;
    }

    // 函数功能：
    // 已经知道栈有 deep 层，最大值 maxx
    // 从栈顶往下 deep 层，返回 maxx 出现的次数
    int stk_times(int deep , int maxx)
    {
        if(deep == 0)
        {
            return 0;
        }

        int num = stk.top();
        stk.pop();
        int rest_times = stk_times(deep-1 , maxx);
        int times = rest_times + (num==maxx ? 1 : 0);
        stk.push(num);

        return times; 
    }

    // 函数功能：
    // 已经知道栈有 deep 层，最大值 maxx，出现了 times 次
    // 将 所有值为 maxx 的数据 沉底
    void stk_down(int deep , int maxx , int times)
    {
        // 直接将 tiems 个 maxx 压栈
        if(deep == 0)
        {
            for(int i=0 ; i<times ; i++)
            {
                stk.push(maxx);
                return;
            }
        }

        int num = stk.top();
        stk.pop();
        stk_down(deep-1 , maxx , times);
        if(num != maxx)
        {
            stk.push(num);
        }

        return;
    }

public:
    stack<int> sort_stack(stack<int> origin)
    {
        stk = origin;
        int deep = stk_deep();
        while(deep > 0)
        {
            int maxx = stk_maxx(deep);
            int times = stk_times(deep , maxx);
            stk_down(deep , maxx , times);
            deep -= times;
        }

        return stk;
    }
};

int main()
{
    stack<int> stk;
    stk.push(5);
    stk.push(7);
    stk.push(1);
    stk.push(0);
    stk.push(2);
    stk.push(3);
    stk.push(6);
    stk.push(4);

    Stack_Sortor ss;
    stk = ss.sort_stack(stk);

    while(!stk.empty())
    {
        cout << stk.top() << endl;
        stk.pop();
    }

    return 0;
}