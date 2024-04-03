// 一个数是否是由连续的数累加而成(累加数>=2)

#include<bits/stdc++.h>
using namespace std;

class SumOfConsecutiveNumbers
{
private:
    vector<int> arr; // 存放累加数
private:
    bool f(int n)
    {
        int sum=0;
        for(int i=1 ; i<=n ; i++)
        {
            sum = i;
            arr.clear();
            arr.push_back(i);
            for(int j=i+1 ; j<=n ; j++)
            {
                // 累加数至少有2个:
                if((sum+j) > n)
                {
                    break; // 从 i 开始不行
                }
                else if((sum+j) == n)
                {
                    arr.push_back(j); // 从 i 开始可以
                    return true;
                }
                else // (sum+j) < n
                {
                    sum+=j; // 不够，继续加
                    arr.push_back(j);
                }
            }
        }

        return false;
    }   

public:
    pair<bool , vector<int>> socn(int n)
    {
        arr.clear();
        return make_pair(f(n) , arr);
    }
};

// 打表得规律：
//  1 : F : 
//  2 : F :
//  3 : T : 1 + 2
//  4 : F :
//  5 : T : 2 + 3
//  6 : T : 1 + 2 + 3
//  7 : T : 3 + 4
//  8 : F :
//  9 : T : 2 + 3 + 4
// 10 : T : 1 + 2 + 3 + 4
// 11 : T : 5 + 6
// 12 : T : 3 + 4 + 5
// 13 : T : 6 + 7
// 14 : T : 2 + 3 + 4 + 5
// 15 : T : 1 + 2 + 3 + 4 + 5
// 16 : F :
// 17 : T : 8 + 9
// 18 : T : 3 + 4 + 5 + 6
// 19 : T : 9 + 10
// 20 : T : 2 + 3 + 4 + 5 + 6

// 凡是 2 的幂都不能由连续的数累加而成(累加数>=2)
bool rule(int n)
{
    // 判断是否是 2 的幂：
    if((n & (n-1)) == 0) // 是 2 的幂
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    // 暴力得到规律：
    // SumOfConsecutiveNumbers SOCN;

    // for(int i=1 ; i<=20 ; i++)
    // {
    //     printf("%2d : %s : " , i , SOCN.socn(i).first == true ? "T" : "F");
    //     if(SOCN.socn(i).first == true)
    //     {
    //         for(int a=0 ; a<SOCN.socn(i).second.size() ; a++)
    //         {
    //             if(a <= SOCN.socn(i).second.size()-2)
    //             {   
    //                 printf("%d + " , SOCN.socn(i).second[a]);
    //             }
    //             else
    //             {
    //                 printf("%d\n" , SOCN.socn(i).second[a]);
    //             }
    //         }
    //     }
    //     else
    //     {
    //         printf("\n");
    //     }        
    // }

    // 规律函数：
//  1 : F ---> 2 的幂
//  2 : F ---> 2 的幂
//  3 : T
//  4 : F ---> 2 的幂
//  5 : T
//  6 : T
//  7 : T
//  8 : F ---> 2 的幂
//  9 : T
// 10 : T
// 11 : T
// 12 : T
// 13 : T
// 14 : T
// 15 : T
// 16 : F ---> 2 的幂
// 17 : T
// 18 : T
// 19 : T
// 20 : T
    for(int i=1 ; i<=20 ; i++)
    {
        printf("%2d : %s\n" , i , rule(i)==true ? "T" : "F");
    }


    return 0;
}