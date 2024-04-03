// 汉诺塔问题：
// 要求：
// 1）只能 小压大
// 2）只能移动最上方的盘子(每次一个盘)
//
// n 层汉诺塔，最有轨迹：(2^n - 1)步

#include<bits/stdc++.h>

using namespace std;

class Hanoi_tower
{
private:
    void f(int i , string from , string to , string other)
    {
        if(i==1)
        {
            cout << "移动圆盘 1 从 " << from << " 到 " << to << endl;
            return;
        }
        else
        {
            f(i-1 , from , other , to);
            cout << "移动圆盘 " << i << " 从 "<< from << " 到 " << to << endl;
            f(i-1 , other , to , from);
            return;
        }
    }
public:
    void hanoi(int n)
    {
        if(n>0)
        {
            f(n , "左" , "右" , "中");
        }
    }
};

using namespace std;

int main()
{
    int n=3;
    Hanoi_tower ht;
    ht.hanoi(n);
    return 0;
}