#include<bits/stdc++.h>
using namespace std;

const int Min = INT_MIN;
const int Max = INT_MAX;

// 1）位运算实现加法
//            a+b = a^b + (a&b<<1) // 等于 a+b(无进位) + a+b(进位信息)
//            ---------> 循环下去，直到进位信息为 0
//              a: 0 0 1 0 1 1  --> 11
//              b: 0 0 1 1 1 0  --> 14
//
//            a^b: 0 0 0 1 0 1 
//            a&b: 0 0 1 0 1 0   
//       (a&b<<1): 0 1 0 1 0 0 
//
//
// (a^b)^(a&b<<1): 0 1 0 0 0 1 --> x
// (a^b)&(a&b<<1): 0 0 0 1 0 0 --> y
//         (y<<1): 0 0 1 0 0 0 
//
//       x^(y<<1): 0 1 1 0 0 1
//       x&(y<<1): 0 0 0 0 0 0   
// (x^y)^(x&y<<1): 0 1 1 0 0 1  --> 25
int Addition(int a , int b)
{
    int ans=a;
    while(b!=0)
    {
        ans = a^b;      // ans = 无进位相加
        b = ((a&b)<<1); // b = 进位信息
        a = ans;
    }
    return ans;
}

// 2）相反数
// a的相反数 ~a+1
int Negative(int x)
{
    return Addition(~x , 1);
}

// 2.2）绝对值
int Absolute_Value(int x)
{
    if(x<0)
    {
        x = Negative(x);
    }
    return x;
}

// 3）减法：
// a-b = a+(-b)
int Subtraction(int a , int b)
{
    return Addition(a , Negative(b));
}

// 打印
void PrintBit(unsigned int x)
{
    for(int i=31 ; i>=0 ; i--)
    {
        printf("%d " , (x>>i)&1);
    }
    cout << endl;
}


// 模拟乘法算术过程
// 遍历
// 为了实现无符号右移，用 unsigned int
int Multiplication(int a , int b)
{
    unsigned int x = a , y = b;
    int ans=0;
    while(y!=0)
    {
        if((y&1) != 0)
        {
            ans = Addition(ans , x);
        }
        x <<= 1;
        y >>= 1; // 无符号右移
    }
    return ans;
}   

// 4.1）除法1
// 必须保证 a 和 b 都不是整数最小值(因为整数最小值 无法转成绝对值的形式)，返回 a 除以 b
int Division1(int a , int b)
{
    // 先转成非负状态
    int x = a<0 ? Negative(a) : a;
    int y = b<0 ? Negative(b) : b;
    int ans=0;
    // 判断 x >= y*2^31 吗
    // 判断 x >= y*2^30 吗
    // 但凡有一个，x要减去判断的值，继续判断
    for(int i=30 ; i>=0 ; i=Subtraction(i , 1)) // i--
    {
        // 判断 x > y*2^30次方吗
        // 如果写成 x > (y<<30) y会有溢出风险，可能挪到符号位上
        // 所以写成 (x>>30) > y
        if((x>>i)>=y) 
        {
            ans |= (1<<i);
            x = Subtraction(x , (y<<i));
        }
    }

    int select =  (a>0)^(b>0); // 同号为 0  异号为 1
    return select == 0 ? ans : Negative(ans);
}

// 4.2）除法2
// 存在INT_MIN
int Division2(int a , int b)
{
    // 1）都是INT_MIN
    if((a==Min) && (b==Min))
    {
        return 1;
    }

    // 2）b是INT_MIN
    if(b==Min)
    {
        return 0;
    }

    // 3）都不是INT_MIN
    if((a!=Min) && (b!=Min))
    {
        return Division1(a , b);
    }

    // 4.1）a是INT_MIN，且 b == 1 or -1
    if((a==Min) && (Absolute_Value(b)==1))
    {
        if(b==-1)
        {
            return Max;
        }
        else
        {
            return Min;
        }
        
    }

    // 4.2）a是INT_MIN，且 b != 1 or -1
    if((a==Min) && (Absolute_Value(b)!=1))
    {
        if(b>0)
        {
            return Division1(a+b , b)-1;
        }
        // b<0
        else
        {
            return Division1(a-b , b)+1;
        }
    }
    return 0;
}

int main()
{
    // int a , b;
    // scanf("%d%d" , &a , &b);
    // // cout << Add(a , b) << endl;
    // cout << Division2(a , b) << endl;
    // PrintBit(Division2(a , b));

    return 0;
}