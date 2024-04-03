// 线段重叠
#include<bits/stdc++.h>

using namespace std;

const int N = 1e4+10;

// 二维数组不能用sort，出问题了
typedef struct Line
{
    int x , y;
}Line;

Line line[N];
int n , MinHeap[N] , size; // line[i][0] line[i][1]

// 自定义小根堆
void swap(int& x , int& y)
{
    int temp = x;
    x = y;
    y = temp;
}

void MinHeapInsert(int i)
{
    // 子结点 < 父结点
    while(MinHeap[i] < MinHeap[(i-1)/2])
    {
        swap(MinHeap[i] , MinHeap[(i-1)/2]);
        i = (i-1)/2;
    }
    return;
}

void MinHeapify(int x)
{
    int left = (x<<1) + 1;
    while(left <= size-1)
    {
        int right = left+1;
        // 找到 左右孩子中最小的一个
        int minn_index = (right <= size-1)&&(MinHeap[right] < MinHeap[left]) ? right : left;
        minn_index = MinHeap[minn_index] < MinHeap[x] ? minn_index : x;
        if(minn_index == x)
        {
            break;
        }
        else
        {
            swap(MinHeap[minn_index] , MinHeap[x]);
            x = minn_index;
            left = (x<<1) + 1;
        }
    }
    return;
}

void add(int x) // MinHeap[0 , size-1]
{
    int i=size; // 新加入数据的位置
    MinHeap[i] = x;
    size++;
    MinHeapInsert(i);
}

void pop()
{
    // 交换 MinHeap[0] 和 MinHeap[size-1] , size--
    swap(MinHeap[0] , MinHeap[size-1]);
    size--;
    MinHeapify(0);
}

int Compute()
{
    // 清空堆
    size=0; // heap-->size 用来让堆保持规则的

    // 一共 n 条线段，line[0][0] , line[0][1]...
    // 所有线段，根据开始位置排序，结束位置不考虑
    // 比较器 Lambda 函数
    // 函数体中 [] 是为了访问某一行中具体的某一列的元素
// 关于迭代器传递： 在 C++ 中，std::sort 函数接受的参数是迭代器，而不是地址。对于一维数组，你可以使用数组的起始位置和结束位置来创建迭代器，例如 arr 和 arr + sizeof(arr) / sizeof(arr[0])。对于二维数组，你可以使用数组的每一行的起始位置和结束位置来创建迭代器。

// 关于 Lambda 函数： Lambda 函数是一个匿名函数，它可以根据你的需要接受不同的参数。在排序函数 std::sort 中，Lambda 函数的作用是比较两个元素的大小。对于一维数组和二维数组，Lambda 函数中使用的参数和操作可能不同。

// 对于一维数组，Lambda 函数只需接受两个元素的值，因为一维数组中的元素本身就是可比较的，例如 [](int a, int b) { return a < b; }，这里的 a 和 b 是数组中的元素值，不需要使用 [] 来访问数组元素。

// 对于二维数组，如果要按照某个维度进行排序，你可能需要在 Lambda 函数中使用 [] 来访问数组的子数组，以获取需要比较的值。例如，如果想按照二维数组的第一个元素进行排序，可以这样写 Lambda 函数：[](const auto& a, const auto& b) { return a[0] < b[0]; }。这里的 a 和 b 是指向二维数组的子数组的指针，因此需要使用 [] 来访问子数组的元素。

// 所以，Lambda 函数中是否使用 [] 取决于你要比较的元素是直接的值，还是需要从数组中取出。

// 一维数组：arr[ 1 , 2 , 3     ,     6 , 7 , 8 , 9 , 10 ] // 直接比较数值 
//                       ^           ^
//                       |           |
//                      it_1        it_2
//
// auto f = [](const auto& a , const auto& b){ return a > b }; // a 是具体的值

// 二维数组：arr[ [1 , 5]  ,  [2 , 3]  ,  [3 , 7]  ,  [4 , 6]  ,  [1 , 9] ] // 需要
//                arr[0]  ,   arr[1]  ,   arr[2]  ,   arr[3]  ,   arr[4]
//                  ^           ^ 
//                  |           |
//                 it_1        it_2    
//          
// auto f = [](const auto& a , const auto& b){ return a[0] > b[0] }; // a 是 arr[i]，需要 a[j] 来访问具体的值

    auto f = [](const auto& a , const auto& b)
    {
        return a.x < b.x; // true - a在前
//                           false - b 在前
    };
    
    sort(line , line+n , f);

    int ans=0;
    // 任何一重叠区域，一定有一个x作为左边界，所以我们以每一个 x 的视角来看当前 x 最多可以和几个y(小根堆中的)组和成为重叠
    // 每遍历一个线段，栈中记录的都是每一段的y值
    // 一个线段遍历结束后，栈中的y值都是可以超越当前线段的x值的 ==> 覆盖/有重叠部分
    for(int i=0 ; i<n ; i++)
    {
        // i：line[i][0] , line[i][1]
        // 新线段的左端点大于等于当前小根堆堆顶元素
        while(size>0 && MinHeap[0] <= line[i].x)
        {
            pop();
        }
        add(line[i].y);
        ans = max(ans , size);
    }
    return ans;
}

int main()
{
    scanf("%d" , &n);
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d%d" , &line[i].x , &line[i].y);
    }

    printf("%d" , Compute());

    return 0;
}

// 一、算法：
//
// 任何一重叠区域，一定有一个x作为左边界，所以我们以每一个 x 的视角来看当前 x 最多可以和几个y(小根堆中的)组和成为重叠
// 每遍历一个线段，栈中记录的都是每一段的y值
// 一个线段遍历结束后，栈中的y值都是可以超越当前线段的x值的 ==> 覆盖/有重叠部分

// 二、为什么先要将线段排序：
// 简化处理流程： 排序可以将线段按照其起始位置进行排序，这样就能够保证在处理每一个线段时，可以从左到右依次处理，而不需要考虑线段的顺序。
// 便于找到重叠部分： 排序后的线段有序排列，可以更容易地找到重叠的部分。在这个算法中，使用小根堆来记录当前线段的结束位置，当处理一个新的线段时，可以通过小根堆快速找到与该线段相交的线段，从而确定重叠的部分。
// 优化算法效率： 排序后的线段能够更有效地利用算法的特性，例如在本算法中，可以通过小根堆来记录当前线段的结束位置，这样就可以在 O(log n) 的时间内找到与当前线段相交的线段，从而提高算法的效率。
// 总的来说，排序是为了让算法更加简洁、高效地处理线段，并更容易找到重叠的部分，从而实现正确且高效的覆盖区间计算。

// 三、Complexity：
//      1）Time Complexity：O(N * log2(N)) // 每个数只 进堆：O(log2(N)) 和 出堆：O(1) 一次 
//      2）Space Complexity：O(N)

// 四、priority_queue 和 sort
// priority_queue 示例：
// 在 priority_queue 中，元素的排列顺序取决于比较函数的返回值。因此，如果返回值是 a < b，则 priority_queue 会按照从小到大的顺序排列元素，形成小根堆。如果返回值是 a > b，则 priority_queue 会按照从大到小的顺序排列元素，形成大根堆。在你的第一个示例中，lambda函数返回的是 a < b，因此得到的是小根堆。

// sort 示例：
// 在使用 sort 函数进行排序时，lambda函数返回的是 a < b 或 a.x < b.x，这表示如果 a 应该排在 b 前面，则返回 true；否则返回 false。在这里，返回 true 的元素会排在前面，因此会按照从小到大的顺序排列元素，形成升序序列。