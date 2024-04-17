#include<bits/stdc++.h>

using namespace std;

class Solution 
{
private:
    vector<int> sum;
    unordered_map<int , vector<int>> hashmap;
    int n , aim;

private:
    // sum:[0 1 ... n n+1]
    void get_sum()
    {
        for(int i=1 ; i<=(n+1) ; i++)
        {
            sum[i] += sum[i-1];
        }

        return;
    }

    void get_hashmap()
    {
        hashmap.clear();
        hashmap.insert({0 , vector<int>{0}});
        for(int i=1 ; i<=n ; i++)
        {
            if(hashmap.find(sum[i]) == hashmap.end())
            {
                hashmap.insert({sum[i] , vector<int>{i}});
            }
            else
            {
                hashmap[sum[i]].push_back(i);
            }
        }
    }

    int f()
    {   
        for(auto& pair : hashmap)
        {
            sort(pair.second.begin() , pair.second.end())
        }
        int ans=0 , search=0 , l=0;
        for(int r=1 ; r<=n ; r++)
        {
            search = sum[r] - aim;
            if(hashmap.find(search) != hashmap.end())
            {
                for(const auto& e : hashmap[search])
                {
                    if(e < r)
                    {
                        ans++;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        
        return ans;
    }

public:
    int subarraySum(vector<int>& nums, int k) 
    {   
        aim = k;
        n = nums.size();
        sum.clear();
        sum = nums;
        sum.insert(sum.begin() , 0);
        sum.insert(sum.end() , 0);

        get_sum();

        get_hashmap();

        return f();
    }
};

int main()
{
    vector<int> arr = {1 , 1 , 1};
    int aim=2;
    
    Solution slt;
    cout << slt.subarraySum(arr , aim) << endl;

    return 0;
}