// 草一共有n的重量，两只牛轮流吃草，A牛先吃，B牛后吃
// 每只牛在自己的回合，吃草的重量必须是4的幂，1、4、16、64....
// 谁在自己的回合正好把草吃完谁赢，根据输入的n，返回谁赢

#include<bits/stdc++.h>

using namespace std;

class SheepEatGrass
{
private:
private:
    // rest - 还剩多少草 | cur - 当前选手
    string f(int rest , string cur)
    {
        // enemy:
        string enemy = cur == "A" ? "B" : "A";

        // rest < 5:
        // 1) rest = 1  cur = A --> A win | B lose      仅一种选择
        //
        // 2) rest = 2  cur = A --> B win | A lose      仅一种选择
        //
        // 3) rest = 3  cur = A --> A win | B lose      仅一种选择
        //
        // 4) rest = 4  cur = A --> A win | B lose      仅一种选择
        //
        // 5) rest = 5  cur = A --> 1) pick = 1 B win | A lose      两种选择
        //                      --> 2) pick = 4 B win | A lose      两种选择
        //
        // 6) rest = 6  cur = A --> 1) pick = 1 A win | B lose      两种选择
        //                      --> 2) pick = 4 A win | B lose      两种选择

        // 从 5 开始就循环 1~4
        if(rest < 5)
        {
            return ((rest==0) || (rest==2)) ? enemy : cur;
        }

        // rest >= 5
        // 假设 rest == 100;
        // cur:
        // 1) 吃 1份，剩99份给enemy
        // 2) 吃 4份，剩96份给enemy
        // 2) 吃16份，剩84份给enemy
        // 2) 吃64份，剩36份给enemy
        int pick = 1;
        while(pick <= rest)
        {
            if(f((rest - pick) , enemy) == cur)
            {
                return cur;
            }
            pick *= 4;
        }
    
        return enemy;
    }

public:
    string win(int n)
    {
        return f(n , "A");
    }

};

// 打表找规律：
// n: 0 win:B --->
// n: 1 win:A
// n: 2 win:B
// n: 3 win:A
// n: 4 win:A --->
// n: 5 win:B --->
// n: 6 win:A
// n: 7 win:B
// n: 8 win:A
// n: 9 win:A --->
// n:10 win:B
// n:11 win:A
// n:12 win:B
// n:13 win:A
// n:14 win:A

void f(int n)
{
    char cur = 'A';
    for(int i=0 ; i<n ; i++)
    {
        if((i%5)==0)
        {
            cur = 'B';
        }
        if((i%5)==1)
        {
            cur = 'A';
        }
        if((i%5)==2)
        {
            cur = 'B';
        }
        if((i%5)==3)
        {
            cur = 'A';
        }
        if((i%5)==4)
        {
            cur = 'A';
        }
        printf("n:%d win:%c" , i , cur);
    }
}

int main()  
{   
    SheepEatGrass seg;
    // 打表：
    for(int i=0 ; i<50 ; i++)
    {
        if(i<10)
        {
            cout << "n: " << i << " win:" << seg.win(i) << endl;
        }
        else
        {
            cout << "n:" << i << " win:" << seg.win(i) << endl;
        }
    }
    return 0;
}