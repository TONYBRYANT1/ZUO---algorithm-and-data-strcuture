// 问题转化：工作时间 t
// 1）t >  8 ---> 1
// 2）t <= 8 ---> -1
// 3）求 区间和 >= 1 的最长区间长度

// 简化：
// 1）当 sum[r]>0 ，最长区间长度：r
// 2）当 sum[r]<0 ，只用找 search = (sum[r]-1)
//    原因：
//          1）为了让 sum[r]>=1 ，sum[r] 必须减去比自己小的区间和
//          2）不需要找 小于(sum[r]-1)的区间和，因为如果找小于 ((sum[r]-1)) 的区间和，由于区间和的值是逐步增加 or 逐步减少的，
//             如果有 小于(sum[r]-1)的区间和，则 (sum[r]-1) 必在 小于(sum[r]-1)的区间和 前面

#include<bits/stdc++.h>

using namespace std;

class Solution 
{
private:
    vector<int> sum;
    unordered_map<int , int> hashmap;
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

    void get_hashmap()
    {
        hashmap.clear();
        hashmap.insert({0 , 0}); // 特殊

        for(int i=1 ; i<=n ; i++)
        {
            if(hashmap.find(sum[i]) == hashmap.end())
            {
                hashmap.insert({sum[i] , i});
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
            if(sum[r] > 0)
            {
                length = r;
            }
            else
            {
                if(hashmap.find(sum[r]-1) != hashmap.end())
                {
                    l = hashmap[sum[r]-1];
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

        get_hashmap();

        return f();
    }
};