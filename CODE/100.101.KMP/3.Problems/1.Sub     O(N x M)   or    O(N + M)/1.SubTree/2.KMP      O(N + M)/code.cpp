// 思路：
// 1）将待检验树和模版子树进行二叉树进行先序序列化
// 先序序列化和后序序列化具有唯一性，而中序序列化没有
// 2）将两个序列进行 KMP 搜索匹配

#include<bits/stdc++.h>

using namespace std;

class Solution 
{
private:
    vector<string> s1;
    vector<string> s2;
    vector<int> next;

private:
    // 二叉树的先序序列化：
    // 得到具有唯一性的序列化字符串
    // 时间复杂度：O(N) --- N为tree的结点个数
    void transform(const P& tree , vector<string>& s)
    {
        if(tree==nullptr)
        {
            s.push_back("#");
        }
        else
        {
            s.push_back(to_string(tree->val));
            transform(tree->left , s);
            transform(tree->right , s);
        }

        return;
    }

    // 获得 比较串s2 的 next数组
    // 时间复杂度：O(M) --- M为s串的字符个数
    void get_next(const vector<string>& s)
    {
        next.clear();
        int m = s.size();
        if(m==1)
        {
            next.push_back(-1);
        }
        else if(m==2)
        {
            next.push_back(-1);
            next.push_back(0);
        }
        else
        {
            next.assign(m , 0);
            next.push_back(-1);
            next.push_back(0);

            int i=2 , cn=0;

            while(i<m)
            {
                if(s[i-1].compare(s[cn]) == 0)
                {
                    next[i] = ++cn;
                    i++;
                }
                else if(cn > 0)
                {
                    cn = next[cn];
                }
                else
                {
                    next[i] = 0;
                    i++;
                }
            }
        }

        return;
    }

    // 遍历 s1 的每一个字符，与 s2 中的字符匹配，匹配时间复杂度：O(1)
    // 时间复杂度：O(N) --- N为 s1的字符个数
    int find(const vector<string>& s1 , const vector<string>& s2)
    {
        int n = s1.size() , m = s2.size();
        int x=0 , y=0;

        while(x<n && y<m)
        {
            if(s1[x].compare(s2[y])==0)
            {
                x++ , y++;
            }
            else if(y > 0)
            {
                y = next[y];
            }
            else
            {
                x++;
            }
        }

        return y==m ? (x-m) : -1;
    }

public:
    bool isSubtree(const P& root , const P& subRoot) 
    {
        s1.clear() , s2.clear();
        transform(root , s1) , transform(subRoot , s2);
        get_next(s2);
        return find(s1 , s2) == -1 ? false : true;
    }
};