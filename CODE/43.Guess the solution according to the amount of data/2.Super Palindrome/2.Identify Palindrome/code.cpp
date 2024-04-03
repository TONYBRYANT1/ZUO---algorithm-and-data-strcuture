// 检验是否是回文数字：
#include<bits/stdc++.h>

using namespace std;

class Is_Palindrome
{
private:
private:
public:
    bool is_palindrome(int n)
    {
        // 特判：
        if(n<0)
        {
            return false;
        }

        // 标准：用来得到 数的首部 和 继续检查回文进程
        // eg:
        // n = 113 | offset = 100
        // n = 9   | offset = 1;
        int offset = 1;
        while((n/offset)>=10)
        {
            offset *= 10;
        }

        while(n)
        {
            // 首部：n/offset
            // 尾部：n%10
            if((n/offset) != (n%10))
            {
                return false;
            }
            // 继续验证：
            else
            {
                //   去掉首部     去掉尾部
                n = (n%offset) / 10;
                offset /= 100;
            }
        }

        return true;
    }
};

int main()
{
    Is_Palindrome ip;
    for(int i=0 ; i<=100 ; i++)
    {
        if(ip.is_palindrome(i) == true)
        {
            printf("%d\n" , i);
        }
    }

    return 0;
}