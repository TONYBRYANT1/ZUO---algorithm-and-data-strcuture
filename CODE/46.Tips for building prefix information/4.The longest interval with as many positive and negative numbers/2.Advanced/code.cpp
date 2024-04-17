// 走一步看一步，不像 common 方法 直接先遍历一遍求 sum[] 和 hashmap
 
#include<bits/stdc++.h>

using namespace std;

class Solution
{
private:
    unordered_map<int , int> hashmap;
    vector<int> arr;
    int n;

private:   
    int f()
    {
        int sum=0 , l=0 , aim=0 , length=0;
        hashmap.clear();
        hashmap.insert({0 , -1});

        for(int r=0 ; r<n ; r++)
        {
            sum += arr[r];
            aim = sum;

            if(hashmap.find(aim) != hashmap.end())
            {
                l = hashmap[aim];
                length = max(length , r-l);
            }

            if(hashmap.find(sum) == hashmap.end())
            {
                hashmap.insert({sum , r});
            }
        }

        return length;
    }

public:
    int longest_interval(const vector<int>& nums)
    {
        n = nums.size();
        arr.clear();
        arr.assign(n , 0);

        for(int i=0 ; i<n ; i++)
        {
            arr[i] = nums[i]==0 ? 0 : (nums[i]>0 ? 1 : -1);
        }

        return f();
    }
};

int main()
{
    int n , m , x;
    vector<int> arr;
    scanf("%d" , &n);
    m = n;

    arr.clear();
    while(m--)
    {   
        scanf("%d" , &x);
        arr.push_back(x);
    }

    Solution slt;
    cout << slt.longest_interval(arr) << endl;

    return 0;
}