#include<bits/stdc++.h>

using namespace std;

class Solution 
{
private:
    vector<long long> sum;
    // key: 当前位置前缀和 % p 的余数
    // value: 下标
    unordered_map<int , vector<int>> hashmap;
    int n , p , mod;

private:
    class MyComparator
    {
    public:
        bool operator() (const int& a , const int& b) const
        {
            return a > b;
        }
    };

private:
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
        
        int key=0;
        for(int i=1 ; i<=n ; i++)
        {
            key = sum[i]%p;
            if(hashmap.find(key) == hashmap.end())
            {
                hashmap.insert({key , vector<int>{i}});
            }
            else
            {
                hashmap[key].push_back(i);
            }
        }

        for(auto& e : hashmap)
        {
            sort(e.second.begin() , e.second.end() , MyComparator());
        }

        return;
    }

    int f()
    {
        int length=-1 , l=0 , search=0;
        for(int r=1 ; r<=n ; r++)
        {
            // temp = sum[r]%p > mod时：search = temp - mod
            // temp = sum[r]%p < mod时：search = temp + p - mod
            // 综上：search = (temp + p - mod)%p
            search = ((sum[r]%p) + p - mod)%p;

            if(hashmap.find(search) != hashmap.end())
            {
                for(const auto& l : hashmap[search])
                {
                    if(l < r)
                    {
                        if(length < 0)
                        {
                            length = max(length , r-l);
                        }
                        else
                        {
                            length = min(length , r-l);
                        }
                        
                    }
                }
            }
        }

        return length;
    }
public:
    int minSubarray(vector<int>& nums, int p) 
    {
        this->p = p;
        n = nums.size();
        sum.assign((n+2) , 0);

        for(int i=0 ; i<n ; i++)
        {
            sum[i+1] = nums[i];
        }

        get_sum();

        mod = sum[n]%p;

        if(mod==0)
        {
            return 0;
        }
        else
        {
            get_hashmap();

            return f()==n ? -1 : f();
        }

    }
};

int main()
{
    vector<int> arr = {3 , 1 , 4 , 2};
    int p = 6;

    Solution slt;
    cout << slt.minSubarray(arr , p);
}