// 好串：

// 定义：有一个字符串，如果这个字符串中有且仅有一个子串为长度大于等于2的回文串，
//       则该字符串是好串

#include<bits/stdc++.h>
using namespace std;

class GoodString
{
private:
    int N; // 问题规模

private:
    // 函数功能：是否是回文串
    bool is_palindromic_string(int j , int k , char* path)
    {
        while(j<=k)
        {
            if(path[j] == path[k])
            {
                j++;
                k--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }


    // 长度为 N 的，由 'r'、'e'、'd' 组成的字符串，有多少个好串
    // eg: length = 5
    // 0 1 2 3 4 5 
    // r e d r e
    //           ^
    //           i
    int f(int i , char* path)
    {   
        // eg: length = 5
        // 0 1 2 3 4 5 
        // r e d r e
        // ^
        // i
        // 长度为 N 的字符串已经成功生成，开始判断是不是好串
        if(i == N)
        {
            int sum = 0; // 回文子串计数器
            // 遍历每一个长度大于等于2的子串
            for(int j=0 ; j<i ; j++)
            {
                for(int k=j+1 ; k<i ; k++)
                {
                    if(is_palindromic_string(j , k , path))
                    {
                        sum++;
                    }
                    // 回文子串数量大于1 , 不是好串，直接返回
                    if(sum > 1)
                    {
                        return 0;
                    }
                }
            }
            return sum; // sum[0 , 1]  0->不是好串 1->好串
        }
        //
        // 还没有生成长度为 N 的字符串
        // eg: length = 5
        // 0 1 2 3 4 5 
        // r e d r e
        //         ^
        //         i
        else
        {
            // 假设在选最后一个，前 path[0...N-2]已经做出决策
            // 任务是返回在当前做出决策的情况之下，能有几种好串
            int ans=0; // 好串收集器
            // 决策1
            path[i] = 'r';
            ans += f(i+1 , path);
            // 决策2
            path[i] = 'e';
            ans += f(i+1 , path);
            // 决策3
            path[i] = 'd';
            ans += f(i+1 , path);

            return ans;
        }
    }
public:
    int goodstring(int n)
    {
        N = n;
        char path[100];
        return f(0 , path); // 从 path[0] 开始
    }
};

// 打表找规律：
//  1 :   0
//  2 :   3
//  3 :  18
//  4 :  30 + 6
//  5 :  36 + 6
//  6 :  42 + 6
//  7 :  48 + 6
//  8 :  54 + 6
//  9 :  60 + 6
// 10 :  66 + 6
// 11 :  72 + 6
// 12 :  78 + 6
// 13 :  84 + 6
// 14 :  90 + 6
// 15 :  96 + 6
// 16 : 102 + 6
// 17 : 108 + 6

void rule(int n)
{
    int sum=0;
    for(int i=1 ; i<=n ; i++)
    {
        if(i==1)
        {
            sum = 0;
        }
        else if(i==2)
        {
            sum=3;
        }
        else if(i==3)
        {
            sum = 18;
        }
        else
        {
            sum = 30+(i-4)*6;
        }
        printf("%2d : %3d\n" , i , sum);
    }
    return;
}

int main()
{
    // 找规律：
    // GoodString gs;

    // for(int i=1 ; i<20 ; i++)
    // {
    //     printf("%2d : %3d\n" , i , gs.goodstring(i));
    // }

    // 根据规律写函数：
    rule(20);
    
    return 0;
}