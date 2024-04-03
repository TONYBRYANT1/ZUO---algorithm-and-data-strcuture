#include<bits/stdc++.h>

using namespace std;

class Stack_Reversor
{
private:
    stack<int> stk;
private:
    // 函数功能，去掉并返回栈低元素    O(N)
    // ans 存当前栈顶
    // last 存栈低元素 ---> 一直向上层传递
    int bottom_out()
    {
        // 呈上：
        // 作用：获得当前顶端数据，直到栈低数据
        int ans = stk.top(); 
        stk.pop();

        // 主体
        if(stk.empty())
        {
            // 当栈空了，说明此时的 ans 存的是栈底元素，要将栈底元素返回上一层
            return ans;
        }
        else
        {            
            // 得到下层传给上层的数据：last(栈低数据)，并上传上一层
            int last = bottom_out();
            
            // 栈还不为空，ans需要重新压栈：
            stk.push(ans);

            return last;
        }
    }

    // O(N*N)
    void f()
    {
        // 呈上：
        if(stk.empty())
        {
            return;
        }

        // 主体：
        int num = bottom_out();
        f();
        stk.push(num);

        return;
    }

public:     
    stack<int> stack_reverse(stack<int> stkkk)
    {
        stack<int> rabbishbin;
        stk.swap(rabbishbin);
        stk = stkkk;
        f();
        return stk;
    }
};

int main()
{
    stack<int> stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.push(5);

    Stack_Reversor sr;
    stack<int> stkkk = sr.stack_reverse(stk);

    while(!stkkk.empty())
    {
        cout << stkkk.top() << endl;
        stkkk.pop();
    }
    return 0;
}