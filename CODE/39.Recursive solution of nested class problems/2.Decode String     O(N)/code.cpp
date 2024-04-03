// Decode String

#include<bits/stdc++.h>
using namespace std;

class Print
{
private:
    string str;
    int where;
    string ans;

private:
    string get(const int& n , const string& strr)
    {
        string repeat;
        repeat.clear();
        for(int i=0 ; i<n ; i++)
        {
            repeat.append(strr);
        }

        return repeat;
    }

    // 处理 [i...] 内部数据，直到遇到 ']' 停止
    // 将处理的数据返回到上层
    // 更新 where，让上游知道从哪里继续
    string f(int i)
    {
        string path;
        path.clear();
        int cur=0;
        //
        // 当遍历完成 or 碰到 ']' 结束循环
        while((str[i] != ']')&&(i<str.length()))
        {
            // 可能会遇到：1.数字 2.字母 3.'['
            // 1.字母：
            if(((str[i]>='a')&&(str[i]<='z'))||((str[i]>='A')&&(str[i]<='Z')))
            {
                path.append(1 , str[i++]);
            }
            // 2.数字
            else if((str[i]>='0')&&(str[i]<='9'))
            {
                // 累加次数
                cur = cur*10 + (str[i]-'0');
                i++;
            }
            // 3.'['
            else
            {
                path.append(get(cur , f(i+1)));
                i = where+1;
                cur=0;
            }   

        }

        where = i;
        return path;
    }

public:
    void print(const string& s)
    {
        str.clear();
        str = s;
        ans = f(0);
        cout << ans << endl;
    }
};

int main()
{
    string expression = "abc3[c]";
    Print pt;
    pt.print(expression);
    return 0;
}