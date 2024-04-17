// 此方法可以收集每一个以 nums[r] 结尾 并且 区间和满足要求的最小区间
// 在通过比较 得出最短区间

#include<bits/stdc++.h>

using namespace std;

class Solution 
{
public:
    // 窗口(虫子) 向右滑动(蠕动)
    int minSubArrayLen1(int target, vector<int>& nums) 
    {
        int n = nums.size();
        int sum=0 , ans=INT_MAX;

        // r 每次容纳一个新的元素
        // 时间复杂度：O(N) --- l、r都不回退
        for(int l=0 , r=0 ; r<n ; r++)
        {
            // 计算窗口大小
            sum += nums[r];

            // 只要还满足 >= target，窗口就缩小
            while((sum>=target) && ((sum-nums[l]) >= target))
            {
                sum -= nums[l];
                l++;
            }

            // 对于前几个元素的特判：
            // 当前几个元素之和仍小于target，则命中
            if(sum >= target)
            {
                ans = min(ans , (r-l+1));
            }
        }

        // 有没有合理的答案
        return ans==INT_MAX ? 0 : ans;
    }

    // 窗口(虫子) 向左滑动(蠕动)
    int minSubArrayLen2(int target, vector<int>& nums) 
    {
        int n = nums.size();
        int sum=0 , ans=INT_MAX;

        for(int l=n-1 , r=n-1 ; l>=0 ; l--)
        {
            sum+=nums[l];
            while(( sum>=target ) && ( (sum-nums[r])>=target ))
            {
                sum -= nums[r];
                r--;
            }

            if(sum>=target)
            {
                ans = min(ans , (r-l+1));
            }
        }

        return ans==INT_MAX ? 0 : ans;
    }
};