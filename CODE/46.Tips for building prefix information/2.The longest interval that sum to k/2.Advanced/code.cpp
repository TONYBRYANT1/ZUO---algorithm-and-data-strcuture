// 走一步看一步，不像 common 方法 直接先遍历一遍求 sum[] 和 hashmap

#include<bits/stdc++.h>
#include <stdexcept>

using namespace std;

class Solution
{
private:    
    int n , k;
    long long sum;
    unordered_map<int , int> hashmap;

private:    
    int f(const vector<int>& arr)
    {
        sum=0;
        int aim=0 , length=0 , l=0;

        hashmap.insert({0 , -1});
        for(int r=0 ; r<n ; r++)
        {   
            sum += arr[r];
            aim = sum - k;

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
    int longest_interval(const vector<int>& arr , int k)
    {
        this->k = k;
        n = arr.size();

        hashmap.clear();

        return f(arr);
    }
};

int main()
{
    int n , m , k , x;
    vector<int> arr;
    scanf("%d%d" , &n , &k);
    m = n;
    arr.clear();
    while(m--)
    {
        scanf("%d" , &x);
        arr.push_back(x);
    }

    Solution slt;
    cout << slt.longest_interval(arr , k) << endl;
    
    return 0;
}