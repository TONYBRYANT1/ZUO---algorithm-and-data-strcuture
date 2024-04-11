// 机器人跳跃问题：

// 题目分析：
// 1）机器人有一定的能量，要想跳过前方的所有障碍，所需能量的最小值

// 2）能找到一种 (正/负)相关 的相关关系：
//    机器人所固有的能量越高，越能越过前方障碍

// 3）固有能量 和 能否越过障碍 之间的关系 的证明：
//    eg: 机器人名字(能量)、柱高：value
//        两个机器人：A(x) 、B(y) (x < y)

//    1） 遇到小于或等于自己能量的柱子：高能量机器人更具优势
//        value <= x < y：
//        对于 A：能量增幅(A_UP) 为 (x - value)
//        对于 B：能量增幅(B_UP) 为 (y - value)
//        明显：B_UP > A_UP

//    2） 遇到大于等于自己能量的柱子：高能量机器人更具优势
//        x < y <= value：
//        对于 A：能量减幅(A_DOWN) 为 (value - x)
//        对于 B：能量减幅(B_DOWN) 为 (value - y)
//        明显：A_DOWN > B_DOWN

//    3） 遇到 A 、B 机器人能量中间的柱子：高能量机器人更具优势
//        x < value < y：
//        对于 A：能量减幅(A_DOWN) 为 (value - x)
//        对于 B：能量增幅(B_UP) 为 (value - y)
//        明显：高能量机器人能量增加，低能量机器人能量减少

#include<bits/stdc++.h>

using namespace std;

// 看看以当前能量：energy，能否越过前方所有柱子
bool f(int energy , const vector<int>& pillars , int maxx)
{
    for(const auto& e : pillars)
    {
        // 遇到小于等于自己能量的柱子：能量增加
        if(e<= energy)
        {
            energy += (energy - e);
        }
        // 遇到大于自己能量的柱子：能量减少
        else
        {
            energy -= (e - energy);
        }

        // 合理剪枝：当某阶段能量大于最高柱子时，一定能够能通过，不用再计算
        if(energy >= maxx)
        {
            return true;
        }

        // 合理剪枝的必要性：
        // eg: 1 1 1 ... 1 1   1 
        //     0 1 2 ... n n+1 n+2
        // 依次跳过这些柱子的能量变化(energy = 2)：
        // energy + 1 + 2 + 4 + 8 + ... 
        // energy 以 2 的指数形式增加，不出几个柱子就会导致 energy 的值超过 long long 类型
        //所以一定要剪枝

        // 合理剪枝：当某阶段的能量小于0，一定不能够通过前方的所有柱子，不用再计算
        if(energy < 0)
        {
            return false;
        }

        // 如果能量：0 < energy <= max(pillars[i]) ，继续计算，正常跳下去
    }

    // 0 < energy <= max(pillars[i])
    // 通过了所有柱子，返回true
    return true;
}

int main()
{
    int n=0;
    vector<int> pillars;
    pillars.clear();
    scanf("%d" , &n);

    for(int i=0 ; i<n ; i++)
    {
        int x;
        scanf("%d" , &x);
        pillars.push_back(x);
    }

    // 能量值范围 [0 , max(pillars[i])]
    int maxx = pillars[0];
    for(const auto& e : pillars)
    {
        maxx = max(maxx , e);
    }

    int l=0 , r = maxx;
    int ans=0;

    // 进行二分
    while(l<=r)
    {
        // 防止溢出的一种写法：
        int mid = l + ((r-l)>>1);

        // 看看此时的 energy 能否通过前方所有柱子
        // 如果能，记录答案，并想能量值小的方向看，看看还有没有更小的能过通过所有柱子的答案
        if(f(mid , pillars , maxx))
        {
            ans = mid;
            r = mid - 1;
        }
        // 如果不能通过所有柱子，向能量稍微大一点的方向看
        else
        {
            l = mid+1;
        }
    }

    cout << ans << endl;

    return 0;
}