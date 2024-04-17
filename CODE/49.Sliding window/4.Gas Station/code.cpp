#include<bits/stdc++.h>

using namespace std;

class Solution 
{
private:   
    vector<int> rest;

public:
    int canCompleteCircuit(const vector<int>& gas, const vector<int>& cost) 
    {
        int n = gas.size();
        
        int sum=0 , len=0 , r=0;

        // l  : 窗口起始位置
        // r  : 即将进入窗口的位置
        // sum: 窗口值的和
        // len: 窗口长度
        // 
        // 时间复杂度：O(N):
        // l 最多走 n
        // r 最多走 2n-1
        for(int l=0 ; l<n ; l++)
        {
            // 只要还有油就一直走
            while(sum>=0)
            {
                // 走完了，返回 l
                if(len==n)
                {
                    return l;
                }
                // 0 1 2 3 4
                //   l
                // r : 即将进入窗口的位置，还没进窗口
                // ps: 一开始窗口长度为0，即将要进的位置与 l 相同
                r = (l+len)%n;
                len++;
                sum += (gas[r] - cost[r]);
            }

            len--;
            sum -= (gas[l] - cost[l]);
        }

        return -1;
    }
};