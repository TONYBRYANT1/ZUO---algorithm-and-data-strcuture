// 位图：
//
// 0）概念描述：位图的实现
// Bitset(int n)：初始化位图的大小，只支持 0 ~ n-1 所有数字的增删改查
// void add(int num)：把num加入到位图
// void remove(int num)：把num从位图中删除
// void reverse(int num)：如果位图里没有num，就加入；如果位图里有num，就删除
// boolean contains(int num)：查询num是否在位图中
// 将采用对数器验证，当你找不到测试链接的时候就用对数器验证，而且对数器验证更稳妥、更能练习debug能力
//
// 1）准备部分：
// 如果要表示 0 ~ 100 之间的数出现还是没出现
// int[4] = {a , b , c , d}
//           0 , 1 , 2 , 3
//
// 位图元素：
// a:  0 ~ 31   (a 数字有32位)
// b: 32 ~ 63   (b 数字有32位)
// c: 64 ~ 95   (c 数字有32位) 64 65 66 67 68 69 70 71 72 73 74
// d: 96 ~ 127  (d 数字有32位)  0  1  2  3  4  5  6  7  8
//
// 2）有数 x，怎么找到 x 是否存在的标记呢？
//          1）n = x/32 找到 x 属于哪一个位图元素
//             eg: x = 72
//                 n = x/32 = 72/32 = 2
//                 说明 x 在 int[n] = int[2] = c，也就是第三个为位图元素上存着（从 0 开始）
//          2）m = x%32 找到 x 属于位图元素 int[n] 的第几位上
//             eg: x = 72
//                 m = x%32 = 72%32 = 8
//                 说明 x 在 位图元素 int[n] 的第 m 位上（从 0 开始）

// 技巧：
// 1）(a/b)向上取整：
// 前提条件：a>=0 && b>0
//      1）方法：
//                  a/b上取整 = (a+b-1)/b
//
//      2）解释：
//                  1）当 a = k*b 时：
//                     (a+b-1)/b = ( (k+1)b-1 )/b = k  // 因为自动向下取整
//                  2）当 a = k*b+m (1<= m <b)时：
//                     (a+b-1)/b = ( (k+1)b+(m-1) )/b = (k+1)  // 此时 0< (m-1) < (b-1)

#include<bits/stdc++.h>

using namespace std;

int* BitMap;

// 当 n =  1 ~ 32 时，只用 1 个位图元素
// 当 n = 33 ~ 64 时，只用 2 个位图元素
// ==> 计算位图大小：(n/32)向上取整
void BitMap_initialization(int n)
{
    int size = ((n + (32-1))/32);
    BitMap = new int[size];
    
    return;
}

// 数字标记 |
void BitMap_Add(int x)
{   
    // 将 [0] 位的 1 移动到对应的位上 然后 '或'
    BitMap[x/32] |= (1<<(x%32));
    // BitMap[x/32] = BitMap[x/32] | (1<<(x%32));
}

// 删除数字标记 &：无论在不在位图中，都将标记改为 0
// eg: 0 0 1 0 1 0 1 1
//     7 6 5 4 3 2 1 0
// 
// 想去掉 [5] 上的标记
//
// 方案：
// 1）将 [0] 上的 1 挪到 [5] 上
//    
//     0 0 1 0 0 0 0 0
//     7 6 5 4 3 2 1 0
//
// 2）~
//
//     1 1 0 1 1 1 1 1
//     7 6 5 4 3 2 1 0
//
// 3）&
//
//     0 0 1 0 1 0 1 1
//     1 1 0 1 1 1 1 1  &
//     ------------------
//     0 0 0 0 1 0 1 1 
//
//     7 6 5 4 3 2 1 0
void BitMap_Remove(int x)
{
    BitMap[x/32] &= ( ~(1<<(x%32)) );
    // BitMap[x/32] = BitMap[x/32] & (~(1<<(x%32)));
}

// 反转标记：
// 1）^1 反转作用：
//          1^1 = 0，0^1 = 1;
//
// 2）^0 不变作用：
//          1^0 = 1，0^0 = 0;
void BitMap_Reverse(int x)
{
    BitMap[x/32] ^= (1<<(x%32));
    // BitMap[x/32] = BitMap[x/32] ^ (1<<(x%32));
}

// 该元素是否被标记
// 找到位图元素，将对应的位移动到 [0] 位，&1
bool BitMap_Contains(int x)
{
    // BitMap[x/32]：位图元素
    // BitMap[x%32]：对应的位
    return (( (BitMap[x/32]) >> (x%32) ) & 1) == 1;
}   

int main()
{
    // 对数器 --- 验证 BitMap 正确性
    srand((unsigned)time(NULL));
    int n=1000;
    int TestTimes = 100000;
    printf("测试开始：\n");

    // 实现位图结构：
    BitMap_initialization(n);
    set<int> MySet;

    // 直接用 Set 做对比测试
    printf("调用阶段开始：\n");
    while(TestTimes--)
    {
        int decide = rand()%3; 
        int number = rand()%n; 
        // number: 0 ~ n-1  等概率得到
        // decide: 0、1、2  等概率得到
        if(decide == 0)
        {
            BitMap_Add(number);
            MySet.insert(number);
        }
        else if(decide == 1)
        {
            BitMap_Remove(number);
            MySet.erase(number);
        }
        else
        {
            BitMap_Reverse(number);

            // 没有数
            if(MySet.find(number) == MySet.end())
            {
                MySet.insert(number);
            }
            // 有数
            else 
            {
                MySet.erase(number);
            }
        }

    }
    printf("调用阶段结束。\n");

    printf("验证阶段开始：\n");
    for(int i=0 ; i<n ; i++)
    {
        if(BitMap_Contains(i) == true)
        {
            if(MySet.find(i) == MySet.end())
            {
                printf("出错了!\n");
                break;
            }
        }
        // BitMap_Contains(i) == false
        else
        {
            if(MySet.find(i) != MySet.end())
            {
                printf("出错了!\n");
                break;
            }
        }
    }

    printf("验证阶段结束了\n");

    printf("测试结束了\n");

    return 0;
}