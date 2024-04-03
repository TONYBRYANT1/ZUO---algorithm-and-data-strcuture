// 一：无重复的情况：
// 实例：
//          eg：1 , 2 , 3
//          
//                     |---> 2.(1 , 1) ---> 3.(3 , 3) ---> 1 2 3
//          1.(0 , 0)
//                     |---> 2.(1 , 2) ---> 3.(3 , 3) ---> 1 3 2
//
//
//                     |---> 2.(1 , 1) ---> 3.(3 , 3) ---> 2 1 3
//          1.(0 , 1)
//                     |---> 2.(1 , 2) ---> 3.(3 , 3) ---> 2 3 1
//
//
//                     |---> 2.(1 , 1) ---> 3.(3 , 3) ---> 3 1 2
//          1.(0 , 2)
//                     |---> 2.(1 , 2) ---> 3.(3 , 3) ---> 3 2 1
//
//
// 其实每一层都在以 i 位为中心跟别的位置交换：
// 0）i==0 , 将 0 位置的数 与 1 , 2 , 3 , 4 , ... , n-1 位置交换，从而固定 i 位置的数
// 1）i==1 , 将 1 位置的数 与 2 , 3 , 4 , ... , n-1     位置交换，从而固定 i 位置的数
// 2）i==2 , 将 1 位置的数 与 3 , 4 , ... , n-1     位置交换，从而固定 i 位置的数
// 3）i==3 , 将 1 位置的数 与 4 , ... , n-1     位置交换，从而固定 i 位置的数
// ...                              
// ...
//
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
    void f(int i)
    {
        // 呈上：
        if(i==size)
        {
            ans.push_back(path);
            return;
        }

        // 启下：
        for(int j=i ; j<size ; j++)
        {
            swap(path[i] , path[j]);
            f(i+1);
            swap(path[i] , path[j]);
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
    vector<int> v = {1 , 2 , 3};
    
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