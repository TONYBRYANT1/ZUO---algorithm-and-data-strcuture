#include<bits/stdc++.h>

using namespace std;

const int N = 1e4+10;

int MissingNumber(const int*& arr , int n) 
{
    // X ^ a = Y;
    // a = Y ^ X;
    int X=0 , Y=0;
    for(int i=0 ; i<n ; i++)
    {
        X ^= arr[i];
        Y ^= i;
    }
    Y ^= n;
    return Y^X;
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

    cout << MissingNumber(arr , n) << endl;

    return 0;

}