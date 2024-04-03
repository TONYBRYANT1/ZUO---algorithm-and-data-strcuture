// 判断一个数是不是 2 的幂

// 方法：
// 0）如果这个数 > 0，就继续讨论
// 1）Brain Kernighan 算法 获得数值的最右侧的 1
// 2）如果这个数是 2 的幂，则这个数仅有一位是 1
// 3）将这个数 和 RightOne 作比较，判断是否相等

#include<bits/stdc++.h>

using namespace std;

unsigned int RightOne(int a)
{
    unsigned int b = (a)&(~a+1);
    printf("%d" , b);
    return b;
}

bool IsPowerOf2(int a)
{
    if((a > 0)&&((unsigned int)a==RightOne(a))) // 当有符号数和无符号数比较时，先将有符号数视为无符号数然后比较，无符号数视为非负数
    {
        return true;
    }
    else
    {
        return false;
    }

}

int main()
{
    int a=0;
    scanf("%d" , &a);
    if(IsPowerOf2(a))
    {
        cout << "Y" << endl;
    }
    else
    {
        cout << "N" << endl;
    }
    return 0;
}
