// 替换子串得到平衡字符串
// 思路：
// 如果自由窗口 [L , R] 不能做到使得 s 平衡，则 [i , j] 更不能，其中(i>=L , j<=R)

#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+10;

class Solution 
{
private:
    int n; // s 长度
    int arr[N]; // Q -> 0 | W -> 1 | E -> 2 | R -> 3
    int list[4]; // 统计自由窗口以外 Q W E R 分别出现的次数(窗口长度从 0 开始)
    int aim; // n/4 每个字符需要保证出现的次数
    int ans; // 记录最小窗口长度

private:
    // 自由窗口 [L , R) 能否做到使得 s 平衡
    // 窗口外的每种字符出现的频率要小于等于 aim
    bool ok()
    {
        for(int i=0 ; i<=3 ; i++)
        {
            if(list[i] > aim)
            {
                return false;
            }
        }

        return true;
    }

public:
    int balancedString(string s) 
    {
        // 预处理：
        n = s.length() , aim = n/4 , ans = INT_MAX;
        memset(&arr[0] , 0 , sizeof(arr));
        memset(&list[0] , 0 , sizeof(list));
        for(int i=0 ; i<n ; i++)
        {
            switch(s[i])
            {
                case 'Q':
                    arr[i] = 0 , list[0]++;
                    break;
                case 'W':
                    arr[i] = 1 , list[1]++;
                    break;
                case 'E':
                    arr[i] = 2 , list[2]++;
                    break;
                case 'R':
                    arr[i] = 3 , list[3]++;
                    break;
            }
        }

        // 开始滑动窗口：[L , R) 实际大小 [L , R-1]
        // eg: 0 1 2 3 4 5 6 n=7
        // l :[0 ......... 6]
        // r :[0 ........... 7]
        for(int l=0 , r=0 ; l<=(n-1) ; l++)
        {
            // 窗口从 l 开始，长度 L-R (从 0 开始)
            // 自由窗口 [L , R) 不能做到使得 s 平衡，并且还可以继续扩展
            while((!ok()) && (r<=(n-1)))
            {
                list[arr[r]]--;
                r++;
            }

            // 跳出窗口原因：
            // 1）!ok() && r==n
            // 2） ok() && r<n
            // 3） ok() && r==n
            // 总结为两种 ---> ok() or !ok()
            if(ok())
            {
                ans = min(ans , (r-l));
            }
            else
            {
                ;
            }

            // l 为窗口开端已经试过了, 试试 l+1 为窗口开端：
            // 更新：
            list[arr[l]]++;
        }

        return ans==INT_MAX ? n : ans;
    }
};