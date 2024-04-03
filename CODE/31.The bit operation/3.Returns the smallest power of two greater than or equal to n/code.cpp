// 返回大于等于 n 的最小的 2 的幂

// 经过不断的右移和求或 使得 a 最左的 1 后全是 1

#include<bits/stdc++.h>

using namespace std;

int TheSmallestPowerOf2(int a)
{
    // 将数分为 3 类：
    // 1）小于等于 0 
    // 2）大于零 && 不是 2 的幂
    // 3）2 的幂
    if(a<=0)
    {
        return 1;
    }
    else
    {
        a--;
        a = a | a>>1;
        a = a | a>>2;
        a |= a>>4;
        a |= a>>8;
        a |= a>>16;

        a++;
        return a;
    }
    // 0 0 0 0 1 0 0 0 0 0 1 0 0 0 
    // 0 0 0 0 0 1 0 0 0 0 0 1 0 0      >>1
// ==> 0 0 0 0 1 1 0 0 0 0 1 1 0 0
    // 0 0 0 0 0 0 1 1 0 0 0 0 1 1      >>2
// ==> 0 0 0 0 1 1 1 1 0 0 1 1 1 1 
    // 0 0 0 0 0 0 0 0 1 1 1 1 0 0      >>4
// ==> 0 0 0 0 1 1 1 1 1 1 1 1 1 1
}

int main()
{
    int a=0;
    scanf("%d" , &a);
    cout << TheSmallestPowerOf2(a) << endl;

    return 0;
}