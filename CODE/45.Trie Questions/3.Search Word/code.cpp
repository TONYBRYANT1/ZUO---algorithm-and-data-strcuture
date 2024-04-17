// 剪枝：
// 1）沿途走过的路径标记为 '#'，记得回复现场
// 2）前缀树剪枝：
//                  1）用 words 构建前缀树：指导递归展开，只走有搜索价值的路
//                  2）将 单词放入 endd[]：方便收集答案
//                  3）搜索过的路径不需要重新搜索：利用 pass 剪枝

#include<bits/stdc++.h>

using namespace std;

const int N = 1e4+10;

class Solution 
{
private:
    int tree[N][26];
    int pass[N];
    string endd[N];
    int cnt , row , col;
    vector<string> collect;

private:
    // 插入一个单词到字典树中
    void trie_insert(const string& str)
    {
        int tool=1 , path=0;
        pass[tool]++;

        for(const auto& c : str)
        {
            path = c - 'a';

            if(tree[tool][path]==0)
            {
                tree[tool][path] = ++cnt;
            }

            tool = tree[tool][path];
            pass[tool]++;
        }

        endd[tool].assign(str);
        
        return;
    }

    // 通过单词集建立字典树
    void trie_build(const vector<string>& words)
    {
        for(const auto& word : words)
        {
            trie_insert(word);
        }
    }

    // 确定了搜索起始位置，开始深度搜索：
    // dfs的返回值是为了剪枝：减去路径经过的次数
    int dfs(vector<vector<char>>& board , int i , int j , int tool)
    {
        // 一、没有必要进行下去，没有搜索价值：
        // 1）网格越界：
        if((i<0 || i>=row) || (j<0 || j>=col))
        {
            return 0;
        }

        // 2）该位置走过：
        if(board[i][j] == '#')
        {
            return 0;
        }

        // 3）1.该位置没有在 trie 中出现
        //              or
        //    2.或者该路径已经搜索完了，不需要再次搜索了
        char temp = board[i][j];
        int path = temp - 'a';
        if((tree[tool][path]==0) || (pass[tree[tool][path]]==0))
        {
            return 0;
        }

        // 二、可以进行下去，有搜索价值：
        tool = tree[tool][path];
        board[i][j] = '#';
        int ans=0;
        // 1）当前结点就是答案：
        if(!endd[tool].empty())
        {
            ans++; // 作用：1.记录路径次数 2.有助于剪枝(pass--)
            collect.push_back(endd[tool]);
            endd[tool].clear();
        }

        //2）上下左右有答案：
        ans += dfs(board , i-1 , j , tool); // 上
        ans += dfs(board , i+1 , j , tool); // 下
        ans += dfs(board , i , j-1 , tool); // 左
        ans += dfs(board , i , j+1 , tool); // 右

        // 当前结点的工作完成，进行剪枝：
        pass[tool] -= ans;
        
        // 恢复现场：
        board[i][j] = temp;
        
        return ans;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
    {
        // 初始化：
        cnt = 1 , row = board.size() , col = board[0].size();

        // 建字典树：
        trie_build(words);

        // 二位字符网格，每个格子都做开头进行深度搜索：
        for(int i=0 ; i<row ; i++)
        {
            for(int j=0 ; j<col ; j++)
            {
                dfs(board , i , j , 1);
            }
        }

        return collect;
    }
};

int main()
{
    vector<vector<char>> board = {
        {'o' , 'a' , 'a' , 'n'},
        {'e' , 't' , 'a' , 'e'},
        {'i' , 'h' , 'k' , 'r'},
        {'i' , 'f' , 'l' , 'v'}
    };

    vector<string> words = {
        "oath" , "eat"
    };

    vector<string> result;

    Solution slt;
    result = slt.findWords(board , words);

    for(const auto& word : result)
    {
        cout << word << endl;
    }
    
    return 0;
}