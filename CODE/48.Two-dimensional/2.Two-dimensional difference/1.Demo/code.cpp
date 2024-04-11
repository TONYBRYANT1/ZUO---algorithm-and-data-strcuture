// 一、记得在外围添加一圈0，差分可能会导致越界访问
//
// 二、初始模板一定要是全零，将初始数据以差分的形式添加，不能直接添加，会出错：
// 1）我们的目的是为了通过 差分--->前缀和 的方式获得一个范围上的 加值操作
// 2）求前缀和之前的过程都是构造差分的过程
//
// 3）错误看法：(单看初始数组)
//       如果将 初始数据 作为 差分过程 直接放入数组，那么就单看 初始数据 变成 前缀和 后就已经改变了
// 
// 4）正确看法：(单看初始数组)
//       要将 初始数据 看做 前缀和 ，在 全零数组上做出相应的差分操作，最后在求前缀和时变成原数组
// 5）eg:
//         目的：       操作：
//      ------------------------
//      |   原数组 ---> 差分0   |
//      |   操作1  ---> 差分1   |
//      |   操作2  ---> 差分2   |
//      |          ...         |
//      |                      |
//      |   操作n  ---> 差分n   |
//      ------------------------
// 操作：                                 目的：
// ==> (差分0 + 差分1 + 差分2 + ... 差分n) ---> (原数组 + 操作1 + 操作2 + 操作n)
//
// 详细看 86~92 行

// 添加一个数的差分：
//
//      -------------------
//      |(a,b)+k          |(a,d+1)-k
//      |                 |
//      |                 |
//      |            (c,d)|
//      |-----------------|
//       (c+1,b)-k          (c+1,d+1)+k
//

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<vector<ll>> metrix;
vector<ll> arr;

ll n , m , q;

// 差分：
void metrix_set(ll a , ll b , ll c , ll d , ll e)
{
    metrix[a][b] += e;
    metrix[c+1][b] -= e;
    metrix[a][d+1] -= e;
    metrix[c+1][d+1] += e;
    return;
}

// 前缀和：
void metrix_build()
{
    for(ll i=1 ; i<=n ; i++)
    {
        for(ll j=1 ; j<=m ; j++)
        {
            // 自己 + 左 + 上 - 左上
            metrix[i][j] += metrix[i][j-1] + metrix[i-1][j] - metrix[i-1][j-1];
        }
    }

    return;
}

int main()
{
    metrix.clear();
    scanf("%lld%lld%lld" , &n , &m , &q);
    fflush(stdin);

    metrix.resize((n+2) , vector<ll>((m+2) , 0));

    // n行 [0...n-1] --> [1...n]
    for(ll i=1 ; i<=n ; i++)
    {
        // m列 [0...m-1] --> [1...m]
        for(ll j=1 ; j<=m ; j++)
        {
            // scanf("%lld" , &metrix[i][j]);       ----------------> 初始模板一定要是全零，将初始数据以差分的形式添加，不能直接添加，会出错
            ll x;
            scanf("%lld" , &x);
            metrix_set(i , j , i , j , x);
        }
    }

    while(q--)
    {
        ll a , b , c , d , e;
        scanf("%lld%lld%lld%lld%lld" , &a , &b , &c , &d , &e);
        metrix_set(a , b , c , d , e);
    }

    metrix_build();

    for(ll i=1 ; i<=n ; i++)
    {
        for(ll j=1 ; j<=m ; j++)
        {
            printf("%lld " , metrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}