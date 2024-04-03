// 神奇的数字：
// https://leetcode.cn/problems/nth-magical-number/description/

#include<bits/stdc++.h>

using namespace std;

const int M = 1e9+7;
typedef long long ll;

class Magic_Number
{
private:
    ll N;

private:
    long gcd(int a , int b) // 默认 a >= b
    {
        return b==0 ? a : gcd(b , a%b);
    }

    long lcm(int a , int b) // 默认 a >= b
    {
        return ( ( a / gcd(a , b) ) * b );
    }

    int f(ll a , ll b) // 默认 a >= b
    {
        ll l = 0 , r = b * N; // 右边界：min(a , b) * N
        ll ans = 0;
        int lcmm = lcm(a , b);

        while(l <= r)
        {
            ll mid = (l+r+1)/2;

            // 看看 mid 及以前 有多少个 Magic_Number (能整除a的 + 能整除b的 - 能整除a也能整除b的)
            if(( (mid/a) + (mid/b) - (mid/lcmm) )  >= N)
            {
                ans = mid;
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }

        return (int)(ans%M);
    }

public:
    ll magic_number(ll n , ll a , ll b)
    {
        N = n;
        return f(max(a , b) , min(a , b));
    }
};


int main()
{
    Magic_Number mn;
    cout << mn.magic_number(1000000000 , 4000 , 4000);

    return 0;
}