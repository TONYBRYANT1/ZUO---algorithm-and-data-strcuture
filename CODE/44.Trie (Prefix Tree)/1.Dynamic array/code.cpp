// Trie
// 数字 / 字母 在路径中(path)，而不在结点中开设专门的空间存放(int/char something)

#include<bits/stdc++.h>
using namespace std;

class Trie 
{
private:
    typedef struct Node
    {
        int pass; // 单词经过
        int end; // 单词结尾
        unordered_map<char , struct Node*> path; // 路径
        Node(int x , int y) : pass(x) , end(y)
        {
            path.clear();
        }
    }Node , *P;

private:
    P root;

public:
    Trie() 
    {
        root = new Node(0 , 0);
    }
    
    // 插入单词：记得末尾 end++
    void insert(string word) 
    {
        P tool = root;
        tool->pass++;
        
        for(const char& c : word)
        {
            if(tool->path.find(c) == tool->path.end())
            {
                tool->path[c] = new Node(1 , 0);
                tool = tool->path[c];
            }
            else
            {
                tool = tool->path[c];
                tool->pass++;
            }
        }

        tool->end++;
        
        return;
    }

    // 数数单词出现几次：
    int countWordsEqualTo(string word) 
    {
        P tool = root;
        
        for(const auto& c : word)
        {
            if(tool->path.find(c) == tool->path.end())
            {
                return 0;
            }
            else
            {
                tool = tool->path[c];
            }
        }

        return tool->end;
    }
    
    // 数数有多少单词以 pre 开头：
    int countWordsStartingWith(string pre) 
    {
        P tool = root;

        for(const auto& c : pre)
        {
            if(tool->path.find(c) == tool->path.end())
            {
                return 0;
            }
            else
            {
                tool = tool->path[c];
            }
        }

        return tool->pass;
    }
    
    // 删除：
    void erase(string word) 
    {
        if(!countWordsEqualTo(word))
        {
            return;
        }
        else
        {
            P tool = root;
            tool->pass--;

            for(const auto& c : word)
            {
                if(--tool->path[c]->pass == 0)
                {
                    delete tool->path[c]; // 不干净的删除，会有脏空间，导致内存泄漏
                    tool->path.erase(c);
                    return;
                }
                
                tool = tool->path[c];
            }

            tool->end--;
            
            return;
        }

    }
};

int main()
{
    return 0;
}