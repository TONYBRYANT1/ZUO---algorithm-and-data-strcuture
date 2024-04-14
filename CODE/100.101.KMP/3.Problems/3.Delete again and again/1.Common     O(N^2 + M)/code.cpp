// 现有字符串 s1，有子串 s2，让 s1 重复的删除最左边的字符串 s2，直到没有 s2 为止，得到剩下的字符串

#include<bits/stdc++.h>

using namespace std;

class Solution
{
private:
    int n , m;
    vector<int> next;
    string s3; // s1的backup

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
            next.push_back(-1);
            next.push_back(0);

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

    int find(const string& s1 , const string& s2)
    {
        int x=0 , y=0;

        while((x<n) && (y<m))
        {
            if(s1[x] == s2[y])
            {
                x++ , y++;
            }
            else if(y > 0)
            {
                y = next[y];
            }
            else
            {
                x++;
            }
        }

        return y==m ? (x-m) : -1;
    }

public:
    string remain(const string& s1 , const string& s2)
    {
        s3  = s1;
        n = s1.length() , m = s2.length();

        int index;
        get_next(s2);

        while((index=find(s3 , s2)) != -1)
        {
            s3.erase(index , m);
        }

        return s3;
    }
};

int main()
{
    string str1 , str2;
    getline(cin , str1);
    getline(cin , str2);

    Solution slt;

    cout << slt.remain(str1 , str2) << endl;

    return 0;
}