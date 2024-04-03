// 计数排序，非常简单，但是数值范围比较大了就不行了

// 例子 N = 1e6 , 元素值域：0 ~ 60

// 方案：
// 1）做 0 ~ 60 的词频统计
// 2）还原数组

#include<bits/stdc++.h>

using namespace std;

const int N = 1e6+10;

int arr[N] , WFS[61] , n; // WFS：Word Frequency Statistic

int main()
{
    memset(arr , 0 , sizeof(arr));

    scanf("%d" , &n);
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d" , &arr[i]);
    }

    for(int i=0 ; i<n ; i++)
    {
        WFS[arr[i]]++;
    }

    for(int i=0 ; i<=60 ; i++)
    {
        while(WFS[i]-- > 0)
        {
            printf("%d " , i);
        }
    }
    return 0;
}