#include<bits/stdc++.h>

using namespace std;

class Solution 
{
private:
    int row; 
    int col;

private:
    void build(vector<vector<int>>& g)
    {
        for(int i=0 ; i<row ; i++)
        {
            for(int j=0 ; j<col ; j++)
            {
                g[i][j] += get(g , i , j-1) + get(g , i-1 , j) - get(g , i-1 , j-1);
            }
        }
        return;
    }

    // 越界访问：
    int get(vector<vector<int>>& g , int i , int j)
    {
        if((i<0) || (j<0) || (i>row) || (j>col))
        {
            return 0;
        }
        else
        {
            return g[i][j];
        }
    }

    // 区域和：
    int get_sum(vector<vector<int>>& g , int a , int b , int c , int d)
    {
        if((c < a) || (d < b))
        {
            return 0;;
        }
        else
        {
            return get(g , c , d) - get(g , c , b-1) - get(g , a-1 , d) + get(g , a-1 , b-1);
        }
    }

public:
    int largest1BorderedSquare(vector<vector<int>>& g) 
    {
        //前缀和化：
        row = g.size();
        col = g[0].size();
        build(g);

        // 如果数组都是零，返回0
        if(get_sum(g , 0 , 0 , row-1 , col-1) == 0)
        {
            return 0;
        }
        // 至少有长度为 1 的 正方形
        else
        {
            int ans = 1; // 正方形的长度
            // 遍历每一个正方形：
            // 先找到左上角点(a , b)
            for(int a=0 ; a<row ; a++)
            {
                for(int b=0 ; b<col ; b++)
                {
                    // 从长度为2的正方形开始看，k---边长
                    for(int c=a+ans , d=b+ans , k=ans+1 ; ( (c<row)&&(d<col) ) ; c++ , d++ , k++)
                    {
                        // 方案一：加特判
                            // // 特判：2x2正方形
                            // if(k==2)
                            // {
                            //     if(get_sum(g , a , b , c , d)==4)
                            //     {
                            //         ans = k;
                            //     }
                            // }
                            // // 长度大于2，从3开始：
                            // else
                            // {
                            //     if( (get_sum(g , a , b , c , d) - get_sum(g , a+1 , b+1 , c-1 , d-1)) == ((k-1)<<2))
                            //     {
                            //         ans = k;
                            //     }
                            // }
                        // 方案二：不加特判
                            if( (get_sum(g , a , b , c , d) - get_sum(g , a+1 , b+1 , c-1 , d-1)) == ((k-1)<<2))
                            {
                                ans = k;
                            }
                    }
                }
            }

            return pow(ans , 2);
        }
    }
};

