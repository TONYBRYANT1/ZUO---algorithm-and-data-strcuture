// 最小供暖距离：
// 让房屋选择最合适的供暖器

// 两点注意：
// 当一个房屋和两个供暖器的距离相等时，选择下一个供暖器
// 1）因为后面的房屋也要选择供暖器，方便后面的房屋选择
// 2）多个供暖器肯能同时出现在一个地方，如果不选择下一个供暖器
//    会导致永远锁死在之前重复的供暖器上，导致无法正确的选择后面的供暖器
//    eg：
//          houses:       10
//          heaters:    3 3 3 3      7
//    会永远锁死在位置为 3 的供暖器上，导致无法选中 7 位置的供暖器

#include<bits/stdc++.h>

using namespace std;

class Solution 
{
private:
    int n1; // 房间数数量
    int n2; // 供暖器数量
private:
    class MyComparator
    {
    public:
        bool operator() (const int& a , const int& b) const
        {
            return a < b;
        }
    };
    
private:
    // 合适的供暖器：
    bool suit(vector<int>& houses, vector<int>& heaters , const int& l , const int& r)
    {
        // 最后一个供暖器，不选也得选：
        if(r==(n2-1))
        {
            return true;
        }
        
        // 下一个供暖器和房屋等距离 or 下一个房屋更近
        // 不合适
        if((abs(houses[l]-heaters[r+1])) <= (abs(houses[l]-heaters[r])))
        {
            return false;
        }

        return true;
    }

public:
    int findRadius(vector<int>& houses, vector<int>& heaters) 
    {
        // 房屋 和 供暖器 先排序：
        sort(houses.begin() , houses.end() , MyComparator());
        sort(heaters.begin() , heaters.end() , MyComparator());
        // 让房屋选择合适的供暖器具：
        int ans=0;
        n1 = houses.size();
        n2 = heaters.size();
        int l=0 , r=0; // l-房屋  r-供暖器
        for( ; l<n ; l++)
        {
            // 当此供暖器不合适时，更换下一个供暖器
            while(!suit(houses , heaters , l , r))
            {
                r++;
            }

            ans = max(ans , abs(houses[l]-heaters[r]));
        }

        return ans;
    }
};