// 一、思路：
// 滑动窗口：
// 滑动窗口 [l ... r]，保证该窗口内部没有重复字符
// 遍历每一个元素，收集 每一个以当前元素作为窗口结尾位置 且 没有重复字符的最长窗口
// 在求 窗口长度的最小值

// 二、做法：
// 1）当没有遇到重复字符时，窗口正常滑动
// 2）当遇到重复的字符时，l位置开始跳转：
//    l的跳转方式：
//    1）如果上一次字符出现的位置在窗口之外，不用管，l不跳转
//    eg   : a b b a
//    index: 0 1 2 3 
//               l r
//
//    2）如果上一次字符出现的位置在窗口内 or 窗口边界，l = 上一次出现的位置 + 1
//    eg   : a    b c d e f a
//    index: 0    1 2 3 4 5 6
//           l -> l'        r

// 三、复杂度：
// 1）时间复杂度：O(N)
// 2）空间复杂度：O(1) 最多 256个(0~255)

#include<bits/stdc++.h>

using namespace std;

class Solution 
{
private:    
    unordered_map<char , int> hashmap;

public:
    // 用 hashmap 来记录上一次出现的位置
    int lengthOfLongestSubstring1(const string& s) 
    {
        int n = s.length();
        int length=0;
        //  0 1 2 3 4 5 6 
        // "t m m z u x t"
        for(int l=0 , r=0 ; r<n ; r++)
        {
            if(hashmap.find(s[r]) == hashmap.end())
            {
                hashmap.insert({s[r] , r});
                length = max(length , (r-l+1));
            }
            else
            {
                // 关键：
                l = hashmap[s[r]]<l ? l : (hashmap[s[r]]+1);
                hashmap[s[r]] = r;
                length = max(length , (r-l+1));
            }
        }

        return length;
    }

    // 用 arr[] 来记录上一次出现的位置
    int lengthOfLongestSubstring2(string s) 
    {
        // 该字符上一次出现的位置：
        int arr[256];
        memset(&arr[0] , -1 , sizeof(arr));

        int n = s.length() , length=0 , l=0;
        for(int r=0 ; r<n ; r++)
        {
            l = max(l , arr[(int)s[r]]+1);
            length = max(length , (r-l+1));
            arr[(int)s[r]] = r;
        }

        return length;
    }
};

int main()
{
    string s = "tmmzuxt";

    Solution slt;
    cout << slt.lengthOfLongestSubstring2(s) << endl;
}