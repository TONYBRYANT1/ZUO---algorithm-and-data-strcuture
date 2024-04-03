// Number of Atom

#include<bits/stdc++.h>

using namespace std;

class Atom_Counter
{
private:    
    string str;
    int where;

private:
    void fill(const string& name , const map<string , int>& pre , map<string , int>& ans , int cur)
    {
        // 历史结算：
        // 两种：1.名字结算 2.小表结算
        // 两种必有其一，但是不可能两种同时有
        if((!name.empty()) || (!pre.empty()))
        {
            cur = cur==0 ? 1 : cur; // 当字母仅有一个时，cur=0
            // 名字结算：
            if(!name.empty())
            {   
                ans[name] += cur;
            }
            // 小表结算：
            else
            {
                for(const auto& e : pre)
                {
                    ans[e.first] += e.second*cur;
                }
            }
        }

        return;
    }

    map<string , int> f(int i)
    {
        // 名字：
        string name;
        name.clear();
        //
        // 大表：    
        map<string , int> ans;
        ans.clear();
        //
        // 小表：
        map<string , int> pre;
        pre.clear();
        //
        // 历史翻倍：
        int cur=0;
        
        // 退出循环的几种情况：1.最外层：遍历完了 2.内层：遇到 ')'
        while((i<str.length())&&(str[i]!=')'))
        {
            // 旧历史结算：
            // 结算特征：1.遇到大写字母 A ~ Z   2.遇到 '('
            if(((str[i]>='A')&&(str[i]<='Z')) || (str[i]=='('))
            {
                // 结算：
                fill(name , pre , ans , cur);
                // 结算完成之后：更新
                name.clear();
                pre.clear();
                cur=0;

                // 新历史开始：
                // 碰到大写字母：
                if((str[i]>='A')&&(str[i]<='Z'))
                {
                    name = str[i++];
                }
                // 碰到 '('：
                else
                {
                    pre = f(i+1);
                    i = where+1;
                }
            }
            // 遇到小写字母：
            else if((str[i]>='a')&&(str[i]<='z'))
            {
                name += str[i++];
            }
            // 遇到数字
            else
            {
                cur = cur*10 + (str[i] - '0');
                i++;
            }
        }

        // 最后的历史可能还没有添加：
        fill(name , pre , ans , cur);

        // 更新 where：
        where = i;

        // 返回答案：
        return ans;
    }

public:
    string counter(string s)
    {
        string answer;
        answer.clear();
        str.clear();
        str = s;
        where = 0;
        map<string , int> map = f(0);
        
        for(const auto& e : map)
        {
            answer.append(e.first);
            if(e.second > 1)
            {
                answer.append(to_string(e.second));
            }

        }
        
        return answer;
    }
};

int main()
{
    string expression = "Mg(OH)2";
    Atom_Counter ac;
    cout << ac.counter(expression) << endl;
}