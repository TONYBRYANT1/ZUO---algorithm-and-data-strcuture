// 求区间和为 k 的最长区间长度
// 解法：
// eg: 
// 遍历每一个元素，以当前元素为区间末尾元素，来求区间和为 k 的最长区间
// 假设：index: [0 .. i . x] [x+1 .... j] 
// sum[x+1 ... j] = k 、sum[0 ... j] = sum ==> sum[0 ... x] = sum - k
// 要想要[x+1 ... j]区间最长
// 也就是求最早让 [0 ... x] 区间 或 区间内部[0 ... i] 的前缀和为 sum-k 的位置
// 如果最早位置为 i，则最长区间长度为 (j - (i+1) + 1) = (j - i)

#include<bits/stdc++.h>

using namespace std;

class Solution
{
private:
    vector<int> sum;
    unordered_map<int , int> hashmap;
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
        hashmap.insert({0 , 0}); // 特殊

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
        int length=0 , search=0 , l=0;
        for(int r=1 ; r<=n ; r++)
        {
            search = sum[r] - aim;
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
    int longest_interval(const vector<int>& arr , int k)
    {
        aim = k;
        n = arr.size();
        sum = arr;
        sum.insert(sum.begin() , 0);
        sum.insert(sum.end() , 0);

        get_sum();

        get_hashmap();

        return f();
    }
};


int main()
{
    vector<int> arr;
    arr.clear();
    int n , m , k , x;
    scanf("%d%d" , &n , &k);
    m = n;
    arr.assign(m , 0);

    for(int i=0 ; i<n ; i++)
    {
        scanf("%d" , &x);
        arr[i] = x;
    }

    Solution slt;
    cout << slt.longest_interval(arr , k) << endl;

    return 0;
}
