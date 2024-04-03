// 判断一个数 是否是 3 的倍数

#include<bits/stdc++.h>

using namespace std;

int MaxPowerOf3;

bool IsPowerOf3(int a)
{
    return (a>0)&&(MaxPowerOf3%a == 0);
}

int main()
{
    int times=0; // 在 int 范围内 3的幂的最大值
    for(int i=0 ; i<30 ; i++)
    {
        if(pow(3 , i) > INT_MAX)
        {
            times = i-1;
            break;
        }
    }

    MaxPowerOf3 = pow(3 , times);

    int a=0;
    scanf("%d" , &a);

    printf("%c" , IsPowerOf3(a) == true ? 'Y' : 'N');

    return 0;
}