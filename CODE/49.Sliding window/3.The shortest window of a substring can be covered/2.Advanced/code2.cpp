// 在 Common 方法的基础上 用 arr[] 代替 hashmap 进行优化

#include<bits/stdc++.h>

using namespace std;

const int N = 130;

class Solution 
{
private:  
    class MyComparator
    {
    public:
        bool operator()(const int& a , const int& b) const
        {
            return a < b;
        }
    };

private:
    // A(65) ~ Z(90)
    // a(97) ~ z(122)
    int ans[N] , procedure[N];
    int n , m;

private:
    bool up_to_standard()
    {
        // 97 122 65 90
        for(int i=65 ; i<=90 ; i++)
        {
            if(procedure[i] < ans[i])
            {
                return false;
            }
        }
        
        for(int i=97 ; i<=122 ; i++)
        {
            if(procedure[i] < ans[i])
            {
                return false;
            }
        }
        return true;
    }

public:
    string minWindow(string s, string t) 
    {  
        string minn;
        minn.clear();
        n = s.length() , m = t.length();
        memset(&ans[0] , 0 , sizeof(ans));
        memset(&procedure[0] , 0 , sizeof(procedure));
        // ans
        for(const auto& c : t)
        {
            ans[(int)c] += 1;
        }

        int length=INT_MAX;

        for(int l=0 , r=0 ; r<n ; r++)
        {   
            // 增加字符已达到要求
            procedure[(int)s[r]] += 1;

            // 达到要求之后，缩短距离，接近答案
            while((up_to_standard()) && ((procedure[int(s[l])]-1) >= ans[(int)s[l]]))
            {
                procedure[int(s[l++])]--;
            }

            // 收集当前 以 s[r] 结尾的最小的覆盖区间
            if(up_to_standard())
            {
                if((r-l+1)<=length)
                {
                    length = (r-l+1);
                    minn = s.substr(l , (r-l+1));
                }
            }
        }

        return minn;
    }
};