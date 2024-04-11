// 吃香蕉问题：
// 二分答案法：时间复杂度：O(log2(max_piles[i]) x N)
//            空间复杂度：O(1)
// 1）找到 speed 的 合理答案范围
// 2）通过单调性进行 l 和 r 的移动：speed 越大 | t 越小(可能不变，但是整体趋势是变小的)
// 3）记录答案，继续寻找最优解

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

class Solution 
{
private:
    bool suit(const vector<int>& piles , int speed , int h)
    {
        // 以 speed 的速度吃香蕉，要多久吃完
        ll t=0;
        h = (ll)h;
        for(const auto& e : piles)
        {
            t += (e + (speed-1)) / speed; // 向上取整
        }
        return t <= h;
    }

public:
    // h >= piles.length
    int minEatingSpeed(vector<int>& piles, int h)
    {
        // 吃香蕉可能的速度范围：1 ~ max_piles[i]
        int l=1 , r=piles[0] , ans=0;
        for(const auto& e : piles)
        {
            r = max(r , e);
        }

        // 开始二分：
        while(l<=r)
        {
            int mid = l + ((r-l) >> 1); // 防止溢出的写法

            // 这个速度达标：
            if(suit(piles , mid , h))
            {
                // 记录答案
                ans = mid;
                // 看看还有没有更小的速度
                r = mid-1;
            }
            // 速度不达标
            else
            {
                l = mid+1;
            }
        }

        return ans;
    }
};