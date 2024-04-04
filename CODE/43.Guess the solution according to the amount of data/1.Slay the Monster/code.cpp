#include<bits/stdc++.h>
using namespace std;

vector<int> op; // operations
vector<int> bl; // blood_limit
int blood;      // sum of blood

class Slay_Monster
{
private:
    // 当做出决策时，要使用 j 位置所对应的技能 (i 位置表示这一步要选择的技能) , 所以要进行交换
    // 分别更新两个集合的元素
    void my_swap(int i , int j)
    {
        // 更新技能集合:
        int temp1 = op[i];
        op[i] = op[j];
        op[j] = temp1;
		
        // 更新血量阈值集合:
        int temp2 = bl[i];
        bl[i] = bl[j];
        bl[j] = temp2;

        return;
    }
    
private:
    // 函数功能：返回杀死怪兽 所使用的 最少的 技能数
    // 函数结束标志：怪物被杀死 blood <= 0
    // 假设有4个技能(A , B , C , D) , 来做写代码
    int f(int i)
    {   
        // 怪兽被杀死：
        // 下标：0 1 2 3 4
        // 下标：A B C D
        //               i
        if(blood <= 0)
        {
            return i; // 这里的 i 有两种含义：1.排序的位置排在了 i 位  2.目前释放技能的总数
        }
        else
        {
            // 怪兽没被杀死：
            // 1）技能数用 (已经释放 A->B->C 连招) 完了, 而没有杀死怪物
            // 下标：0 1 2 3 4
        	// 下标：A B C D
        	//              i
            if(i==op.size())
            {
                return INT_MAX; // 返回整数最大值表示：这一连招不能将怪兽杀死
            }
            // 2）技能还没有用完：
            else
            {   
                // 这里的 ans 取 INT_MAX 有两个原因：
                // 1.若当前决策下的所有连招都不能杀死怪物，则保持 INT_MAX 向上返回表示无解
                // 2.当遇到好的决策方法时，可以通过 min(INT_MAX , 好方法), 来直接锁定好方法, 即 ans = 好方法
                int ans=INT_MAX; // 使用的最少的技能数
                // INT_MAX：表示技能无效，为了让 ans 取得最小值, 先让 ans 表示一个超大的值
                
                // eg: 3个技能，已经放了一个 A , 现在可以选择 B or C or D 技能进行释放
                // 0   1 2 3 4
                // A | B C D
                //     i            i:还能使用哪些技能[i , op.size()-1]
                //       j            j:使用哪个技能
                // 分类讨论：用回溯的方法一个一个试：
                for(int j=i ; j<op.size() ; j++)
                {
                    // 决定使用 j 技能：因为后序技能的释放受之前决策的影响，修改 op 和 bl 的排列顺序
                    my_swap(i , j); // 当前技能集 和 血量阈值集合 表示 当前的决策
                    // 使用 C 技能，但是 C 技能被换到 B 技能位置上 ==> 使用 i 位置的技能 
                    // 0   1 2
                	// A | C B
                	//     i            i:还能使用哪些技能
                	//       j            j:使用哪个技能
                    
                    int blood_back = blood; // 血液的状态标记，便于回溯
                    blood -= blood<=(bl[i]) ? (2*op[i]) : (op[i]); // 当前使用 C 技能, 对怪兽造成伤害
                    ans = min(ans , f(i+1)); // 看看 C 技能释放之后, 剩下的所有种决策能否杀死怪兽, 并返回最优解
				
                    // 状态回溯过程:
                    // 将 op 和 bl 的顺序修改回来，进行下一种技能的选择, 下一步 j++ , 表示对 D 技能 进行释放
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
    int m; // m组测试数据
    scanf("%d" , &m);

    // eg:
    // 3 100
    // 10 20
    // 45 89
    // 5 40
    while(m--)
    {
        // 更新：
        op.clear();
        bl.clear();

        // 输入数据：
        int n=0; // 技能数
        scanf("%d" , &n); // 技能数
        scanf("%d" , &blood); // 怪兽血量
        for(int i=0 ; i<n ; i++) // 技能 | 血量阈值 详细参数
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