// 超级回文数：
// 1）概念：
// 如果一个正整数自身是回文数，而且它也是一个回文数的平方，那么我们称这个数为超级回文数。
//
// 2）要求：
// 1 <= len(L) <= 18
// 1 <= len(R) <= 18
// L 和 R 是表示 [1, 10^18) 范围的整数的字符串。
// int(L) <= int(R)
//
// 3）做法：
//    1）range[L , R] 范围很大 问题规模：1e18，很大决不能一个一个找
//    2）范围缩小：先在 range[根号L , 根号R] 中找 回文数字，再将这些回文数字平方，看看是不是回文数字
//    3）范围再缩小：先找一半的数字，再将它扩成回文数字(基扩展 & 偶扩展)，咱判断在不在 range[根号L , 根号R] 范围内

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

class Super_Palindromes_In_Range
{
private:
    ll l;
    ll r;
    ll limit_up;
    ll limit_down;
    vector<ll> arr;

private:
    // 偶扩展：
    ll even_expand(ll seed)
    {
        ll ans = seed;
        while(seed)
        {
            ans = (ans*10) + (seed%10);
            seed/=10;
        }
        return ans;
    }

    // 基扩展：
    ll odd_expand(ll seed)
    {
        ll ans = seed;
        seed /= 10;
        while(seed)
        {
            ans = (ans*10) + (seed%10);
            seed /= 10;
        }
        return ans;
    }

    // 检查是否是回文数字：
    bool Is_Palindrome(ll n)
    {
        if(n<0)
        {
            return false;
        }

        ll offset = 1;
        while((n/offset)>=10)
        {
            offset*=10;
        }

        while(n)
        {
            if((n/offset) != (n%10))
            {
                return false;
            }
            else
            {
                n = (n%offset) / 10;
                offset /= 100;
            }
        }

        return true;
    }

    // 检查 构造出来的回文数字的平方是不是超级回文数字
    bool check(ll seed)
    {
        return (seed<=r) && (seed>=l) && (Is_Palindrome(seed));
    }
    
public:
    pair<int , vector<ll>> spir(string left, string right) 
    {
        arr.clear();
        l = stoll(left);
        r = stoll(right);
        // 如果 根号 r 是回文数 --> 正好
        // 如果 根号 r 不是回文数 or 不是整数 --> 最后一个超级回文数一定小于limit
        // 综上 sqrt(超级回文数) <= 根号(R)
        limit_up = sqrt(r)+1; // sqrt(LONG_LONG_MAX) > sqrt(INT_MAX)
        limit_down = sqrt(l)-1;

        ll seed=1;
        ll ans=0;
        ll even=1 , odd=1; // even - 偶扩展 | odd - 基扩展

        while(true)
        {
            // 基扩展:
            odd = odd_expand(seed);
            if(odd > limit_up)
            {
                break;
            }

            if(check(odd*odd))
            {
                ans++;
                arr.push_back(odd*odd);
            }

            // 偶扩展:
            even =  even_expand(seed);
            if(even > limit_up)
            {
                seed++;
                continue;
            }
            if(check(even*even))
            {
                ans++;
                arr.push_back(even*even);
            }
            seed++;
        }
        // 用 seed 创造 even & odd (even[sqrt(L) , sqrt(R)] , odd[sqrt(L) , sqrt(R)])


        // 偶扩展的字长 > 基扩展的字长
        // 一个数的偶扩展 可能 > limit，但是 基扩展 < limit ==> 这种数可能是答案
        // 当一个数的基扩展都 > limit，则越界了

        return make_pair(ans , arr);
    }
};

int main()
{
    Super_Palindromes_In_Range SPIR;

    ll minn = 0;
    ll maxx = LONG_LONG_MAX;
    string str_minn = to_string(minn);
    string str_maxx = to_string(maxx);

    ll ans = SPIR.spir(str_minn , str_maxx).first;
    vector<ll> arr = SPIR.spir(str_minn , str_maxx).second;

    printf("共：%d 个\n" , arr.size());
    for(int i=0 ; i<ans ; i++)
    {
        printf("%lld , \n" , arr[i]);
    }
    return 0;
}