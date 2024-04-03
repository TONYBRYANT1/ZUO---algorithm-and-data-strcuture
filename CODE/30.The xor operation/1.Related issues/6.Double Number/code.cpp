// 因为会出现 arr[0 , 1 , 1 , -2^31]
// 因为 正数范围是[-2^31 ~ 2^31-1]
// 1）为了避免 2^31 的出现，可以先将 xorr 和 xor_ 设置为 unsigned int 
// 求具体的值时在强制类型转换为 int
// 2）或者直接用 long

// 会出现的问题：
// 1）将一个数的补码 取反加一 会得到 相反数的补码
// 2）将 INT_MIN 取反 会出问题

#include<bits/stdc++.h>

const int N = 1e4+10;

int arr[N] , n;

using namespace std;

pair<int , int> DoubleNumber()
{
    // 首先  获得 a^b
    unsigned int xorr=0;
    for(int i=0 ; i<n ; i++)
    {
        xorr ^= arr[i];
    }
    // xor == a^b;

    // (n)&((~n)+1) == (n)&(-n) == 最右边的 1
    // eg：A：0 0 1 1 0 0 1 0 (50)
    //     B：1 1 0 0 1 1 0 1 (~A)
    //     C：1 1 0 0 1 1 1 0 (~A + 1)
    //     A & C = 0 0 0 0 0 0 1 0 
    //     得到最右边的 1
    int RightOne = (xorr) & ((~xorr)+1); // 因为 a != b，所以 xorr 一定至少有一位为 1

    // 用这个 RightOne(1) 来区别 a 、b
    
    // 分区：RightOne 位置上是 1 的数，RightOne 位置上不是 1 的数
    // 将 RightOne 位置上是 1 的数 求异或和，因为除了 a 外，其他的数都是偶数，所以 RightOne 上的 1 都会消掉，只剩下 a（假设 a 的 RightOne上的数值为 1）
    
    unsigned int xor_=0;

    for(int i=0 ; i<n ; i++)
    {   
        // 这里不能写 == 1
        // 有两种情况
        // 1）& 完之后 RightOne上是 1，但是并不代表 (arr[i] & Right) == 1，也有可能是 2、4、8 ...
        // 2）& 完之后 RightOne上是 0
        // 所以 可以写 == 0 or == RightOne
        if((arr[i] & RightOne) == 1) 
        {
            xor_ ^= arr[i];
        }
    }
    // xor_ == a;

    int a = (int)xor_;

    // 因为 xorr = a ^ b;
    // 则 b = a ^ xorr = xor_ ^ xorr
    int b = (int)(xor_ ^ xorr);

    pair<int , int> p;

    if(a > b)
    {
        swap(a , b);
    }

    p.first = a;
    p.second = b;
    
    return p;
}

int main()
{   
    scanf("%d" , &n);
    
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d" , &arr[i]);
    }
    
    pair<int , int> p;

    p = DoubleNumber();

    cout << "a：" << p.first << " " << "b：" << p.second << endl;

    return 0;
}