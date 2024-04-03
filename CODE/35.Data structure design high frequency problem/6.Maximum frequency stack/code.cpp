#include<bits/stdc++.h>

using namespace std;

class FreqStack 
{
public:
    // 统计词频表 Word Frequency Table
    unordered_map<int , int> Wft;
    // 栈+链表结构
    unordered_map<int , vector<int>> Stk;
    // 最大频率 Max Time
    int Mt=0;
public:
    FreqStack() {}

    void push(int key) 
    {
        // 1）词频+1
        //      1）找的到
        if(Wft.find(key) != Wft.end())
        {
            Wft[key]++;
        }
        //      2）找不到
        else
        {
            Wft[key] = 1;
        }   
        // 2）更新最大频率
        Mt = max(Mt , Wft[key]);
        // 3）加入栈中
        Stk[Wft[key]].push_back(key);
    }
    
    int pop() 
    {
        // 1）记录答案值
        int ans = Stk[Mt].back();
        // 2）弹栈
        Stk[Mt].pop_back();
        // 3）如果 stk[Mt] 没值了 销毁 ---> Mt--
        if(Stk[Mt].size()==0)
        {
            Stk.erase(Mt);
            Mt--;
        }
        // 4）Wft--
        Wft[ans]--;
        if(Wft[ans]==0)
        {
            Wft.erase(ans);
        }
        return ans;
    }
};