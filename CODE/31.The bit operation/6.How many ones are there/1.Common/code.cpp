// 多少个 1

#include<bits/stdc++.h>

using namespace std;

typedef unsigned int ut;

ut RightOne(ut x)
{
    return x&(~x+1);
}   

int CountBit_1(ut x)
{
    int countt=0;
    while(x>0)
    {
        countt++;
        x -= RightOne(x);
    }
    return countt;
}

int main()
{
    ut a;
    cin >> a;
    printf("%d" , CountBit_1(a));
    return 0;
}