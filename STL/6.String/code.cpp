#include <iostream>
#include <string>

using namespace std;

int main() {
    // 创建一个空字符串
    string str;

    // 判断字符串是否为空
    if (str.empty()) {
        cout << "字符串为空" << endl;
    }

    // 给字符串赋值
    str = "Hello, world!";

    // 获取字符串长度
    cout << "字符串长度：" << str.length() << endl;

    // 输出字符串内容
    cout << "字符串内容：" << str << endl;

    // 使用下标访问字符串中的字符
    cout << "第一个字符：" << str[0] << endl;

    // 使用迭代器遍历字符串
    cout << "遍历字符串：" << endl;
    for (auto it = str.begin(); it != str.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // 字符串拼接
    string anotherStr = " How are you?";
    str += anotherStr;
    cout << "拼接后的字符串：" << str << endl;

    // 字符串比较
    string compareStr = "Hello, world! How are you?";
    if (str == compareStr) {
        cout << "两个字符串相同" << endl;
    } else {
        cout << "两个字符串不同" << endl;
    }

    // 字符串查找
    string subStr = "world";
    size_t found = str.find(subStr);
    if (found != string::npos) {
        cout << "子串 \"" << subStr << "\" 在字符串中的位置：" << found << endl;
    } else {
        cout << "未找到子串 \"" << subStr << "\"" << endl;
    }

    // 截取子串
    string substr = str.substr(7, 5); // 从位置7开始，长度为5的子串
    cout << "截取的子串：" << substr << endl;

    return 0;
}
