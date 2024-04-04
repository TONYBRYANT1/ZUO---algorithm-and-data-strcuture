#include<bits/stdc++.h>

using namespace std;

const int N = 1e7+10;

class Solution 
{
private:
    int Tree[N][2]; // 因为只需要看看路径是否存在 ==> 不需要 pass 和 end 来构建完整的 trie
    int cnt; // 当前结点总个数
    int high; // 数组中对大值最左边的 1 的下标，从 high 下标开始建树

private:   
    // 看看最大值的最左边的 1 在哪个位置
    int high_bit(int maxx)
    {
        int i=0;
        while(maxx>1)
        {
            maxx >>= 1;
            i++;
        }
        return i;
    }

    // 插入 Trie 字典树
    void bit_insert(int n)
    {
        int tool = 1;
        int path = 0;

        for(int i=high ; i>=0 ; i--)
        {
            path = ((n>>i) & 1);
            
            if(Tree[tool][path]==0)
            {
                Tree[tool][path] = ++cnt;
            }

            tool = Tree[tool][path];
        }
        return;
    }

    // 通过 vector 构建字典树
    void Build_Trie(const vector<int>& nums)
    {
        int maxx = INT_MIN;
        for(const auto& e : nums)
        {
            maxx = max(maxx , e);
        }

        high = high_bit(maxx);

        for(const auto& e : nums)
        {
           bit_insert(e);
        }
        return;
    }

    // 已经构建字典树，想获得最大的 xor
    // 知识点 [1 , 0 , 0 , 0 , 0 ... 0]    >    [0 , 1 , 1 , 1 , 1 ... 1]
    //        i位                               i位
    // 所以只要尽早的得到想要的，权重大的位，即使后面的都是不想要的，仍是最优解
    int MAX_XOR(int e)
    {
        int ans=0; // 答案 越大越好
        int tool=1; // 遍历计数器，一层一层遍历
        int status=0; // 本身这一位是 0 or 1
        int want=0; // 这一位想要 0 or 1
        
        // 开始遍历：
        for(int i=high ; i>=0 ; i--)
        {
            // 看看本身这一位是 0 or 1
            status = ((e>>i)&1);
            // 这一位想要 0 or 1
            want = status^1;
            
            // 想要的没有，只能选另一个了
            if(Tree[tool][want]==0)
            {
                want ^= 1; // 想要的没有，只能换
            }

            // 更新答案：
            ans |=( (want^status) << i);

            // 进入下一结点：
            tool = Tree[tool][want];
        }

        return ans;
    }
    
    // 一次解答完成，重置 Trie
    void clear()
    {
        cnt=1;
        memset(&Tree[0][0] , 0 , sizeof(int)*2*(cnt+1));
        return;
    }

public:
    int findMaximumXOR(vector<int>& nums) 
    {
        // 更新：
        cnt=1;

        // 根据 nums 建 Trie
        Build_Trie(nums);

        // 筛选最大值：
        int maxx = INT_MIN;

        // 遍历每一个 max_xor, 挑一个最大的
        for(const auto& e : nums)
        {
            maxx = max(maxx , MAX_XOR(e));
        }

        // 重制 Trie
        clear();

        // 返回最大值
        return maxx;
    }
};