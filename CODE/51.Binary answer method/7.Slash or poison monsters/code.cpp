// 刀砍毒杀怪兽问题
// 怪兽的初始血量是一个整数hp，给出每一回合刀砍和毒杀的数值cuts和poisons
// 第i回合如果用刀砍，怪兽在这回合会直接损失cuts[i]的血，不再有后续效果
// 第i回合如果用毒杀，怪兽在这回合不会损失血量，但是之后每回合都损失poisons[i]的血量
// 并且你选择的所有毒杀效果，在之后的回合都会叠加
// 两个数组cuts、poisons，长度都是n，代表你一共可以进行n回合
// 每一回合你只能选择刀砍或者毒杀中的一个动作
// 如果你在n个回合内没有直接杀死怪兽，意味着你已经无法有新的行动了
// 但是怪兽如果有中毒效果的话，那么怪兽依然会在血量耗尽的那回合死掉
// 返回至少多少回合，怪兽会死掉
// 数据范围 : 
// 1 <= n <= 10^5
// 1 <= hp <= 10^9
// 1 <= cuts[i]、poisons[i] <= 10^9
// 本题来自真实大厂笔试，找不到测试链接，所以用对数器验证


// 本题理解：
// 1）当不知道用几回合杀死怪兽的情况下，每回合用 刀、毒 的手段时不确定的
// 2）当知道了具体要求几回合杀死怪兽后，可以明确当前两种手段对怪兽造成的伤害
#include<bits/stdc++.h>

using namespace std;

class Solution
{
private:
    // mid 回合能不能杀死怪兽
    int f(vector<int>& slash , vector<int>& poison , int hp , int limit)
    {
        // 具体回合数：
        int n = min(limit , slash.size());

        for(int i=0 , j=1 ; i<n ; i++ , j++)
        {
            // 有了具体回合数，就能将伤害回合化，
            int hurt = max((long long)slash[0] , (long long)(limit-j) * (long long)poison[i]);

            // 怪兽扣血：
            hp -= hurt;

            // 如果怪兽还活着，并且回合数没到limit，继续受到伤害
            if(hurt > 0)
            {
                ;
            }
            else
            {
                return true;
            }
        }

        return false;
    }

public:
    int Kill_Monster(vector<int>& slash , vector<int>& poison , int hp)
    {
        int n = slash.size();
        // 范围可以定大一点防止会出错：
        // 杀死怪兽所需要的回合的范围：[1 , hp+1] // hp+1：第hp回合怪兽死
        int l=0 , r=hp+1;
        int ans=0;

        while(l<=r)
        {
            int mid = l + ((r-l)>>1);

            // mid 回合能不能杀死怪兽
            // 1）mid 回合能杀死怪兽，记录答案，并看看用更少的 mid 回合能否杀死怪兽
            if(f(slash , poison , hp , mid))
            {
                ans = mid;
                r = mid-1;
            }
            // 2）mid 回合不能杀死怪兽，看看用更多的 mid 回合能否杀死怪兽
            else
            {
                l = mid+1;
            }
        }

        return ans;
    }
};

int main()
{
    return 0;
}
