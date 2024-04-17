#include<bits/stdc++.h>
using namespace std;

// 答案解析：
// 对于最大值的最左边的 i , 如果有 3 对值 (a1 ^ b1) & (a2 ^ b2) & (a3 ^ b3)
// 可以满足使得 i 位 的值为 1
// 但是对于下一步的需求(i 位 和 i+1 位 为1) 就不一定还有 3 对了
// 可以满足需求的 对数(an , bn) 是逐渐缩小的
// 如果 (am , bm) 不能满足 i 位上的需求，那么 其必不能满足 下一步的需求(i 位 和 i+1 位 为1)

class Solution 
{
private:
    int high;
    unordered_set<int> HashSet;
    
private:
    int get_high(int n)
    {
        int i=0;
        while(n>1)
        {
            n>>=1;
            i++;
        }
        return i;
    }

public:
    int findMaximumXOR(vector<int>& nums) 
    {
        // 答案：
        int ans=0;

        // 求最大值：
        int maxx = INT_MIN;
        for(const auto& num : nums)
        {
            maxx = max(maxx , num);
        }
        
        // 求最大值 最左边 的 1
        // 看看最大值从哪一位开始：想要 xor 出最大值，必须在高位不同，而高位多数是 0
        // 所以最大值最左边的 1 限制了 xor_max;
        high = get_high(maxx);

        // 从最高位开始筛选，看看有没有能满足需求的(高位为 1)：
        for(int i=high ; i>=0 ; i--)
        {
            // 当前的需求：              
            // eg: 假如 maxx = 25 --> (0001 1001)2
            // high = 4
            // 当前需求  ：(0001 0000) ---> 想让最高位为 1
            // 下一位需求：(0001 1000) ---> 次高位位为 1 (当最高位需求能被满足时)
            // 下一位需求：(0000 1000) ---> 次高位位为 1 (当最高位需求不能被满足时)
            int want = ( ans | (1<<i) );
            //                                         31 30 ...7 6 5 4 3 2 1 0 
            // 只看：[31...i] 位 其中包含了需求 (当前需求[0  0 ... 0 0 0 1 0 0 0 0 ]), 其他位不看
            HashSet.clear();

            // 当参数转化为当前需求需要看的形式
            // eg: 仅看 [31...6] ，需求为 (0100 0000)2
            // 参数 a:(0101 0011)2 ==(转化)==> a:(0100 0000)2
            for(auto num : nums)
            {
                num = ((num>>i)<<i); // 仅观察参数在[32 ... i] 位的状态
                HashSet.insert(num);
            }

            // 遍历每个参数：看看有没有参数可以满足当前需求：
            // want(当前需求) = s1(参数1) ^ s2(参数2)
            // ==> a = b ^ c --> b = a ^ c or c = a ^ c
            // s2(参数2) = want(当前需求) ^ s1(参数1)
            // 以 s1(参数1) 的视角搜寻 s2(参数2)
            for(const auto& s1 : HashSet)
            {
                // 可以满足要求( s1 所对应的 s2 可以找到)：
                if(HashSet.find(want ^ s1) != HashSet.end())
                {
                    // i 位的要求可以被满足：
                    // 答案改变：
                    ans = want; // 答案改变
                    break; // 找到一组即可
                }
            }
            // i 位的答案不能被满足：
            // ans 的 i 位上仍为 0 ---> ans 不改变
        }

        // 返回答案
        return ans;
    }
};