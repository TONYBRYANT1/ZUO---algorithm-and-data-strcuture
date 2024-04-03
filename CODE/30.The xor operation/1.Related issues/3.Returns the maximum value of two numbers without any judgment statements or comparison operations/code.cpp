// 不用任何判断语句和比较操作，返回两个数的最大值

#include<bits/stdc++.h>

using namespace std;

int Flip(int a)
{
    return a^1;
}

// 返回 符号位
// 负数  返回 1
// 非负数 返回 0
int Sign(int n)
{
    // [31 30 29 ... 3 2 1 0]
    // 将 1号位 挪到 0号位 需要 >>1
    // 将 31号位 挪到 0号位 需要 >>31
    return (1 & (n>>31));
}

// 可能会溢出导致问题
int GetMax1(int a , int b)
{
    int c = a - b;
    int Return_B = Sign(c);
    int Return_A = Flip(Return_B); // Return_B=1 ==> Return_A=0 or Return_B=0 ==> Return_A=1;
    // c>0 ：Return_B=0 Return_A=1 return a
    // c<0 ：Return_B=1 Return_A=0 return b
    return a*Return_A + b*Return_B;
}

// 安全函数
int GetMax2(int a , int b)
{
    int c = a - b;
    // 1）a、b 同号 ==> c有效 ==> (c>0 ==> return a) or (c<0 ==> return b)
    // 2）a、b 异号 ==> c无效 ==> (Sign_A == 0 ==> return a) or (Sign_B == 0 ==> return b)
    int Sign_a = Sign(a);
    int Sign_b = Sign(b);
    int Sign_c = Sign(c);

    int Same_ab = Flip(Sign_a ^ Sign_b); // 同号 1
    int Diff_ab = Flip(Same_ab); // 异号 0

    int Return_A = Same_ab * Flip(Sign_c) + Diff_ab * Flip(Sign_a);
    int Return_B = Flip(Return_A);

    return a*Return_A + b*Return_B;
}


int main()
{
    int a=56 , b=23;
    cout << GetMax2(a , b) << endl;
    return 0;
}