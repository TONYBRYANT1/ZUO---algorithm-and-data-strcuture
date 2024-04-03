#include<bits/stdc++.h>
using namespace std;

vector<int> op; // operations
vector<int> bl; // blood_limit
int blood;      // sum of blood

class Slay_Monster
{
private:
    void my_swap(int i , int j)
    {
        int temp1 = op[i];
        op[i] = op[j];
        op[j] = temp1;

        int temp2 = bl[i];
        bl[i] = bl[j];
        bl[j] = temp2;

        return;
    }
private:
    // 函数功能：返回杀死怪兽 所使用的 最少的 技能数
    // 函数结束标志：怪物被杀死 blood <= 0
    // 假设有3个技能
    int f(int i)
    {   
        // 怪兽被杀死：
        if(blood <= 0)
        {
            return i;
        }
        else
        {
            // 怪兽没被杀死：
            // 1）技能数用完了
            if(i==op.size())
            {
                return INT_MAX; // 返回整数最大值表示：这一连招不能将怪兽杀死
            }
            // 2）技能还没有用完：
            else
            {   
                int ans=INT_MAX; // 使用的最少的技能数
                
                // eg: 3个技能，已经放了一个
                // 0   1 2
                // a | b c
                //     i            i:还能使用哪些技能
                //     j            j:使用哪个技能
                // 分类讨论：用回溯的方法一个一个试：
                for(int j=i ; j<op.size() ; j++)
                {
                    // 决定使用 j 技能：因为后序技能的释放受之前决策的影响，修改 op&bl 的排列顺序
                    my_swap(i , j);
                    // 使用 j技能，但是 j技能被换到 i技能位置上 ==> 使用 i技能 ：
                    int blood_back = blood; // 血液的状态回溯
                    blood -= blood<=(bl[i]) ? (2*op[i]) : (op[i]);
                    ans = min(ans , f(i+1)); // 如果后续连招不能杀死怪物，返回 INT_MAX

                    // 将 op&bl 的顺序修改回来，进行下一种技能的选择
                    my_swap(i , j);
                    blood = blood_back;
                }

                return ans; // 返回所用的最少的技能数
            }
        }


    }
public:
    int Min_Op()
    {
        return f(0)==INT_MAX ? -1 : f(0); // 从第 0 个技能开始考虑
    }
};

int main()
{
    int n; // n组测试数据
    scanf("%d" , &n);

    // eg:
    // 3 100
    // 10 20
    // 45 89
    // 5 40
    while(n--)
    {
        // 更新：
        op.clear();
        bl.clear();

        // 输入数据：
        int m=0; // 技能数
        scanf("%d" , &m); // 技能数
        scanf("%d" , &blood); // 怪兽血量
        for(int i=0 ; i<m ; i++) // 技能 | 血量阈值 详细参数
        {
            int x=0; // 技能伤害
            int y=0; // 血量阈值
            scanf("%d%d" , &x , &y);
            op.push_back(x);
            bl.push_back(y);
        }

        // 计算杀死怪兽的最少技能数：
        Slay_Monster sm;
        printf("%d\n" , sm.Min_Op());
    }

    return 0;
}