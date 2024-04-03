// 保证同时入栈的个数 不超过 N
#include<bits/stdc++.h>

using namespace std;

const int N = 1e3+10;
int stack[N] , size=0;

bool IsEmpty()
{
    return size == 0;
}

void Push(int x)
{
    stack[size++] = x;
}

int Pop()
{
    return stack[--size];
}

int Peek()
{
    return stack[size-1];
}

int size()
{
    return size;
}

int main()
{
    return 0;
}