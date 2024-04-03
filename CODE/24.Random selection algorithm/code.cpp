// 无序数组中找第 k 大的数(数值) 
// 假设有 100 个数
// 无序数组中第 1 大 <==> 无序数组中第 100 小
// 第一大的数 下标 n-1
// 第二大的数 下标 n-2

// 方法：
// 1）在快速排序的基础上做修改
// 2）在荷兰国旗问题基础上，看 <x =x >x 哪一个范围命中了该下标
// 3）因为其他范围已经定序了，所以就在命中下标的范围上再求具体的下标

// 复杂度分析：
// 1）时间复杂度：期望是 O(N)
//              1）最坏：O(N^2)，想要的下标在最左边，选的数在最右边(镜像也一样)
//              2）最好：O(N)，每一次选的数都在当前段落的中间，只用扫描 (N+N/2+N/4+N/8...) -> O(N)
// 2）空间复杂度：O(1)
// 不管问题规模 N 有多大，只用几个有限的变量去处理问题(原数组不算)

#include<bits/stdc++.h>

using namespace std;

const int N = 5e4+10;
int arr[N] , n , k;

void swap(int& x , int& y)
{
    int temp = x;
    x = y;
    y = temp;
}

void DutchFlagIssue(int l , int r , int x , int& first , int& last)
{
    int a=l , b=r , i=l;
    while(i<=b)
    {
        if(arr[i] < x)
        {
            swap(arr[i] , arr[a]);
            a++ , i++;
        }
        else if(arr[i] > x)
        {
            swap(arr[i] , arr[b]);
            b--; // i++ 因为交换之后 arr[i] 的值还没有扫描过
        }
        else
        {
            i++;
        }
    }
    first = a , last = b;
}

// 找到下标为 k 的数
int FindBigK(int l , int r , int k)
{
    int ans=0;
    while(l<=r)
    {
        int x = arr[l+rand()%(r-l+1)];
        int first=0 , last=0;
        // <x      =x      >x
        // first           last
        DutchFlagIssue(l , r , x , first , last);
        if(k<first)
        {
            r = first-1;
        }
        else if(k>last)
        {
            l = last+1;
        }
        else
        {
            ans = arr[k]; // first <= i <= last 且 arr[first...last] = x
            break;
        }
    }

    return ans;
}

int main()
{
    srand((unsigned)time(NULL));
    scanf("%d" , &n);
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d" , &arr[i]);
    }

    scanf("%d" , &k);

    printf("第%d大的数 = %d" , k , FindBigK(0 , n-1 , n-k));
    return 0;
}



