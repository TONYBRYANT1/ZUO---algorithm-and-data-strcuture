// 2.Generate_Permutation：
// 不要求顺序，只需要看每个数出现几次
//
// aabaac
// 112113
// 64
// 5*2*2 = 20
#include<bits/stdc++.h>

using namespace std;

class Solution 
{
private:    
    int path[20];
    int size;
    int pointer;
    vector<int> arr;
    vector<vector<int>> ans;

private:   
    class Comparator
    {
    public:
        bool operator()(int a , int b)
        {
            return a < b;
        }
    };

    void f(int i , int pointer)
    {
        // 呈上：
        if(i == size)
        {
            vector<int> v;
            for(int i=0 ; i<pointer ; i++)
            {
                v.push_back(path[i]);
            }
            ans.push_back(v);

            return;
        }

        // 主体：
        // 1 1 1 1 1 1 1 2 2 2 2 3 3 3 3
        // i             j
        int j = i+1;
        while((j<size)&&(arr[j]==arr[i]))
        {
            j++;
        }

        // 1.加0个 2.加1个 3.加2个 4.加(j-i)个 // 共 j-i+1 种情况：
        // 1）加0
        f(j , pointer);
        // 2）加0 加1 加2 ... 加(j-i)个
        int n = j-i;
        while(n--)
        {
            path[pointer++] = arr[i];
            f(j , pointer);
        }
        
        return;
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        // 更新：
        this->arr.assign(nums.begin() , nums.end());
        sort(arr.begin() , arr.end() , Comparator());
        size = arr.size();
        ans.clear();
        pointer=0;
        
        // 特判：
        if(size==0)
        {
            return ans;
        }

        f(0 , pointer);

        return ans;
    }
};

int main()
{
    vector<int> v = {1 , 1 , 2 , 1 , 1 , 3};
    Solution slt;

    vector<vector<int>> ans = slt.subsetsWithDup(v);
    for(const auto& e : ans)
    {
        for(const auto& c : e)
        {
            printf("%d " , c);
        }
        printf("\n");
    }
    cout << ans.size() << endl;
    return 0;
}