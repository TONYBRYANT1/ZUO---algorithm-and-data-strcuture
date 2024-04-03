#include<bits/stdc++.h>

using namespace std;

const int N = 1e4+10;

// 例如：arr[ Q , A , Q , K , B , A , A , K , A , Q  , Q ]
//           0   1   2   3   4   5   6   7   8   9    10
// 其中：
//       A：4   B：1    K：2    Q：4
// xor = Q ^ A ^ Q ^ K ^ B ^ A ^ A ^ K ^ A ^ Q ^ Q
//     = A ^ A ^ A ^ A ^ Q ^ Q ^ Q ^ Q ^ K ^ K ^ B
//     = (A ^ A ^ A ^ A) ^ (Q ^ Q ^ Q ^ Q) ^ (K ^ K) ^ B
//     = 0 ^ 0 ^ 0 ^ B
//     = B
int SingleNumber(const int* arr , int n) 
{
    int xorr = 0;
    for(int i=0 ; i<n ; i++)
    {
        xorr ^= arr[i];
    }
    return xorr;
}

int main()
{
    int n=0;
    scanf("%d" , &n);

    int arr[N];
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d" , &arr[i]);
    }   

    int* p = arr;
    SingleNumber(p , n);
    // SingleNumber(arr , n) // 这种方法是错误的，虽然向函数中传入的时数组的首地址，但是 arr 毕竟是 数组类型 并不是 int 的指针类型，所以不合适
    return 0;
}