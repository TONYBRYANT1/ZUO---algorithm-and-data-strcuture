#include<bits/stdc++.h>

using namespace std;

const int N = 1.5e5 + 10;

class Trie 
{
private:
    int cnt; // 结点数
    int Tree[N][26]; // 最多 N-1 个结点(Tree[0]默认不用)，每个结点 26个方向
    int pass[N]; // 经过
    int end[N];  // 结束

public:
    Trie() 
    {
        // 更新：
        memset(Tree , 0 , sizeof(Tree));
        memset(pass , 0 , sizeof(pass));
        memset(end , 0 , sizeof(end));
        cnt=1;
    }
    
    void insert(string word) 
    {
        // 从 1 开始遍历：tool - 遍历工具
        int tool = 1;
        pass[tool]++;
        int path=0;

        for(const auto& c : word)
        {
            // 决定路径：
            path = c - 'a';

            // 没有该路径：
            if(Tree[tool][path] == 0)
            {
                // 创造路径：
                Tree[tool][path] = ++cnt; // 创造第二个结点，并加入到第一个结点的路径中去
            }

            // 继续遍历：
            tool = Tree[tool][path]; // 来到第二个结点
            pass[tool]++;
        }

        // 来到最后一个结点：end++
        end[tool]++;
    }
    
    int countWordsEqualTo(string word) 
    {
        // 从结点 1 开始遍历：遍历工具 - tool
        int tool = 1;
        int path = 0;

        for(const auto& c : word)
        {
            // 路径：
            path = c - 'a';
            
            // 路径断了：
            if(Tree[tool][path] == 0)
            {
                return 0;
            }
            // 路径没断，来到下一结点：
            else
            {
                tool = Tree[tool][path];
            }
        }

        // 返回最后一个结点的 end:
        return end[tool];
    }
    
    int countWordsStartingWith(string prefix) 
    {
        // 从 1 开始遍历：遍历工具 - tool
        int tool = 1;
        int path = 0;
        
        for(const auto& c : prefix)
        {
            // 路径：
            path = c - 'a';
            // 路径断开：
            if(Tree[tool][path] == 0)
            {
                return 0;
            }
            // 路径没断：
            tool = Tree[tool][path];
        }

        // 返回 prefix 路径的 pass
        return pass[tool];
    }
    
    void erase(string word) 
    {
        // word 没出现过：
        if(!countWordsEqualTo(word))
        {
            return;
        }
        // 出现过：
        else
        {
            // 从 1 开始遍历：遍历工具 - tool
            int tool = 1;
            pass[tool]--;
            int path = 0;

            for(const auto& c : word)
            {
                // 路径：
                path = c - 'a';

                // pass--：
                // 如果下个结点的 pass 值为 1，直接删除，并退出，不予理会
                // 该结点 及 后面的一段结点 不需要了，以后会有更大的结点直接代替
                if((--pass[Tree[tool][path]]) == 0)
                {
                    // 删除 对应的标记
                    Tree[tool][path] = 0;
                    return;
                }

                tool = Tree[tool][path];
            }
            
            // end--
            end[tool]--;
            return;
        }
    }
};