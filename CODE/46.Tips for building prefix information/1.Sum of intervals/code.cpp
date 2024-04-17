#include<bits/stdc++.h>

using namespace std;

class NumArray 
{
private:
    vector<int> sum;
public:
    NumArray(vector<int>& nums) 
    {
        sum = nums;
        sum.insert(sum.begin() , 0);
        sum.insert(sum.end() , 0);

        for(int i=1 ; i<(sum.size()-1) ; i++)
        {
            sum[i] += sum[i-1];
        }
    }
    
    int sumRange(int left, int right) 
    {
        return sum[right+1] - sum[left];
    }
};