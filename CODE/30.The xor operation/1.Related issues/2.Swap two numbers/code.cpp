// 交换两个数的值

#include<bits/stdc++.h>

using namespace std;

// 1）当 a 和 b 分别有两个存储空间时 没问题
// 2）当 a 和 b 共享同一个存储空间时 不安全（a = a ^ b ==> a = 0）
void Swap(int& a , int& b)
{
    // a：甲    b：乙
    a = a ^ b; // a = 甲 ^ 乙
    b = a ^ b; // b = 甲 ^ 乙 ^ 乙 == 甲
    a = a ^ b; // a = 甲 ^ 乙 ^ 甲 == 乙
}

int main()
{
    int a=0;
    int b=1;

    printf("a = %d , b = %d" , a , b);

    swap(a , b);

    printf("a = %d , b = %d" , a , b);

    return 0;
}