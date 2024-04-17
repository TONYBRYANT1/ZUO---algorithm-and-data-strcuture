// 问题转化：工作时间 t
// 1）t >  8 ---> 1
// 2）t <= 8 ---> -1
// 3）求 区间和 >= 1 的最长区间长度

#include<bits/stdc++.h>

using namespace std;

class Solution 
{
private:
    class MyComparator
    {
    public: 
        bool operator() (const int& a , const int& b) const 
        {
            return a < b;
        }
    };

private:
    vector<int> sum;
    map<int , int , MyComparator> map;
    int n;

private:
    // sum:[0 1 ... n n+1]
    void get_sum()
    {
        for(int i=1 ; i<=(n+1) ; i++)
        {
            sum[i] += sum[i-1];
        }

        return;
    }

    void get_map()
    {
        map.clear();
        map.insert({0 , 0}); // 特殊

        for(int i=1 ; i<=n ; i++)
        {
            if(map.find(sum[i]) == map.end())
            {
                map.insert({sum[i] , i});
            }
        }

        return;
    }

    int f()
    {
        int length=0 , l=0 , search=0;

        // 遍历每一个元素
        for(int r=1 ; r<=n ; r++)
        {
            // 找到当前比自己小的区间和
            search = sum[r]-1;

            for(const auto& e : map)
            {
                if(e.first <= search)
                {
                    l = e.second;
                    if(l < r)
                    {
                        length = max(length , r-l);
                    }
                }
            }
        }

        return length;
    }

public:
    int longestWPI(vector<int>& hours) 
    {
        n = hours.size();
        sum.clear();
        sum.assign(n , 0);

        // >8 -> 1 、<=8 -> -1
        for(int i=0 ; i<n ; i++)
        {
            sum[i] = hours[i]>8 ? 1 : -1;
        }

        sum.insert(sum.begin() , 0);
        sum.insert(sum.end() , 0);

        get_sum();

        get_map();

        return f();
    }
};