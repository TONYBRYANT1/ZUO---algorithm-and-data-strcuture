// Basic Calculator

#include<bits/stdc++.h>
using namespace std;

class Calculator
{
private:
    string str;
    int where;

private:
    int compute(const vector<int>& number , const vector<char>& oper)
    {
        int n = number.size();
        int ans = number[0];

        for(int i=1 ; i<n ; i++)
        {
            ans += oper[i-1] == '+' ? number[i] : -number[i];
        }

        return ans;
    }

    void push(vector<int>& number , vector<char>& oper , const int& cur , const char& op)
    {
        // 放入数字时肯定有一个对应的操作也被放入
        // 如果 是第一个数 or 前面只是 '+' or '-' 则直接放入容器
        int n = oper.size();
        if((n==0) || (oper[n-1] == '+') || (oper[n-1] == '-'))
        {
            number.push_back(cur);
            oper.push_back(op);
        } 
        // 如果 放入的数前面有 '*' or '/'，要先将 数字与上一个数字做运算，再放入容器
        else
        {
            int top_number = number[n-1];
            int top_oper = oper[n-1];

            if(top_oper == '*')
            {
                number[n-1] = top_number * cur;
            }
            else
            {
                number[n-1] = top_number / cur;
            }

            oper[n-1] = op;
        }  

        return;
    }

    // 计算(i...) 这一段，直到遇到 ')' 停止
    // 返回自己负责的这一段的结果
    // 返回之前更新 where，让上游函数直到从哪里继续
    int f(int i)
    {
        // tool:
        int cur = 0;
        vector<int> number;
        vector<char> oper;

        // upgrade:
        number.clear();
        oper.clear();

        // traversal:
        // 当遇到 ')' or 字符串遍历完 停止
        while((str[i]!=')') && (i < str.length()))
        {
            // 会遇到四种情况：1.数字 2.运算符 3.'(' 
            //
            // 1.数字：等遇到操作符时再将数字放入容器
            if((str[i] >= '0') && (str[i] <= '9'))
            {
                cur = cur*10 + (str[i] - '0');
                i++;
            }
            // 2.运算符：
            else if(str[i] != '(')
            {
                // 将 number 和 operation 放入容器
                push(number , oper , cur , str[i]);
                i++;
                cur=0;
            }
            // 3.'('
            else
            {
                cur = f(i+1);
                i = where+1;
            }
        

        }            
        // 最后一个数：
        push(number , oper , cur , '+');
        where = i;
        return compute(number , oper);
    }

public:
    int calculate(const string& expression)
    {
        str.clear();
        str = expression;
        where = 0;
        // 从下标 0 开始：
        return f(0);
    }

};

int main()
{
    Calculator cl;
    string expression = "2*(5+5*2)/3+(6/2+8)";
    cout << "Result : " << cl.calculate(expression) << endl;
    return 0;
}