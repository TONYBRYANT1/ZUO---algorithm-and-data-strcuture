// https://leetcode.cn/problems/trapping-rain-water/solutions/1502995/shuang-zhi-zhen-by-lafiteee-aay8/

// 渐渐地发现一种单调性，哪边的 max 值小就结算那一端
// 不需要额外数组
// 双指针解决
// 时间复杂度：O(N) 、空间复杂度 O(1)

// 总结：
// 1）根据 Common 方法知道了 每个柱子上能接多少雨水，完全由柱子两侧的最高柱子中的较小一根决定：
//    max(0 , min(l_max , r_max)-height[i])
// 2）那么重点就是要找出较小的那一根
// 3）对于 i 指针来说，l_max 是真实的，r_max 是不真实的，但至少，右侧柱子最大值 >= r_max 的
//    所以对于 i 来说，当 l_max <= r_max <= r_max(真实值)，就可以确定左边的答案了，因为 i 柱子两侧的最高柱子中的较小一根一定是 l_max
//    但是如果 l_max > r_max <= r_max(真实值)，就不能判断，柱子两侧的最高柱子中的较小一根到底是什么了
//    于是换方向讨论 r 指针
//    因为对于 r 柱子，r_max 是真实的，l_max 是基础值，又因 l_max > r_max，所以 j 柱子两侧的最高柱子中的较小一根一定是 r_max
//    于是又可以确定答案了

#include<bits/stdc++.h>

using namespace std;

class Solution 
{
public:
    int trap(vector<int>& height) 
    {
        int n = height.size();
        // 柱子数 <= 2
        if(n<=2)
        {
            return 0;
        }
        // 柱子数 3 个起步
        else
        {   
            int ans=0;
            int l = 1 , r = n-2;
            int l_max = height[0] , r_max = height[n-1];
            // 发现那边的 max(l_max or r_max)值 小，就结算哪边
            while(l<=r)
            {
                // 结算左边：
                if(l_max <= r_max)
                {
                    ans += max(0 , (l_max - height[l]) );
                    l_max = max(l_max , height[l]);
                    l++;
                }
                // 结算右边：
                else
                {
                    ans += max(0 , (r_max - height[r]) );
                    r_max = max(r_max , height[r]);
                    r--;
                }
            }

            return ans;
        }
    }
};

int main()
{
    vector<int> arr = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution slt;
    cout << slt.trap(arr) << endl;

    return 0;
}
