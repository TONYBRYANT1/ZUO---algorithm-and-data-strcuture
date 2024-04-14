// 进阶版本：栈(处理每一位的对应信息) + KMP
// 出现错误是因为 N 太大，但是 LuoGu 上的编译器没有问题，不清楚为什么会出错

#include<bits/stdc++.h>

using namespace std;

typedef pair<int , int> pii;

const int N = 1e6+10;

class Solution
{
private:
    pii stk[N];
    int n , m;
    vector<int> next;
    int size;

private:
    void get_next(const string& s)
    {
        next.clear();

        if(m==1)
        {
            next.push_back(-1);
        }
        else if(m==2)
        {
            next.push_back(-1);        
            next.push_back(0);
        }
        else
        {
            next.assign(m , 0);
            next[0] = -1;
            next[1] = 0;
            int i=2 , cn=0;

            while(i<m)
            {
                if(s[i-1] == s[cn])
                {
                    next[i] = ++cn;
                    i++;
                }
                else if(cn > 0)
                {
                    cn = next[cn];
                }
                else
                {
                    next[i]=0;
                    i++;
                }
            }

        }

        return;
    }

public:
    void remain(const string& s1 , const string& s2)
    {
        n = s1.length();
        m = s2.length();
        int x=0 , y=0;
        size=0;

        get_next(s2);

        while(x < n)
        {
            // 匹配成功：
            if(s1[x] == s2[y])
            {
                stk[size++] = make_pair(x++ , y++); 
            }
            // 没有匹配成功：
            // 1）能跳跃：
            else if(y > 0)
            {
                y = next[y];
            }
            // 2）不能跳跃：y==0
            else
            {
                stk[size++] = make_pair(x++ , -1);
            }
            
            // 结算：
            if(y == m)
            {
                size -= m;
                y = size==0 ? 0 : (stk[size-1].second + 1);
            }   
        }

        for(int i=0 ; i<size ; i++)
        {
            printf("%c" , s1[stk[i].first]);
        }

        return;
    }
};

int main()
{
    string str1 , str2;
    getline(cin , str1);
    getline(cin , str2);

    Solution slt;
    slt.remain(str1 , str2);

    return 0;
}