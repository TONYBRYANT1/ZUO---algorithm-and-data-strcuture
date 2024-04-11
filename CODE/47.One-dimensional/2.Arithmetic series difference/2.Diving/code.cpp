#include<bits/stdc++.h>

using namespace std;

const int OFFSET = 3e4;

int n , m , v , x;

vector<int> ans;

void sett(int l , int r , int s , int e , int d)
{
    ans[l+OFFSET] += s;
    ans[l+1+OFFSET] += (d-s);
    ans[r+1+OFFSET] -= (e+d);
    ans[r+2+OFFSET] += e;
    return;
}

void diving()
{
    sett((x-3*v+1) , (x-2*v) , (1) , (v) , (1));
    sett((x-2*v+1) , (x) , (v-1) , (-v) , (-1));
    sett((x+1) , (x+2*v) , (-v+1) , (v) , (1));
    sett((x+2*v+1) , (x+3*v) , (v-1) , (0) , (-1));
    return;
}

void build()
{
    // 等差数列的差分受到起点的影响，一定要从起点开始求前缀和才正确
    for(int i=1 ; i<=(m+OFFSET) ; i++)
    {
        ans[i] += ans[i-1];
    }

    // 等差数列的差分受到起点的影响，一定要从起点开始求前缀和才正确
    for(int i=1 ; i<=(m+OFFSET) ; i++)
    {
        ans[i] += ans[i-1];
    }

    return;
}

int main()
{
    ans.clear();

    scanf("%d%d" , &n , &m);

    ans.assign((OFFSET + m + OFFSET) , 0);

    while(n--)
    {
        scanf("%d%d" , &v , &x);
        diving();
    }

    build();

    for(int i=(1+OFFSET) ; i<=(m+OFFSET) ; i++)
    {
        printf("%d " , ans[i]);
    }

    return 0;
}