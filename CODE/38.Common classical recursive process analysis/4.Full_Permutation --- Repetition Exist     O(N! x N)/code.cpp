// 二：有重复的情况：
// 其实跟无重复情况类似，第一位置先跟自己换，再试试其他位置，如果其他位置的值和第一位置的值一样，就没有换的必要，应为情况相同
// 只要保证每次换的东西跟之前不一样，就可以保证答案不同 ---> 剪枝
//
#include<bits/stdc++.h>

using namespace std;

class Solution 
{
private:
    vector<int> path;
    vector<vector<int>> ans;
    int size;

private:
// 以 i==0 层 举例：
// i == 0 层：先交换 path[0]==1，在交换时发现 path[1]也等于1，在交换没意义，所以 j++，等下一个，当发现 path[2]==2时，发现了新的数，可以试着交换
    void f(int i)
    {
        // 呈上：
        if(i==size)
        {
            ans.push_back(path);
            return;
        }

        unordered_set<int> list;
        // 启下：
        for(int j=i ; j<size ; j++)
        {
            if(list.find(path[j]) == list.end())
            {
                list.insert(path[j]);
                swap(path[i] , path[j]);
                f(i+1);
                swap(path[i] , path[j]);
            }


        }

        return;
    }

public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        // 更新：
        path.clear();
        ans.clear();
        path.assign(nums.begin() , nums.end());
        size = path.size();

        // 特判：
        if(size==0)
        {
            return ans;
        }

        f(0);

        return ans;
    }
};

int main()
{
    vector<int> v = {1 , 1 , 2};
    
    Solution slt;
    vector<vector<int>> ans = slt.permute(v);

    for(const auto& e : ans)
    {
        for(const auto& c : e)
        {
            printf("%d " , c);
        }
        printf("\n");
    }

    return 0;
}