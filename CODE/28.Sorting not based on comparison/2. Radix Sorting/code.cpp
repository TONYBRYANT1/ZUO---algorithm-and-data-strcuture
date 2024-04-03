// 基数排序的实现细节，非常优雅的一个实现
// 关键点：前缀数量分区的技巧、数字提取某一位的技巧
// 时间复杂度O(n)，额外空间复杂度O(m)，需要辅助空间做类似桶的作用，来不停的装入、弹出数字

// 原数组：
// Array：[ 3 , 0 , 3 , 2 , 1 , 3 , 0 , 0 , 1 , 2 , 2 ]
//          0   1   2   3   4   5   6   7   8   9   10

// 词频统计：                        定位统计：前缀数量分区
// 0 ：3个                          <=0 ：3个 -> 2个 -> 1个 -> 0个
// 1 ：2个           ===>           <=1 ：5个 -> 4个 -> 3个
// 2 ：3个                          <=2 ：8个 -> 7个 -> 6个 -> 5个
// 3 ：3个                          <=3 ：11个 -> 10个 -> 9个 -> 8个

// 逆序遍历 Array，按照定位统计填入 Help 数组
// Help：[ 0   0   0   1   1   2   2   2   3   3   3  ]
//         0   1   2   3   4   5   6   7   8   9   10

// 为什么要逆序遍历 Array：
// 1）排序的稳定性：
// 在基数排序的实现中，逆序访问原数组 arr 的目的是为了保证排序的稳定性。稳定性是指排序算法在处理相等元素时能够保持它们在原数组中的相对顺序不变。
// 在循环中，我们逆序遍历原数组 arr。这样做的好处是，当存在相等的元素时，先出现的元素会先放入对应的位置，而后出现的相等元素会放在它们之后的位置。这样可以保证相等元素的相对顺序不变，从而保证了排序的稳定性。
// 如果我们采用顺序访问 arr 的方式，那么在处理相等元素时，后出现的相等元素可能会先放入对应的位置，从而打破了它们在原数组中的相对顺序，导致排序不稳定。
// 因此，为了确保排序的稳定性，我们需要在逆序遍历原数组 arr 的情况下进行元素的放置操作。
// 2）自己的理解：
//      1）基数排序，是基于数字的每一位（从低位到高位）进行排序，每一位的排序 基于 上一位（较低位）排好的基础上
//      2）先将所有元素按照低位排序，再保持低位位序不变的情况下去排高位的位序（能让 已经排好的 低位的 位序 变化的原因 只能受 高位数值 的影响）
//      3）如果是顺序排序，那么低位顺序的改变不仅仅受到高位数值的影响，也受到错位的影响
//      4）错位的影响：有数组：arr[ 11 , 12 , 13 , 14 , 15] 
//         低位序已经排好，如果按照高位顺序遍历，会导致数组变成 [15 , 14 , 13 , 12 , 11]
//         使得原先在 15 之前的 11 排在了 15 之后
//         这种错位的影响是 顺序遍历 和 使用词频统计方法往Help中放元素(逆序) 相互作用导致的

// Declaration：
// N-问题规模   B-进制数    M-最大数 x 的位数
// TC & SC：
// 1）TC：O(N)
//      explain：O(M) * (O(N) || O(B)) ==(O(M) << O(N) 、O(B) << O(N))==> O(N)
// 2）SC：O(N) + O(B)

#include<bits/stdc++.h>

using namespace std;

#define BASE 10
const int N = 5e4+10;
int arr[N] , WFS[BASE] , Bucket[N] , n , bits , indexx; // WFS：Word Frequency Statistic   
// WFS[0 ... 9]

// 基数排序核心代码
// arr 内要保证没有负数
// n 是 arr 的长度
// bits 是 arr 中最大值 x 在 BASE 进制下有几位
// indexx 是每个数当前位上的值
void RadixSort()
{
    // 理解的时候可以假设 BASE = 10
    // 一共要走 bits 轮 
    // TC：O(M) M-最大数 x 的位数
    for(int offset=1 ; bits>0 ; offset*=BASE , bits--) // offset 当前级别
    {
        // bits = 4，x = abcd
        // offset = 1     当前位：d
        //          10           c
        //          100          b
        //          1000         a
        memset(WFS , 0 , sizeof(WFS));

        // 当前位数的词频统计
        // TC：O(N)
        for(int i=0 ; i<n ; i++)
        {
            indexx = (arr[i]/offset)%BASE;
            WFS[indexx]++;
        }

        // 前缀数量分区：
        // arr[1] = arr[0] + arr[1];
        // arr[2] = arr[1] + arr[2];
        // ...
        // arr[9] = arr[8] + arr[9];
        // TC：O(B) B-进制数
        for(int i=1 ; i<BASE ; i++)
        {
            WFS[i] = WFS[i-1] + WFS[i];
        }

        // 逆序遍历 arr
        // 向桶里填数字
        // TC：O(N) N-数组元素个数
        for(int i=n-1 ; i>=0 ; i--)
        {
            indexx = (arr[i]/offset)%BASE;
            Bucket[WFS[indexx]-1] = arr[i];
            WFS[indexx]--;
        }

        // TC ：O(N)
        for(int i=0 ; i<n ; i++)
        {
            arr[i] = Bucket[i];
        }
    }

}

int main()
{
    scanf("%d" , &n);
    int maxx = INT_MIN;
    int minn = INT_MAX;
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d" , &arr[i]);
        if(arr[i] > maxx)
        {
            maxx = arr[i];
        }
        if(arr[i] < minn)
        {
            minn = arr[i];
        }
    }

    if(minn < 0)
    {
        for(int i=0 ; i<n ; i++)
        {
            arr[i] -= minn;
        }
        maxx -= minn; // 当数组最小值小于零时，将数组更新成非负数组，一定记得将记录的最大值更新，不然影响 bits 的值，从而影响排序
    }

    while(maxx > 0)
    {
        maxx /= BASE;
        bits++;
    }

    RadixSort();

    if(minn < 0)
    {
        for(int i=0 ; i<n ; i++)
        {
            arr[i] +=minn;
        }
    }

    for(int i=0 ; i<n ; i++)
    {
        printf("%d " , arr[i]);
    }

    return 0;
}