#include<bits/stdc++.h>

using namespace std;

// 2 4 5 9 8 7 3 1 2
// 0 1 2 3 4 5 6 7 8
// ^ ^             ^
// | |             |
// e o            send

class Solution 
{
private:
    int odd , even , send;

private:
    void swap(vector<int>& nums , int i , int j)
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        return;
    }

public:
    vector<int> sortArrayByParityII(vector<int>& nums) 
    {
        int n = nums.size();

        for(odd=1 , even=0 , send=(n-1); ( (odd<n) && (even<n) ) ; )
        {
            // nums[send] 为 偶
            if( (nums[send] & 1)==0 )
            {
                swap(nums , even , send);
                even+=2;
            }
            // nums[send] 为 基
            else
            {
                swap(nums , odd , send);
                odd+=2;
            }
        }

        return nums;
    }
};