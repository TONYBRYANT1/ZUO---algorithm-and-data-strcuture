// 走一步看一步，不像 common 方法 直接先遍历一遍求 sum[] 和 hashmap

class Solution 
{
private:
    // key: 当前位置前缀和 % p 的余数
    // value: 下标
    unordered_map<int , int> hashmap;
    
    int n , mod , p;

private:    
    int f(const vector<int>& arr)
    {
        int length=INT_MAX , l=0 , search=0 , cur=0;
        hashmap.clear();
        hashmap.insert({0 , -1});

        for(int r=0 ; r<n ; r++)
        {
            // 看看当前前缀和余数为多少
            cur = (cur+arr[r])%p;
            // search = (cur - mod + p)%p;
            search = cur>=mod ? (cur-mod) : (cur-mod+p);

            if(hashmap.find(search) != hashmap.end())
            {
                l = hashmap[search];
                length = min(length , r-l);
            }

            if(hashmap.find(cur) == hashmap.end())
            {
                hashmap.insert({cur , r});
            }
            else
            {
                hashmap[cur] = r;
            }
        } 

        return length;
    }
public:
    int minSubarray(vector<int>& nums, int p) 
    {
        n = nums.size() , this->p = p;
        int sum=0;
        for(const auto& e : nums)
        {
            sum = (sum+e)%p;
        }

        mod = sum%p;

        if(mod==0)
        {
            return 0;
        }
        else
        {
            return f(nums)==n ? -1 : f(nums);
        }
    }
};