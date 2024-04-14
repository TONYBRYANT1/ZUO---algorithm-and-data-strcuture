#include<bits/stdc++.h>

using namespace std;

typedef ListNode* PL;
typedef TreeNode* PT;

class Solution 
{
private:
    vector<int> next;
    vector<int> s2;
    int m;

private:
    // 获得 比较串s2 的 next数组
    void get_next()
    {
        next.clear();

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
            next[0] = -1;
            next[1] = 0;
            int i=2 , cn=0;
            
            while(i<m)
            {
                if(s2[i-1] == s2[cn])
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
                    next[i] == 0;
                    i++;
                }
            }
        }

        return;
    }

private:
    bool find(PT& root , int y)
    {
        // 一、结算情况：
        // 1）比较串 s2 便利完成 ---> 说明树中有该结构的链表
        if(y == m)
        {
            return true;
        }
        // 2）比较串 s2 还未完成，但根结点先为空 ---> 说明树中没有该结构的链表
        else if((root==nullptr) && (y!=m))
        {
            return false;
        }
        // 二、普通情况：
        // root != nullptr && y != m
        else
        {
            // 匹配：
            while((y!=-1) && (root->val!=s2[y]))
            {
                y = next[y];
            }

            // 一边不行换另一边
            return find(root->left , y+1) || find(root->right , y+1);
        }
    }

public:
    bool isSubPath(PL& head, PT& root) 
    {
        // 现将 head链表 转化为 比较串
        s2.clear();
        PL cur = head;

        while(cur!=nullptr)
        {
            s2.push_back(cur->val);
            cur = cur->next;
        }

        m = s2.size();

        get_next();

        // 从 根结点开始比较
        return find(root , 0);
    }
};