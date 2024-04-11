// 画匠问题：

// 给定一个非负整数数组 nums 和一个整数 k ，你需要将这个数组分成 k 个非空的连续子数组。
// 设计一个算法使得这 k 个子数组各自和的最大值最小。

#include<bits/stdc++.h>

using namespace std;

class Solution 
{
private:
    int n;

private:
    // h - 每个人最多的工作量， 返回完成该任务最少要几个人(每个人必须连续作业)
    int f(int h , const vector<int>& nums) 
    {
        int cnt=1;
        int sum=0;
        for(int i=0 ; i<n ; i++)
        {
            if((sum+nums[i]) > h)
            {
                cnt++;
                sum = nums[i];
            }
            else
            {
                sum+=nums[i];
            }
        }
        return cnt;
    }

public:
    int splitArray(vector<int>& nums, int k)
    {
        n = nums.size();

        int maxx = nums[0] , sum=0;
        for(const auto& e : nums)
        {
            sum += e;
            maxx = max(maxx , e);
        }

        int h_max = sum;
        int h_min = maxx;

        int h_l = maxx; // 画家数 == 数组个数 时 工作时间最短
        int h_r = sum;  // 一个画家 时 工作时间最长

        int ans=0;

        // 二分逐渐逼近
        while(h_l <= h_r)
        {
            int mid = h_l + ((h_r - h_l) >> 1);

            if(f(mid , nums) <= k)
            {
                ans = mid;
                h_r = mid-1;
            }
            else
            {
                h_l = mid+1;
            }
        }

        return ans;
    }
};

int main()
{
    int h = 23;
    vector<int> arr = {7 , 2 , 5 , 10 , 8}; 
    Solution slt;
    slt.splitArray(arr , 2);
}