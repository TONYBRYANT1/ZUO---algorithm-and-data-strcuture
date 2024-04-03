// 用位运算的方法（巧妙、常数时间快，推荐）
// int col   : 0..i-1行皇后放置的位置因为正下方向延伸的原因，哪些列不能再放皇后
// int left  : 0..i-1行皇后放置的位置因为左下方向延伸的原因，哪些列不能再放皇后
// int right : 0..i-1行皇后放置的位置因为右下方向延伸的原因，哪些列不能再放皇后
// 根据col、left、right，用位运算快速判断能放哪些列
// 把能放的列都尝试一遍，每次尝试修改3个数字表示当前的决策，后续返回的答案都累加返回

#include<bits/stdc++.h>

using namespace std;

typedef unsigned int ui;

class N_Queen
{
private:
    ui limit;

private:
    int f2(int column , int left , int right)
    {
        // 填完了：
        if(column == limit)
        {
            return 1;
        }

        // 没填完：
        // 假设当前局势：
        // 进入第 1 层：
        //  \ 0  1  2  3  4 
        // 0  +  +  +  *  +  
        // 1  +  +  +  +  + 
        // 2  +  +  +  +  + 
        // 3  +  +  +  +  +
        // 4  +  +  +  +  +
        //
        //         n-1 n-2 ... 5 4 3 2 1 0
        // limit :  0   0  ... 0 1 1 1 1 1 
        // column:  0   0  ... 0 0 1 0 0 0 
        // left  :  0   0  ... 0 0 0 1 0 0 
        // right :  0   0  ... 0 1 0 0 0 0 
        
        // 总限制：1-不能放 0-可以放
        // eg: 
        // ban   :  0   0  ... 0 1 1 1 0 0 
        ui ban = column | left | right;
        
        // ~ban : 0-不能放 1-可以放
        // eg:
        // ~ban  :  1   1  ... 1 0 0 0 1 1

        // 得到可以尝试的位数
        ui candidate = limit & (~ban);
        // eg:
   // candidate  :  0   0  ... 0 0 0 0 1 1
        
        ui place = 0;
        int ans=0;

        while(candidate)
        {
            // 提取最右侧的 1：
            // 5 4 3 2 1 0
            // candidate:
            // 0 0 0 0 1 1 
            // place:
            // 0 0 0 0 0 1
            // candidate:
            // 0 0 0 0 1 0
            // place:
            // 0 0 0 0 1 0
            // candidate:
            // 0 0 0 0 0 0
            // quit
            place = candidate & (-candidate);
            candidate ^= place;

            // 假设用了第一个 place :
            //         n-1 n-2 ... 5 4 3 2 1 0
            // place :  0   0  ... 0 0 0 0 0 1
            //
            // 当前局势更改：
            // 进入第 2 层：
            //  \ 0  1  2  3  4
            // 0  +  +  +  *  +
            // 1  *  +  +  +  +
            // 2  +  +  +  +  +
            // 3  +  +  +  +  +
            // 4  +  +  +  +  +
            //
            // 以前的 column , left , right:         
            //         n-1 n-2 ... 5 4 3 2 1 0
            // column:  0   0  ... 0 0 1 0 0 0 
            // left  :  0   0  ... 0 0 0 1 0 0 
            // right :  0   0  ... 0 1 0 0 0 0 
            // 
            // 更新：
            // limit :  0   0  ... 0 1 1 1 1 1 
            // column:  0   0  ... 0 0 1 0 0 1 
            // left  :  0   0  ... 0 0 0 0 1 0
            // right :  0   0  ... 1 0 0 0 1 0
            ans += f2((column|place) , ((left|place)>>1) , ((right|place)<<1));
        }

        return ans;
    }

public:
    int n_queen(int n)
    {
        if(n<1)
        {
            return 0;
        }

        // 限制：仅仅在 0~4 范围上有效果
        // eg: n=5 ==> limit=0b 0...1 1 1 1 1
        //                          4 3 2 1 0
        // 1<<5   = 0b0...100000
        // 1<<5-1 = 0b0...011111
        limit = (1<<n)-1;
        //
        // 列限制：
        ui column = 0;
        //
        // 右上 --> 左下 的限制：
        ui left   = 0;
        //
        // 左上 --> 右下 的限制：
        ui right  = 0;

        return f2(column , left , right);
    }
};

int main()
{
    int n;
    scanf("%d" , &n);
    N_Queen nq;
    cout << nq.n_queen(n) << endl;
    return 0;
}