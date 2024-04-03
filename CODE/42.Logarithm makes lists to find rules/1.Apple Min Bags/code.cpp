// 对数器打表找规律：

// 有装下8个苹果的袋子、装下6个苹果的袋子，一定要保证买苹果时所有使用的袋子都装满
// 对于无法装满所有袋子的方案不予考虑，给定n个苹果，返回至少要多少个袋子
// 如果不存在每个袋子都装满的方案返回-1

#include<bits/stdc++.h>
using namespace std;

// 打表：
class Minbags
{
private:
    int f(int rest)
    {
        // 说明装不满
        if(rest < 0)
        {
            return INT_MAX; 
        }

        // 说明装满了，不需要袋子了
        if(rest == 0)
        {
            return 0;
        }

        // 用规格为 6 的袋子装：
        int p1 = f(rest - 6);
        // 用规格为 8 的袋子装：
        int p2 = f(rest - 8);

        // 收集答案：INT
        p1 += p1 == INT_MAX ? 0 : 1;
        p2 += p2 == INT_MAX ? 0 : 1;

        // 向上一级返回答案：
        return min(p1 , p2);
    }

public: 
    int bags(int apples)
    {
        int ans = f(apples);
        return ans == INT_MAX ? -1 : ans;
    }
};


//  1: -1
//  2: -1
//  3: -1
//  4: -1
//  5: -1
//  6:  1
//  7: -1
//  8:  1
//  9: -1
// 10: -1
// 11: -1
// 12:  2
// 13: -1
// 14:  2
// 15: -1
// 16:  2
// 17: -1
// 18:  3 ---> 规律开始 周期 0   -------
// 19: -1                             |
// 20:  3                             |
// 21: -1                             8
// 22:  3                             
// 23: -1                             |
// 24:  3                             |
// 25: -1 ---> 规律结束 周期 0   -------
// 26:  4 ---> 规律开始 周期 1
// 27: -1
// 28:  4
// 29: -1
// 30:  4
// 31: -1
// 32:  4
// 33: -1 ---> 规律结束 周期 1
// 34:  5 ---> 规律开始 周期 2
// 35: -1
// 36:  5
// 37: -1
// 38:  5
// 39: -1
// 40:  5
// 41: -1 ---> 规律结束 周期 2
    
// 开始写函数：
void f(int apples)
{
    // 排除基数：
    if((apples%2) == 1)
    {
        return;
    }

    // 筛选偶数：

    // 前 17:
    if(apples < 18)
    {
        // 1个袋子：
        if((apples == 6) || (apples == 8))
        {
            printf("%d : 1\n" , apples);
            return;
        }

        // 2个袋子：
        if((apples == 12) || (apples == 14) || (apples == 16))
        {
            printf("%d : 2\n" , apples);
            return;
        }
    }
    // >= 18
    else
    {
        // 看看是哪一层：
        // eg: 第一层：18 ~ 25
        // (apples-18) ---> 归零
        // (apples-18)%8 ---> 看看是哪一层
        printf("%d : %d\n" , apples , ((apples-18)/8+3));
        return;
    }

    return;
}

int main()
{
    // Minbags mb;
    // // 打表：
    // for(int i=1 ; i<=100 ; i++)
    // {
    //     printf("%2d: %2d\n" , i , mb.bags(i));
    // }

    for(int i=1 ; i<=100 ; i++)
    {
        f(i);
    }

    
    return 0;
}