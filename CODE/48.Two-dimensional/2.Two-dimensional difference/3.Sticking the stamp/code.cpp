#include<bits/stdc++.h>

using namespace std;

class Solution 
{
private:
    vector<vector<int>> g1; // 演示表格 ---> 看看那个位置可以贴邮票
    vector<vector<int>> g2; // 操作表格 ---> 贴完邮票后的效果实现
    int row , col; // 原表格的 行、列数
    int k=1; // 默认贴上邮票，数值+1
private:
    void matrix_build(vector<vector<int>>& matrix)
    {
        for(int i=1 ; i<=row ; i++)
        {
            for(int j=1 ; j<=col ; j++)
            {
                matrix[i][j] += matrix[i][j-1] + matrix[i-1][j] - matrix[i-1][j-1];
            }
        }
        return;
    }

    // (a , b) -> (c , d) 范围的所有值的和：
    int matrix_sum(vector<vector<int>>& matrix , const int& a , const int& b , const int& c , const int& d)
    {
        return matrix[c][d] - matrix[c][b-1] - matrix[a-1][d] + matrix[a-1][b-1];
    }

    // 在 g2 上贴邮票(差分的方式)： matrix_set - 意思相同
    void stick_stamp(vector<vector<int>>& matrix , const int& a , const int& b , const int& c , const int& d)
    {
        matrix[a][b] += k;
        matrix[c+1][b] -= k;
        matrix[a][d+1] -= k;
        matrix[c+1][d+1] += k;
        return;
    }

public:
    bool possibleToStamp(vector<vector<int>>& g , int h, int w) 
    {
        // 一、原表格的 行、列数：
        row = g.size();
        col = g[0].size();

        // 二、g1、g2 的初始化：
        // g1、g2 在 g 的基础上加上一圈 0，放置越界访问：
        // g: 
        //    行：[0 ... row-1]
        //    列：[0 ... col-1]
        //
        // g1、g2:
        //    行：[0 [1 ... row] row+1]
        //    列：[0 [1 ... col] col+1]
        g1.resize((row+2) , vector<int>((col+2) , 0));
        g2 = g1;
        for(int i=0 ; i<row ; i++)
        {
            for(int j=0 ; j<col ; j++)
            {
                g1[i+1][j+1] = g[i][j];
            }
        }

        // 三、开始遍历网格 g1，看看能不能贴邮票：
        
        // 1）为了方便知道 (a , b) -> (c , d) 范围的所有值的和是不是 0 
        // ---> 求 g1 的前缀和：
        matrix_build(g1);

        // 2）遍历网格：
        //  临界值计算：
        //      1）行临界值：(row - a_max + 1) = h ---> a_max = row + 1 - h
        //      2）列临界值：(col - b_max + 1) = w ---> b_max = col + 1 - w
        int c; // (c - a + 1) = h ---> c = h + a -1
        int d; // (d - b + 1) = w ---> d = w + b -1
        for(int a=1 ; a<=(row + 1 - h) ; a++)
        {
            for(int b=1 ; b<=(col + 1 - w) ; b++)
            {
                c = h + a -1 , d = w + b -1;
                if(matrix_sum(g1 , a , b , c , d) == 0)
                {
                    stick_stamp(g2 , a , b , c , d);
                }
            }
        }

        // 四、检查是否所值为 0 的位置都贴上了邮票：
        //
        // 方法一：直接下标对应
        //
        // 1）为了统一下标：将 初始表格 g 也加上一圈0
        //      1）加上左右两列：
        for(auto& row : g)
        {
            row.insert(row.begin() , 0);
            row.push_back(0);
        }
        //      2）加上上下两行：
        g.insert(g.begin() , vector<int>((col+2) , 0));
        g.push_back(vector<int>((col+2) , 0));

        // 2）将 g2 求前缀和，将贴上邮票的效果显现出来：
        matrix_build(g2);

        // 3）开始检查原数组 g 中所有值为 0 的元素，看看是否被贴上了邮票(g2 上相同位置 值为1)
        for(int i=1 ; i<=row ; i++)
        {
            for(int j=1 ; j<=col ; j++)
            {
                // g中元素值为 0 的位置，没被贴上邮票(g2 上相同位置的值也为0)
                if((g[i][j]==0) && (g2[i][j]==0))
                {
                    return false;
                }
            }
        }
        return true;

        // // 方法二：g没有加一圈0，下标对应要加1
        // //
        // matrix_build(g2);
        // for(int i=0 ; i<row ; i++)
        // {
        //     for(int j=0 ; j<col ; j++)
        //     {
        //         if((g[i][j]==0) && (g2[i+1][j+1]==0))
        //         {
        //             return false;
        //         }
        //     }
        // }
        // return true;

    }

};


int main()
{
    vector<vector<int>> arr = {
        {1 , 0 , 0 , 0},
        {1 , 0 , 0 , 0},
        {1 , 0 , 0 , 0},
        {1 , 0 , 0 , 0},
        {1 , 0 , 0 , 0}
    };

    Solution slt;
    cout << (slt.possibleToStamp(arr , 4 , 3) == true ? "TRUE" : "FALSE") << endl;
    
    return 0;
}