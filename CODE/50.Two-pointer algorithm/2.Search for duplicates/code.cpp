// 快慢指针 fast and slow

// [1,3,4,2,2]
//  0 1 2 3 4
// [0] --> [1] --> [3] --> [2] --> [4] ---
//                          ^            |   
//                          |            v
//                          -------<------

#include<bits/stdc++.h>

using namespace std;

class Solution 
{
public:
    int findDuplicate(vector<int>& nums) 
    {
        int n = nums.size();

        // 数组长度为 0 or 1
        if((n==0) || (n==1))
        {
            return -1;
        }
        // 数组长度 大于等于 2
        else
        {   
            // 快慢指针
            int fast = nums[nums[0]];
            int slow = nums[0];

            // 直到 fast 和 slow 相遇
            while(fast != slow)
            {
                fast = nums[nums[fast]];
                slow = nums[slow];
            }

            // fast 回到头结点
            fast = 0;
            
            // fast 步长为 1
            while(fast != slow)
            {
                fast = nums[fast];
                slow = nums[slow];  
            }

            // 直到再相遇
            return fast;
        }
    }
};

int main()
{
    vector<int> arr = {3 , 1 , 3 , 4 , 2};

    Solution slt;
    cout << slt.findDuplicate(arr);
    
    return 0;
}