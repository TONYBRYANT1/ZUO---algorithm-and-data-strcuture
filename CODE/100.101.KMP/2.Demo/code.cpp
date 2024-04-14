#include<bits/stdc++.h>

using namespace std;

class Solution
{
private:
    int n , m;
    vector<int> next;

private:
	// 得到 next数组
	// 时间复杂度：O(m) m---b串的长度
	// b串的每一个字符求 next[] 的均摊时间复杂度：O(1)
    void get_next(const string& str)
    {
        next.clear();

		// next[0]、next[1] 特判
        if(m==1)
        {
            next.push_back(-1);
        }
        else if(m==2)
        {
            next.push_back(-1);
            next.push_back(0);
        }
        // m >= 3
        else
        {
            next.assign(m , 0);
            next[0] = -1;
            next[1] = 0;
            int i = 2 , cn = 0;

            while(i<m)
            {
                // 一、str[i-1] == str[next[i-1]] ---> cn不用跳跃
                if(str[i-1] == str[cn])
                {
                    next[i] = ++cn;
                    i++;
                }
                // 二、str[i-1] != str[next[i-1]] ---> cn 需要跳跃
                // 1）cn还能跳跃：
                else if(cn > 0)
                {
                    cn = next[cn];
                }
                // 2）cn不能跳跃 cn==0
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
	// 时间复杂度：O(n+m) n---a串的长度、m---b串的长度
    int strStr(const string& a , const string& b)
    {
        n = a.length() , m = b.length();
        int x=0 , y=0;
        get_next(b);

		// a、b串比对过程：
		// 时间复杂度：O(n) n---a串的长度
		// a串每一位进行比对的平均时间复杂度：O(1) (在这期间 y 会进行跳转)
        while(x<n && y<m)
        {
            // 一、不用跳跃：
            if(a[x] == b[y])
            {
                x++ , y++;
            }
            // 二、需要跳跃：
            // 1）还能跳跃：
            else if(y > 0)
            {
                y = next[y];
            }
            // 2）不能跳跃：
            else
            {
                x++;
            }
        }

        return y==m ? (x-m) : -1;
    }
};

int main()
{
    string a = "mississippi";
    string b = "pi";

    Solution slt;
    cout << slt.strStr(a , b) << endl;
    return 0;
}