//               0     1     2     3     4     5     6     7     8     9
// one    floor: 0     0     s     s+d   s+2d  s+3d  s+4d  e     0     0
// second floor: 0     0     s     d     d     d     d     d     -e    0
// third  floor: 0     0     s     d-s   0     0     0     0     -e-d  e
//                           l     l+1                     r     r+1

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> ans;

int n , t , l , r , s , e , d;

void sett()
{
    ans[l] += s;
    ans[l+1] += (d-s);
    ans[r+1] -= (e+d);
    ans[r+2] += e;
}

void build()
{
    for(int i=1 ; i<=n+2 ; i++) // 可以写成 i<=n，不影响
    {
        ans[i] += ans[i-1];
    }

    for(int i=1 ; i<=n+2 ; i++) // 可以写成 i<=n，不影响
    {
        ans[i] += ans[i-1];
    }
}

ll find_max()
{
    ll maxx = ans[1];
    for(int i=2 ; i<=n ; i++)
    {
        maxx = max(maxx , ans[i]);
    }

    return maxx;
}

ll sum_xor()
{
    ll xorr = ans[1];
    for(int i=2 ; i<=n ; i++)
    {
        xorr ^= ans[i];
    }

    return xorr;
}

int main()
{
    scanf("%d%d" , &n , &t);

    ans.clear();
    ans.resize(n+3);

    while(t--)
    {
        scanf("%d%d%d%d" , &l , &r , &s , &e);
        d = (e-s) / (r-l);
        sett();
    }

    build();

    printf("%lld %lld\n" , sum_xor() , find_max());
    return 0;
}