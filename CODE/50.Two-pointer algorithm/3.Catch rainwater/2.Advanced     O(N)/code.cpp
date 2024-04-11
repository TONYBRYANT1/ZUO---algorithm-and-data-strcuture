// 渐渐地发现一种单调性，哪边的 max 值小就结算那一端
// 不需要额外数组
// 双指针解决
// 时间复杂度：O(N) 、空间复杂度 O(1)

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
    vector<int> arr = {3 , 5 , 7 , 2 , 8 , 4 , 6 , 3};
    Solution slt;
    cout << slt.trap(arr) << endl;

    return 0;
}
