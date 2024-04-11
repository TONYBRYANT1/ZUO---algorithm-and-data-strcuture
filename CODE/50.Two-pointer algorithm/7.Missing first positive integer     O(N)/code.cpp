// 双指针做法：
// 一、想法：
//      1）将数组从 低到高进行排序：arr[l] = l+1
//          1 2 3 4
//          0 1 2 3
// 
// 二、变量指针准备
// 1）l：[0...(l-1)] 表示已经排好了的数，当 l=0 时表示还没开始一一检测 arr[l]
//
// 2）r：[r...(n-1)] 表示垃圾区，当 r=n 时表示刚刚开始，垃圾区为空
//    r 也表示最好情况下 数值(1~r) 都能排上
//
// 三、规则：只检测 l 位置上的数值 | 最理想情况 可以摆数值(1~r)
// 1）情况：arr[l] == (l+1)
//    措施：l++
//    解释：当前 l位置上的数值 满足要求，检测下一位
//
// 2）情况：arr[l] < (l+1)
//    措施：将 arr[l] 放入垃圾区，最理想情况数-1
//    解释：当前从 l 位置开始，最小能摆的数值为 (l+1)，而 arr[l] < (l+1)，被视为垃圾值
//
// 3）情况：arr[l] > r
//    措施：将 arr[l] 放入垃圾区，最理想情况数-1
//    解释：当前理想的最大数值为 r ，若 arr[l] > r，则视为垃圾值
//
// 4）情况：(l+1) < arr[l] <= r && arr[arr[l]-1] == arr[l]
//    措施：将 arr[l] 放入垃圾区，最理想情况数-1
//    解释：当前 l位置的数 虽然合理，但是相应的位置上已经放了这样的数，导致数值的重复，被视为垃圾值
// 
// 5）情况：(l+1) < arr[l] <= r && arr[arr[l]-1] ！= arr[l]
//    措施：swap( arr , l , (arr[l]-1) )
//    解释：当前 l位置的数 合理，且相应位置上不是相应的值，那么 arr[l] 受用，可以将 arr[l] 的值放在对应的位置上
//
//  eg:      arr[10] , l=0 , r=n
//          -3  2  1  8  5  4  2  3  5 13  |
//           0  1  2  3  4  5  6  7  8  9  |  10
//           ^                                 ^
//           l                                 r

// step 1: arr[l] < (l+1)
//         swap(arr , l , --r);
//
// ==>
//          13  2  1  8  5  4  2  3  5 | -3
//           0  1  2  3  4  5  6  7  8 | 9   10
//           ^                           ^    
//           l                           r    

// step 2: arr[l] > r 
//         swap(arr , l , --r);
//
// ==> 
//           5  2  1  8  5  4  2  3 | 13 -3
//           0  1  2  3  4  5  6  7 |  8  9   10
//           ^                         ^       
//           l                         r      

// step 3: (l+1) < arr[l] <= r 但是 arr[arr[l]-1] == arr[l]
//         swap(arr , l , --r);
//
// ==> 
//           3  2  1  8  5  4  2 | 5  13 -3
//           0  1  2  3  4  5  6 | 7   8  9   10
//           ^                     ^       
//           l                     r 

// step 4: (l+1) < arr[l] <= r 且 arr[arr[l]-1] != arr[l]
//         swap(arr , l , (arr[l]-1));
//
// ==> 
//           1  2  3  8  5  4  2 | 5  13 -3
//           0  1  2  3  4  5  6 | 7   8  9   10
//           ^                     ^       
//           l                     r 

// step 5: arr[l] == (l+1)
//         l++;
//
// ==> 
//           1  2  3  8  5  4  2 | 5  13 -3
//           0  1  2  3  4  5  6 | 7   8  9   10
//              ^                  ^       
//              l                  r 

// step 6: arr[l] == (l+1)
//         l++;
//
// ==> 
//           1  2  3  8  5  4  2 | 5  13 -3
//           0  1  2  3  4  5  6 | 7   8  9   10
//                 ^               ^       
//                 l               r 

// step 7: arr[l] == (l+1)
//         l++;
//
// ==> 
//           1  2  3  8  5  4  2 | 5  13 -3
//           0  1  2  3  4  5  6 | 7   8  9   10
//                    ^            ^       
//                    l            r 

// step 8: arr[l] > r
//         swap(arr , l , --r);
//
// ==> 
//           1  2  3  2  5  4 | 8  5  13 -3
//           0  1  2  3  4  5 | 6  7   8  9   10
//                    ^         ^       
//                    l         r 

// step 9: arr[l] < (l+1)
//         swap(arr , l , --r);
//
// ==> 
//           1  2  3  4  5 | 2  8  5  13 -3
//           0  1  2  3  4 | 5  6  7   8  9   10
//                    ^      ^       
//                    l      r 

// step 10: arr[l] == (l+1)
//          l++;
//
// ==> 
//           1  2  3  4  5 | 2  8  5  13 -3
//           0  1  2  3  4 | 5  6  7   8  9   10
//                       ^   ^       
//                       l   r 

// step 11: arr[l] == (l+1)
//          l++;
//
// ==> 
//           1  2  3  4  5 | 2  8  5  13 -3
//           0  1  2  3  4 | 5  6  7   8  9   10
//                           ^       
//                           lr 

// step 12: l==r
//          退出while , return (l+1) 即 5位置还没有摆好，最小的没出现的整数为 6

#include<bits/stdc++.h>

using namespace std;

class Solution 
{
private:
    void swap(vector<int>& nums , int i , int j)
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        return;
    }
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        int n = nums.size();
        int l=0 , r=n;
        
        while(l<r)
        {
            // 符合要求：
            if(nums[l] == (l+1))
            {
                l++;
            }
            // 垃圾数：
            // 0.value = nums[l]
            // 1.value < (l+1) 
            // 2.value > r
            // 3.(l+1) < value <= r 并且 nums[value-1] == value ---> 数字重复
            //
            // 一二条命中：垃圾数
            else if((nums[l] < (l+1)) || (nums[l] > r))
            {
                swap(nums , l , --r);
            }
            // 第三条命中：垃圾数
            // 筛选后的条件：(l+1) < value <= r
            // 如果 (value-1) 位置上的值等于 value 
            // 即：(value-1) 位置上已经摆放好了，那么 l 位置上的 value值也成了垃圾
            else if(nums[nums[l]-1] == nums[l])
            {
                swap(nums , l , --r);
            }
            // (l+1) < value <= r
            // 并且 (value-1) 位置上的值不等于 value 
            else
            {
                swap(nums , l , (nums[l]-1));
            }
        }

        return l+1; // l 和 r 碰上时结算答案
    }
};