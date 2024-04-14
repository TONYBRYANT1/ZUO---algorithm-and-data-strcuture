// 循环节的最小重复长度：
//
// 循环节：
//          由循环字符串 s2 构成，s2至少一个，剩余的部分可以不全

// 问题：
// 现有一个循环节，求最小循环长度 s2

// 定理：
// 最小循环长度：循环节长度 - 循环节中前后缀的最大匹配长度
//
// eg:
//      a b c a b c a b c a b c a b
//
// 1）肉眼观察：
// 不难看出重复字符串可以是 s2_1: a b c a b c
//               也可以是 s2_2: a b c
// 题目要求最小，则该循环节的最小重复长度为: a b c
//
// 2）推理：
//            A     A     A     A    L
//          ----- ----- ----- ----- ---
//          a b c a b c a b c a b c a b
// index:   i ................. j
// index:         k ................. l
// 任意长度的循环节一定由 k个 最小重复部分 A 和 剩余部分 L 组成，即：M = k*A + L
// 而 循环节的 前后缀最大匹配长度一定为：N = (k-1)*A + L
// 前后缀最大匹配长度可以进行验证：假设为 Q (Q>N)，则 最小重复部分会改变为 LCM(A.length() , (Q-N))
// 将其作差：M - N = A 即为最小重复部分长度

#include<bits/stdc++.h>

using namespace std;

class Solution
{
private:
    vector<int> next;
    int l;

private:
    void get_next(const string& str)
    {
        next.clear();
        
        // 特判：
        // 特判要到什么程度？
        // next[0]、next[1] 不需要判断，当需要判断 next[3]时，不加特判
        if(l==1)
        {
            next.push_back(-1);
            next.push_back(0);
        }
        // 至少两个：需要求 next[3] ---> 所以从 长度为两个的开始不需要特判
        else
        {
            next.assign((l+1) , 0);
            next[0] = -1;
            next[1] = 0;
            int i=2 , cn=0;

            // 要求判断整个字符串的前后缀匹配长度，所以要加一位
            while(i<=l) 
            {
                if(str[i-1] == str[cn])
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
                    next[i] = 0;
                    i++;
                }
            }
        }

        return;
    }

public:
    int length(const string& str)
    {
        l = str.length();
        get_next(str);

        return l - next[l];
    }
};

int main()
{
    int n;
    string str;
    scanf("%d" , &n);
    getchar();

    getline(cin , str);

    Solution slt;
    printf("%d" , slt.length(str));

    return 0;
}