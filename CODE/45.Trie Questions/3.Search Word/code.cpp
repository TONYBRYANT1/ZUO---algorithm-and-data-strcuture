#include<bits/stdc++.h>

using namespace std;

const int N = 1e3+10;

class Solution 
{
private:
    int cnt;
    int Tree[N][26];
    int pass[N];
    string endd[N];
    vector<string> ans;

private:
    // 根据单词建树：
    void words_build(const vector<string>& words)
    {
        // 遍历每个单词：
        for(const auto& word : words)
        {
            int tool=1; // 建Trie 工具
            pass[tool]++;
            int path=0;
            // 遍历单词的每个字母：
            for(const auto& c : word)
            {
                path = c - 'a';
                if(Tree[tool][path]==0)
                {
                    Tree[tool][path]=++cnt;
                }
                tool = Tree[tool][path];
                pass[tool]++;
            }
            endd[tool] = word;
        }
    }

    // 对于每个开始字母开始，单词搜寻过程中把经历过的字母标为零
    // 走过(i , j) --> board(i , j) = '#'
    int dfs(int i , int j , vector<vector<char>>& board , int t)
    {
        // 排除：‘
        // 
        // 一、位置越界，此路不通
        if((i<0) || (i>=board.size()) || (j<0) || (j>=board[0].size()))
        {
            return 0;
        }

        // 二、位置走过，此路不通
        if(board[i][j]=='#')
        {
            return 0;
        }

        // 三、Trie中没有路径，走了也是白走
        // 没有该路径：
        // 1）从来就没有，对应的结点为零：Tree[t][path]==0
        // 2）原本有，但是单词找到了，不需要走这条路了：pass=0
        char tmp = board[i][j];
        int path = tmp - 'a';
        if((Tree[t][path]==0) || pass[Tree[t][path]]==0)
        {
            return 0;
        }

        // 更新t
        t = Tree[t][path];
        // 答案收集：
        // 当前结点可以收集多少种答案(单词)         
        //                up
        //
        //        left    cur    right
        //              
        //                down

        int anss=0;

        // 一、当前结点收集答案：
        if(!endd[t].empty())
        {
            anss++;
            ans.push_back(endd[t]);
            endd[t].clear();
        }
        board[i][j] = '#';

        // 二、上下左右收集答案：
        anss += dfs(i-1 , j , board , t);
        anss += dfs(i+1 , j , board , t);
        anss += dfs(i , j-1 , board , t);
        anss += dfs(i , j+1 , board , t);

        // 修改 pass
        pass[t] -= anss;

        // 恢复现场：
        board[i][j] = tmp;

        return anss;
    }

    void clear()
    {
        memset(Tree , 0 , sizeof(int)*26*(cnt+1));
        memset(pass , 0 , sizeof(int)*(cnt+1));
        for(int i=0 ; i<=cnt ; i++)
        {
            endd[i].clear();
        }
        return;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
    {
        // Trie的结点数：
        cnt=1;
        // 根据单词建树：
        words_build(words);

        // 从 网格 中的任意一个位置开始查询：
        int row = board.size();
        int col = board[0].size();
        for(int i=0 ; i<row ; i++)
        {
            for(int j=0 ; j<col ; j++)
            {
                // DFS - Depth-first-search
                // 1 --> Trie的第一个结点
                dfs(i , j , board , 1);
            }
        }

        clear();
        return ans;
    }
};
