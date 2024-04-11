#include<bits/stdc++.h>

using namespace std;

int n , t;
int a , b , c , d , k=1;
vector<vector<int>> metrix;

// 离散化：
void metrix_set()
{
    metrix[a][b] += k;
    metrix[c+1][b] -= k;
    metrix[a][d+1] -= k;
    metrix[c+1][d+1] += k;
    return;
}

// 前缀和：
void metrix_build()
{
    for(int i=1 ; i<=n ; i++)
    {
        for(int j=1 ; j<=n ; j++)
        {
            metrix[i][j] += metrix[i][j-1] + metrix[i-1][j] - metrix[i-1][j-1];
        }
    }
    return;
}

int main()
{
    scanf("%d%d" , &n , &t);
    fflush(stdin);

    // metrix 的初始化：[0 , n-1] --> [0][1 , n][n+1]
    metrix.clear();
    metrix.resize((n+2) , vector<int>((n+2) , 0));

    while(t--)
    {
        scanf("%d%d%d%d" , &a , &b , &c , &d);
        fflush(stdin);
        metrix_set();
    }

    metrix_build();

    for(int i=1 ; i<=n ; i++)
    {
        for(int j=1 ; j<=n ; j++)
        {
            printf("%d " , metrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}