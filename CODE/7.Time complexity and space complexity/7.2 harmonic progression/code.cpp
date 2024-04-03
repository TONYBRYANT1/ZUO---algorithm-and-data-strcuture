// 调和级数
// 1 + 1/2 + 1/3 + ... + 1/(N-1) + 1/N = log2(N)
// N + N/2 + N/3 + ... + N/(N-1) + N/N = N*log2(N)

// 对于200000的数据来说
// O(N*log2(N))共花费 0.003 s
// O(N^2)共花费 55.878 s

#include<bits/stdc++.h>

using namespace std;

const int N = 200000;

int arr[N];

void fun1()
{
    for(int i=1 ; i<=N ; i++)
    {
        for(int j=i ; j<=N ; j+=i)
        {
            ;
        }
    }
}

void fun2()
{
    for(int i=1 ; i<=N ; i++)
    {
        for(int j=1 ; j<=N ; j++)
        {
            ;
        }
    }
}

int main()
{
    clock_t start , end;
    start = clock();
    fun1();
    end = clock();
    cout << "O(N*log2(N))共花费 " << double(end-start)/CLOCKS_PER_SEC << " s" << endl;
    start = clock();
    fun2();
    end = clock();
    cout << "O(N^2)共花费 " << double(end-start)/CLOCKS_PER_SEC << " s" << endl;
    return 0;
}