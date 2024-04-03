// 反转Bit
#include<bits/stdc++.h>

using namespace std;

int help[32];

int main()
{
    unsigned int a;
    cin >> a;
    for(int i=31,j=0; i>=0 ;i--,j++)
    {
        if((i%4==3)&&(i!=31))
        {
            printf(" ");
        }
        help[j] = (a>>i)&1;
        printf("%d" , (a>>i)&1);
    }

    cout << endl;

    for(int i=31,j=0; i>=0 ;i--,j++)
    {
        if((i%4==3)&&(i!=31))
        {
            printf(" ");
        }
        printf("%d" , help[i]);
    }

    return 0;
}