#include<bits/stdc++.h>

const int N = 3e4+10;

int arr[N] , help[32] , n , times;

using namespace std;

int NumberLessMTimes()
{
    //遍历一边数组 , 将所有数对应的二进制代码 每一位累加起来
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<32 ; j++)
        {
            help[j] += ((arr[i]>>j)&1);
        }
    }

    // 每一位凡是 %times != 0 的，都是受那一个 没有出现times次的 元素导致的
    // 让 ans 在这样的位上加 1，至于零，对位没有影响
    int ans=0;
    for(int i=0 ; i<32 ; i++)
    {
        if((help[i]%times) != 0)
        {
            ans = ans | (1<<i);
        }
    }

    return ans;
}

int main()
{
    scanf("%d" , &n);
    scanf("%d" , &times);

    for(int i=0 ; i<n ; i++)
    {
        scanf("%d" , &arr[i]);
    }

    cout << NumberLessMTimes() << endl;

    return 0;
}