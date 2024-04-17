#include<bits/stdc++.h>

using namespace std;

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
    map<int , int , MyComparator> ans , procedure , temp;
    int n , m;

private:
    bool up_to_standard()
    {
        for(const auto& pair : ans)
        {
            if(procedure[pair.first] < pair.second)
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
        ans.clear() , procedure.clear();
        // ans
        for(const auto& c : t)
        {
            ans[(int)c] += 1;
        }

        int length=INT_MAX;

        for(int l=0 , r=0 ; r<n ; r++)
        {
            procedure[(int)s[r]] += 1;

            while((up_to_standard()) && ((procedure[int(s[l])]-1) >= ans[(int)s[l]]))
            {
                procedure[int(s[l++])]--;
            }

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

int main()
{
    string s = "ab";
    string t = "a";

    Solution slt;
    cout << slt.minWindow(s , t) << endl;

    return 0;
}