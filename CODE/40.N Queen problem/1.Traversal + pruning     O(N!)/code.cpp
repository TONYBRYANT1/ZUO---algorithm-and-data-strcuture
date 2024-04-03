// 用数组表示路径的方法（经典、常数时间慢，不推荐）
// 1）记录之前每一行的皇后放在了什么列
// 2）来到第i行的时候，可以根据0..i-1行皇后的位置，判断能放哪些列
// 3）把能放的列都尝试一遍，每次尝试修改路径数组表示当前的决策，后续返回的答案都累加返回

#include<bits/stdc++.h>
using namespace std;

class N_Queen
{
private:
    // 问题规模：
    int N;
    // 记录当前棋局：
    vector<vector<int>> map;

private:   
    // 检查第 i 层的选择，会不会收到 [0...i-1] 层的干扰
    bool check1(int i , int j , vector<int> path)
    {
        // [0...i-1] 层
        for(int k=0 ; k<i ; k++)
        {
            // 列校验：         对角线校验：
            if((j==path[k]) || (abs(i-k)==abs(j-path[k])))
            {
                return false;
            }
        }
        
        return true;
    }

    // 得到 path[0...i-1] 层的选择之后，在第 i 层的每一列进行尝试
    int f1(int i , vector<int> path)
    {
        // 问题规模 N
        // 如果能走到第 N 层，则此方法有效(有效层数 0...N-1)
        if(i==N)
        {
            // 记录当前棋局：
            map.push_back(path);
            return 1;
        }

        // 现在轮到第 i 层进行尝试
        int ans=0;
        // 尝试每一列：
        for(int j=0 ; j<N ; j++)
        {
            // 看看这一列的选择会不会受到 path[0...i-1] 的干扰
            if(check1(i , j , path))
            {
                path[i] = j;
                ans += f1(i+1 , path);
            }
        }

        // 返回：在 path[0...i-1] 已经确定的情况之下，能有多少种出路
        return ans;
    }

public: 
    pair< int , vector<vector<int>> > n_queen(int n)
    {        
        // 记录当前棋局：
        map.clear();

        // 问题规模：
        N = n;

        // 答案：
        int kinds = 0;
        // 特判：
        if(N<1)
        {
            return make_pair(kinds , map);
        }

        // 每种局势的记录：
        vector<int> path(N , 0);

        // 共有多少种棋局：
        kinds = f1(0 , path);

        return make_pair(kinds , map);
    }
};


int main()
{
    int n;
    scanf("%d" , &n);
    N_Queen nq;

    pair<int , vector<vector<int>>> package = nq.n_queen(n);

    cout << "共有 " << package.first << " 种棋局：" << endl;
    cout << endl;  

    int r = package.first;

    int m = 0;

    while(r--)
    {   
        printf("第 %d 种棋局：\n" , m);
        printf(" \\ ");
        for(int i=0 ; i<n ; i++)
        {
            printf("%d " , i);
        }
        cout << endl;
        for(int i=0 ; i<n ; i++)
        {
            printf("%d  " , i);
            for(int j=0 ; j<n ; j++)
            {
                if(j == package.second[m][i])
                {
                    printf("%c " , '*');
                }
                else
                {
                    printf("  ");
                }
            }
            cout << endl;
        }
        cout << endl;
        m++;
    }

    return 0;
}