// 用位状态来记录信息

#include<bits/stdc++.h>

using namespace std;

class Solution 
{
private:
    // key: 各个元音状态：a e i o u
    // value: 下标
    unordered_map<int , int> hashmap;
    int n;

private:   
    int trans(char c)
    {
        switch(c)
        {
            case 'a': return 4;
            case 'e': return 3;
            case 'i': return 2;
            case 'o': return 1;
            case 'u': return 0;
            default : return -1;
        }
    }

public:
    int findTheLongestSubstring(const string& s) 
    {
        n = s.length();

        hashmap.clear();
        hashmap.insert({0 , -1}); // 0 : 0 0 0 0 0 
        int status=0 , move_tool=0 , length=0 , l=0;

        for(int r=0 ; r<n ; r++)
        {
            // 改变相应的位状态
            // 不是元音，不改变状态
            move_tool = trans(s[r]);
            if(move_tool != -1)
            {
                statue ^= (1<<move_tool);
            }

            // 都是偶数次，直接记录答案
            if(statue == 0)
            {
                length = max(length , r+1);
            }
            else
            {
                // 看看前面有没有一样的状态
                if(hashmap.find(statue) != hashmap.end())
                {
                    l = hashmap[statue];
                    length = max(length , r-l);
                }
            }

            if(hashmap.find(statue) == hashmap.end())
            {
                hashmap.insert(statue , r);
            }
        }

        return length;
    }
};