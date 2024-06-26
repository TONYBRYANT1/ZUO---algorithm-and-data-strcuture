// 时间复杂度：O(N) , 额外空间复杂度：O(1)

// 三种思考方式：
// 1）O(N^2) ---(行 or 列 的剪枝) ---> O(N)
// https://leetcode.cn/problems/container-with-most-water/solutions/94102/on-shuang-zhi-zhen-jie-fa-li-jie-zheng-que-xing-tu/

// https://leetcode.cn/problems/container-with-most-water/description/comments/66769
// 2）对O(n)的算法写一下自己的理解，一开始两个指针一个指向开头一个指向结尾，此时容器的底是最大的，
//    接下来随着指针向内移动，会造成容器的底变小，在这种情况下想要让容器盛水变多，就只有在容器的高上下功夫。 
//    那我们该如何决策哪个指针移动呢？我们能够发现不管是左指针向右移动一位，还是右指针向左移动一位，容器的底都是一样的，都比原来减少了 1。
//    这种情况下我们想要让指针移动后的容器面积增大，就要使移动后的容器的高尽量大，
//    所以我们选择指针所指的高较小的那个指针进行移动，这样我们就保留了容器较高的那条边，放弃了较小的那条边，以获得有更高的边的机会。

// 3）这种算法不会错过最优解：
//
//                                                 |
//                               |           |     |
//                               |           |     |
//                      |  |  |  |  |  |  |  |  |  |  
//                      ----------------------------
//                      0  1  2  3  4  5  6  7  8  9  
//                               i                 j
//
//  假设最优解是 (3 , 7)，我们试试看这种算法会不会错过最优解
//  当遇到此时的 (i , j) 站位时(i==3 , j>7)，要想得到最优解 必须 j--，而不是 i++
//  按照算法：如果是 i++，说明 height[i] <= height[j]，而 (3 , 7) 的最优解的最理想情况是 (7-3)*hight[i]
//  既然 height[i] <= height[j] 那么就会出现新的答案 (3 , j) 而不是 (3 , 7)
//  因为 最优解并不会是 (3 , j) 所以 i++是个错误的假设
//  i++(错误假设) --> 最优解为 (3 , j)
//  j--(正确假设) --> 最优解为 (3 , 7)

#include<bits/stdc++.h>

using namespace std;

class Solution 
{
public:
    int maxArea(vector<int>& height) 
    {
        int n = height.size();
        int l = 0 , r = n-1;
        int ans=0;
        // 那边小结算哪边
        while(l<=r)
        {
            ans = max( ans , ( (r-l)*min(height[l] , height[r]) ) );
            if(height[l]<=height[r])
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}