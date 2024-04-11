// 题目所用到的单调性：
// 差值限制越大(越宽泛)，小于等该差值的对数越多

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
    // 用滑动窗口简化找对数的问题
    // 虽然是两层for 但是时间复杂度：O(N)
    int f(const vector<int>& nums , int limit)
    {
        int cnt=0;
        int n = nums.size();
        for(int i=0 ; i<n ; i++)
        {
            for(int j=i+1 ; j<n ; j++)
            {
                if(abs(nums[i] - nums[j]) <= limit)
                {
                    cnt++;
                }
                else
                {
                    break;
                }
            }
        }

        return cnt;
    }

public:
    int smallestDistancePair(vector<int>& nums, int k) 
    {
        // 用滑动窗口简化找对数的问题
        sort(nums.begin() , nums.end() , MyComparator());

        // 先遍历一遍找到数对差值的最大值
        int minn = nums[0];
        int maxx = minn;

        for(const auto& e : nums)
        {
            minn = min(minn , e);
            maxx = max(maxx , e);
        }

        int l=0 , r = maxx - minn;

        int ans=0;

        while(l<=r)
        {
            int mid = l + ((r-l)>>1);

            // 看看 数对差<=mid 的数对有几对
            if(f(nums , mid) >= k)
            {
                ans = mid;
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }

        return ans;
    }
};

int main()
{
    vector<int> arr = {1 , 3 , 1};
    int k=1;
    Solution slt;
    int a = slt.smallestDistancePair(arr , k);
    cout << a << endl;
    return 0;
}