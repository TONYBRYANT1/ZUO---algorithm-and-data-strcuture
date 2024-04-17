// 走一步看一步，不像 common 方法 直接先遍历一遍求 sum[] 和 hashmap

class Solution 
{
private:
    unordered_map<int , int> hashmap;
    int n , k;

private:    
    int f(const vector<int>& arr)
    {   
        long long sum=0;
        int l=0 , aim=0 , ans=0;
        hashmap.insert({0 , 1});

        for(int r=0 ; r<n ; r++)
        {
            sum += arr[r];
            aim = sum - k;

            if(hashmap.find(aim) != hashmap.end())
            {
                ans += hashmap[aim];
            }

            if(hashmap.find(sum) == hashmap.end())
            {
                hashmap.insert({sum , 1});
            }
            else
            {
                hashmap[sum]++;
            }
        }

        return ans;
    }

public:
    int subarraySum(const vector<int>& nums, int k) 
    {
        n = nums.size();
        this->k = k;

        hashmap.clear();

        return f(nums);
    }
};