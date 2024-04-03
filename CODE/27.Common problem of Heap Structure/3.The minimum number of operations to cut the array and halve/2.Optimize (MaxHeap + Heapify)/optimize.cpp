// long（怕 double 精度不够，将元素扩大 <<20 ，认为增加精度） + customize MaxHeap

// Time Complexity：O(N * log2(N))

// Space Complexity：O(N)

#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+10;

class Solution 
{
public:
    long MaxHeap[N];
    int size=0;
public: 
    void swap(int x , int y)
    {
        long temp = MaxHeap[x];
        MaxHeap[x] = MaxHeap[y];
        MaxHeap[y] = temp;
    }

    // Time Complexity：O(N) = N/2 * 1 + N/4 * 2 + N/8 * 3 + ... + 1 * log2(N)
    void Heapify(int i)
    {
        int left = (i<<1) + 1;
        while(left <= size-1)
        {
            int right = left + 1;
            int maxx = (right <= size-1)&&(MaxHeap[right] > MaxHeap[left]) ? right : left;
            maxx = (MaxHeap[maxx] > MaxHeap[i]) ? maxx : i;
            if(maxx == i)
            {
                break;
            }
            else
            {
                swap(i , maxx);
                i = maxx;
                left = (i<<1) + 1;
            }
        }
        return;
    }

    int HalveArray(vector<int>& nums) 
    {   
        long sum=0;
        size = nums.size();
        int i = size-1;

        // Time Complexity：O(N)
        for(auto e : nums)
        {
            MaxHeap[i] = ((long)e) << 20;
            sum += MaxHeap[i];
            Heapify(i);
            i--;
        }

        sum /= 2;
        long goal=0;
        int ans=0;
        
        // Time Complexity：O(N * log2(N))
        while(goal < sum)
        {
            MaxHeap[0] /= 2;
            goal += MaxHeap[0];
            Heapify(0);
            ans++;
        }
        
        return ans;
    }
    
};


int main()
{
    vector<int> v;
    int n=0 , x=0;
    scanf("%d" , &n);
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d" , &x);
        v.push_back(x);
    }

    Solution s;

    printf("%d" , s.HalveArray(v));

    return 0;
}