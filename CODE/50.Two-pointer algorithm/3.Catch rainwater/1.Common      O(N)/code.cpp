// 接雨水：

// 时间复杂度：O(N) 、空间复杂度 O(N)
// 做法一：分别讨论每一个柱子上方可以留下几格水
// 1）以第 i 根柱子为例：
// 2）几种情况讨论：
//      1）(l_max > i) && (r_max > i)  可留下的水为：min(l_max , r_max) - i
//      2）(l_max > i) && (r_max = i)  可留下的水为：0
//      3）(l_max > i) && (r_max < i)  可留下的水为：0
//
//      4）(l_max = i) && (r_max > i)  可留下的水为：0
//      5）(l_max = i) && (r_max = i)  可留下的水为：0
//      6）(l_max = i) && (r_max < i)  可留下的水为：0
//
//      7）(l_max < i) && (r_max > i)  可留下的水为：0
//      8）(l_max < i) && (r_max = i)  可留下的水为：0
//      9）(l_max < i) && (r_max < i)  可留下的水为：0

// ==> 综上 第 i 根柱子上方可以留下几格水：min( 0 , (min(l_max , r_max) - i) )

#include<bits/stdc++.h>

using namespace std;

class Solution 
{
private:
    vector<int> l_max;
    vector<int> r_max;
private:

public:
    int trap(vector<int>& height) 
    {
        // { 4 , 2 , 0 , 3 , 2 , 5 }
        //   0   1   2   3   4   5
        //  n = 6
        int n = height.size(); // [0 ... n-1]
        l_max.clear() , r_max.clear();
        l_max.assign(n , 0) , r_max.assign(n , 0);

        // 一、第 i 根柱子 左侧 最高的 柱子的高度
        // l_max[i] ==> [0...i] 上柱子的最高高度
        int maxx = height[0];
        for(int i=0 ; i<= (n-1) ; i++)
        {
            maxx = max(maxx , height[i]);
            l_max[i] = maxx;
        }

        // 二、第 i 根柱子 右侧 最高的 柱子的高度
        // r_max[i] ==> [i...n-1] 上柱子的最高高度
        maxx = height[n-1];
        for(int i=n-1 ; i>=0 ; i--)
        {
            maxx = max(maxx , height[i]);
            r_max[i] = maxx;
        }

        // 三、遍历 [1 ... n-2] 根柱子：因为两侧的柱子留不住水 
        int ans = 0;
        for(int i=1 ; i<=(n-2) ; i++)
        {
            ans += max( 0 , (min(l_max[i-1] , r_max[i+1]) - height[i]));
        }

        return ans;
    }
};

int main()
{
    vector<int> arr = {3 , 5 , 7 , 2 , 8 , 4 , 6 , 3};
    Solution slt;
    cout << slt.trap(arr) << endl;

    return 0;
}