// 用 debt 和 list 的组合 减少了区间是否满足条件的判断次数

#include<bits/stdc++.h>

using namespace std;

const int N = 130;

class Solution 
{
private:
    int debt;
    int list[N];
    int n , m;

public:
    string minWindow(string s, string t) 
    {
        string ans;
        ans.clear();

        n = s.length() , m = t.length();
        debt = m;
        memset(&list[0] , 0 , sizeof(list));

        for(const auto& c : t)
        {
            list[(int)c]--;
        }

        int length = INT_MAX , temp=0;

        // 时间复杂度：O(N)
        for(int l=0 , r=0 ; r<n ; r++)
        {
            // 增加字符以达到覆盖子串的区间
            // 1）不管还的是不是债款字符，对应的list都要++
            // 2）还的是债款字符，debt--
            temp = s[r];
            if(list[temp]<0)
            {
                debt--;
            }
            list[temp]++;

            // 达到要求
            if(debt==0)
            {
                // 尝试缩减区间：
                while(list[int(s[l])] > 0)
                {
                    list[int(s[l++])]--;
                }

                // 收集以 s[r] 结尾的，满足要求的，长度最小的区间
                if((r-l+1) <= length)
                {
                    length = (r-l+1);
                    ans = s.substr(l , length);
                }
            }

        }

        return ans;
    }
};

int main()
{
    string s , t;
    s = "ADOBECODEBANC";
    t = "ABC";

    Solution slt;
    cout << slt.minWindow(s , t) << endl;

    return 0;
}