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
public:
    int numRescueBoats(vector<int>& people, int limit) 
    {
        // 排序：
        sort(people.begin() , people.end() , MyComparator());
        
        // 双指针前后相向遍历数组：
        int sum=0 , ans=0;
        int n = people.size();
        int l = 0 , r = n-1;

        // 到最后有两种情况：
        // eg：limit = 10
        // 1）    4    5
        //        i    j
        // 2）       5
        //          ij
        // 结束状态相同：l > r
        // 两种写法：
            // 第一种：
        while(l<=r) // 跳出while 的原因：l > r
        {
            // 特判：
            sum = l==r ? people[l] : (people[l]+people[r]);
            if(sum > limit)
            {
                r--;
            }
            else
            {
                l++;
                r--;
            }
            ans++;
        }

            // 第二种：
        // while(l<r) // 跳出while 的原因：l >= r，但是 当 l==r 时第二种情况还没有结束
        // {
        //     // 到最后有两种情况：
        //     // eg：limit = 10
        //     // 1）    4    5
        //     //        i    j
        //     // 2）       5
        //     //          ij
        //     sum = l==r ? people[l] : (people[l]+people[r]);
        //     if(sum > limit)
        //     {
        //         r--;
        //     }
        //     else
        //     {
        //         l++;
        //         r--;
        //     }
        //     ans++;
        // }

        //// 发生第二种情况时：
        // if(l==r)
        // {
        //     ans++;
        // }


        return ans;
    }
};