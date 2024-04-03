#include <iostream>
#include <sstream>
#include <string>

int main() 
{
    // 创建一个空的 stringstream 对象
    std::stringstream ss;

    // 写入数据到 stringstream 中
    int num = 123;
    double pi = 3.14159;
    ss << "Integer: " << num << ", Pi: " << pi;

    // 从 stringstream 中读取字符串
    std::string str;
    ss >> str;
    std::cout << "Read from stringstream: " << str << std::endl; // 输出 "Integer:"

    // 清空 stringstream
    ss.str("");
    ss.clear(); // 清除错误状态

    // 格式化数据并写入到 stringstream 中
    ss << "Integer: " << num << ", Pi: " << std::fixed << pi;

    // 从 stringstream 中读取完整字符串
    std::string fullString = ss.str();
    std::cout << "Full string from stringstream: " << fullString << std::endl;

    return 0;
}