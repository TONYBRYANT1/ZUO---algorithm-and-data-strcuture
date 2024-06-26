// 反转Bit

// 8bit 举例:
//              abcd efgh  <== 初始值
// ==> 1v1反转
//              badc fehg
// ==> 2v2反转  
//              dcba hgfe
// ==> 4v4反转
//              hgfe dcba  <== 目标值                                                                                                           

// 1v1反转方法：
//
// 1)
// abcd efgh             abcd efgh
// 1010 1010 &           0101 0101 &
// -------------         -------------     
// a0b0 e0g0    ==> A    0b0d 0f0h    ==> B
//
// 2）
// A>>1，A：0a0b0e0g
// B<<1，B：b0d0f0h0
//
// 3)
// A | B：
// 0a0b0e0g
// b0d0f0h0 |
// ------------
// badbfehg

#include<bits/stdc++.h>

typedef unsigned int ut;
using namespace std;

ut BitReverse(ut x)
{
    // 1v1      0101 0101 0101 0101 0101 0101 0101 0101 | 1010 1010 1010 1010 1010 1010 1010 1010
    x = ((x & 0xaaaaaaaa)>>1) | ((x & 0x55555555)<<1); // a:1010  5:0101

    // 2v2      1100 1100 1100 1100 1100 1100 1100 1100 | 0011 0011 0011 0011 0011 0011 0011 0011
    x = ((x & 0xcccccccc)>>2) | ((x & 0x33333333)<<2); // c:1100  3:0011

    // 4v4      1111 0000 1111 0000 1111 0000 1111 0000 | 0000 1111 0000 1111 0000 1111 0000 1111
    x = ((x & 0xf0f0f0f0)>>4) | ((x & 0x0f0f0f0f)<<4); // f:1111  0:0000

    // 8v8      1111 1111 0000 0000 1111 1111 0000 0000 | 0000 0000 1111 1111 0000 0000 1111 1111
    x = ((x & 0xff00ff00)>>8) | ((x & 0x00ff00ff)<<8); // f:1111  0:0000

    // 16v16    1111 1111 1111 1111 0000 0000 0000 0000 | 0000 0000 0000 0000 1111 1111 1111 1111
    x = ((x & 0xffff0000)>>16) | ((x & 0x0000ffff)<<16); // f:1111  0:0000

    return x;
}

ut PrintBit(ut x)
{
    for(int i=31 ; i>=0 ; i--)
    {
        if((i!=31)&&(i%4)==3)
        {
            printf(" ");
        }
        printf("%d" , (x>>i)&1);
    }
}

int main()
{
    ut a=0 , b=0;
    cin >> a;
    b = BitReverse(a);
    PrintBit(a);
    cout << endl;
    PrintBit(b);
    return 0;
}