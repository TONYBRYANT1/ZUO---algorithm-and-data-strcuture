// 比较器：
// 任何比较器都默认
// 如果返回负数认为o1的优先级更高
// 如果返回正数认为o2的优先级更高
// 任何比较器都是这样，所以利用这个设定，可以定制优先级怎么确定，也就是怎么比较
// 不再有大小的概念，就是优先级的概念

// 1）类中比较器
// 2）lambda比较器
#include<bits/stdc++.h>

using namespace std;

class Employee
{
public:
    int company;
    int age;

public:
    Employee(int c , int a) : company(c) , age(a) {}
};

// 比较器 1 
class EmployeeComparator
{
public:
    bool operator()(const Employee& o1 , const Employee& o2)
    {
        return o1.age < o2.age;
    }
};

int main()
{
    Employee s1(2, 27);
    Employee s2(1, 60);
    Employee s3(4, 19);
    Employee s4(3, 23);
    Employee s5(1, 35);
    Employee s6(3, 55);

    vector<Employee> arr = {s1 , s2 , s3 , s4 , s5 , s6};

    printf("比较器一：按年龄升序排列\n");

    sort(arr.begin() , arr.end() , EmployeeComparator());

    for(const auto e : arr)
    {
        printf("%d , %d\n" , e.company , e.age);
    }

    printf("===================================\n");

// 比较器 2

    printf("比较器二：按年龄降序排列\n");

    sort(arr.begin() , arr.end() , [](const Employee& a , const Employee& b){return b.age < a.age;});

    for(const auto e : arr)
    {
        printf("%d , %d\n" , e.company , e.age);
    }

    printf("===================================\n");

// 比较器 3

    printf("比较器三：先按公司，公司相同时按年龄\n");

    sort(arr.begin() , arr.end() , [](const Employee&a , const Employee&b){return (a.company==b.company) ? (a.age < b.age) : (a.company < b.company);});

    for(const auto e : arr)
    {
        printf("%d , %d\n" , e.company , e.age);
    }

    return 0;
}