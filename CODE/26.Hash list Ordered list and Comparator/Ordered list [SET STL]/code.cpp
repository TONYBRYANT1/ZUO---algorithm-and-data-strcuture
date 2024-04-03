// 有序表 
// 1）有序表内部比较器：有序表元素类型的实现中 运算符重载 bool operator< (const Employee& other) const
// 2）有序表外部比较器：另写一类，专门做比较器 EmployeeComparator
// 3）Lambda函数：不会写
#include<bits/stdc++.h>

using namespace std;

class Employee
{
public:
    int company;
    int age;

public:
    Employee(int c , int a) : company(c) , age(a) {}

    // 比较器一：
    // bool operator< (const Employee& other) const
    // {
    //     return 
    //     (this->company==other.company) ? 
    //     (this->age==other.age ? (addressof(*this) < addressof(other)) : (this->age < other.age)) // company 和 age 相同的前提下 比较(addressof(*this) < addressof(other))
    //     : (this->company < other.company);
    // }
};

// 比较器二：
class EmployeeComparator
{
public:
    bool operator() (const Employee& e1 , const Employee& e2)
    {
        return 
        (e1.company==e2.company) ? 
        (e1.age==e2.age ? (addressof(e1) < addressof(e2)) : (e1.age < e2.age)) // company 和 age 相同的前提下 比较(addressof(*this) < addressof(other))
        : (e1.company < e2.company);
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

    // sort(arr.begin() , arr.end());
    // 有序表
    set<Employee , EmployeeComparator> sett;
    // 向有序表中添加元素的类需要一定的规则
    for(const auto& e : arr)
    {
        sett.insert(e);
    }

    printf("sett.size() = %d\n" , sett.size());

    // 去重
    sett.insert(Employee(2 , 27));

    printf("sett.size() = %d\n" , sett.size());

    printf("====================================");
    return 0;
}