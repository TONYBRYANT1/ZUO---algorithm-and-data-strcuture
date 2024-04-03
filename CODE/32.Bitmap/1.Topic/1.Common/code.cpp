#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Bitset {
public:
    unsigned int* p;
    int size , ones , zeros , reverse , n;
public:
    Bitset(int sizee) 
    {
        n = (sizee + 31) / 32;
        p = new unsigned int[n];
        memset(p , 0 , sizeof(unsigned int) * n); // 正确初始化数组大小
        size = sizee;
        ones = 0;
        zeros = size;
        reverse = 0;
    }

    void fix(int x) 
    {
        int idx = x / 32;
        if (idx >= n) return; // 检查索引是否越界
        int bit = x % 32;
        if(((p[idx] >> bit) & 1) == 0)
        {
            p[idx] |= (1 << bit);
            zeros--;
            ones++;
        }
    }

    void unfix(int x) 
    {
        int idx = x / 32;
        if (idx >= n) return; // 检查索引是否越界
        int bit = x % 32;
        if(((p[idx] >> bit) & 1) == 1)
        {
            p[idx] &= ~(1 << bit);
            zeros++;
            ones--;
        }
    }

    void flip() 
    {
        int temp = ones;
        ones = zeros;
        zeros = temp;

        for(int i = 0; i < n; i++)
        {
            p[i] ^= 0xffffffff;
        }
    }

    bool all() 
    {
        return ones == size;
    }

    bool one() 
    {
        return ones > 0;
    }

    int count() 
    {
        return ones;
    }

    string toString() 
    {
        string str;
        for(int i = 0; i < n; i++)
        {
            unsigned int number = p[i];
            for(int j = 0, k = i * 32; j < 32 && k < size; j++, k++) // 修正循环条件
            {
                char a;
                unsigned int t = (number >> j) & 1;
                t ^= reverse; // 翻转逻辑
                if(t == 1)
                {
                    a = '1';
                }
                else
                {
                    a = '0';
                }
                str.push_back(a);
            }
        }
        return str;
    }
};