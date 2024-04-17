#include<bits/stdc++.h>

using namespace std;

class Solution
{
private:
    vector<int> sum;
    unordered_map<int , int> hashmap;
    int n;

private:
    void get_sum()
    {
        // sum:[0 1 ... n n+1]
        for(int i=1 ; i<=(n+1) ; i++)
        {
            sum[i] += sum[i-1];
        }

        return;
    }

    void get_hashmap()
    {
        hashmap.clear();
        hashmap.insert({0 , 0});

        for(int i=1 ; i<=n ; i++)
        {
            if(hashmap.find(sum[i]) == hashmap.end())
            {
                hashmap.insert({sum[i] , i});
            }
        }

        return;
    }

    int f()
    {
        int length=0 , l=0 , search=0;

        for(int r=1 ; r<=n ; r++)
        {   
            search = sum[r];

            if(hashmap.find(search) != hashmap.end())
            {
                l = hashmap[search];
            
                if(l<r)
                {
                    length = max(length , r-l);
                }
            }
        }

        return length;
    }

public:
    int longest_interval(const vector<int>& nums)
    {
        sum.clear() , n = nums.size();
        sum.assign(n , 0);

        for(int i=0 ; i<n ; i++)
        {
            sum[i] = nums[i]==0 ? 0 : (nums[i]>0 ? 1 : -1);
        }

        sum.insert(sum.begin() , 0);
        sum.insert(sum.end() , 0);

        get_sum();

        get_hashmap();

        return f();
    }
};

int main()
{
    int n , x;
    vector<int> arr;
    scanf("%d" , &n);
    arr.clear();
    arr.assign(n , 0);

    for(int i=0 ; i<n ; i++)
    {
        scanf("%d" , &x);
        arr[i] = x;
    }

    Solution slt;
    cout << slt.longest_interval(arr) << endl;

    return 0;
}
