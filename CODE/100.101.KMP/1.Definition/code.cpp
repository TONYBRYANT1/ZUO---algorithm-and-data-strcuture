// 一、next 数组定义：
// 不含当前下标字符，前面字符串中前后缀最大匹配长度(不能含整体)
//
// eg:
// string: a  a b a a b s a a b a  a  a  x
// index:  0  1 2 3 4 5 6 7 8 9 10 11 12 13 
// next:   -1 0 1 0 1 2 3 0 1 2 3  4  5  2

// 二、假设已经有了 next 数组，看看匹配过程是如何因 next 数组加速的
// 
// eg:
// s2的 next 数组：
// s2:    a a b a a b c a a b a  a  b  t
// index: 0 1 2 3 4 5 6 7 8 9 10 11 12 13
// next: -1 0 1 0 1 2 3 0 1 2 3  4  5  6
//
// s1:    a a b a a b c a a b a  a  b  e  ...
// index: 0 1 2 3 4 5 6 7 8 9 10 11 12 13
// s2:    a a b a a b c a a b a  a  b  t
// index: 0 1 2 3 4 5 6 7 8 9 10 11 12 13
//
// 1)
// ==> 发现 index[13] 不同，查 s2 next数组：index[13].next = 6
// ==> 跳转继续比对
//
// s1:    a a b a a b c a a b a  a  b  e  ...
// index: 0 1 2 3 4 5 6 7 8 9 10 11 12 13
// s2:                  a a b a  a  b  c  a a b a  a  b  t
// index:               0 1 2 3  4  5  6  7 8 9 10 11 12 13
//
// 2)
// ==> 发现 index[6] 不同，查 s2 next数组：index[6].next = 3
// ==> 跳转继续比对
//
// s1:    a a b a a b c a a b a  a  b  e  ...
// index: 0 1 2 3 4 5 6 7 8 9 10 11 12 13
// s2:                        a  a  b  a  a b c a a b a  a  b  t
// index:                     0  1  2  3  4 5 6 7 8 9 10 11 12 13
//
// 3)
// ==> 发现 index[3] 不同，查 s2 next数组：index[3].next = 0
// ==> 跳转继续比对
//
// s1:    a a b a a b c a a b a  a  b  e  ...
// index: 0 1 2 3 4 5 6 7 8 9 10 11 12 13
// s2:                                 a  a b a a b c a a b a  a  b  t
// index:                              0  1 2 3 4 5 6 7 8 9 10 11 12 13
//
// 4)
// ==> 发现 index[0] 不同，查 s2 next数组：index[0].next = -1
// ==> 没有一样的部分了只能将 s2[0] 与 s1[14] 试着匹配了
//

// 原理分析： 
// 
// eg:
// s1:    1 2 3 4 5 6 7 5 5 5 1 2 3 4 5 6 7 5 ...
// index: a ......... b     e c ......... d i ...
//
// s2:    1 2 3 4 5 6 7 5 5 5 1 2 3 4 5 6 7 1 ...
// index: 0 ......... 6 7     g ......... h j ...
// next:                                    7 
//
// ==> s1[i] != s2[j]
//
// s1:    1 2 3 4 5 6 7 5 5 5 1 2 3 4 5 6 7 5 ...
// index: a ......... b     e c ......... d i ...
//
// s2:                        1 2 3 4 5 6 7 5 5 5 1 2 3 4 5 6 7 1 ...
// index:                     0 ......... 6 7     g ......... h j ...
//
//
// 问题：当 s1[i] != s2[j]
//      1) 为什么可以直接跳转 去判断 s1[i] =?= s2[7]
//      2) 为什么可以不比较 s1[2]...s1[e](作为头部) 和 s2[0](作为头部)，和 其后续判断?
//
// 回答:
//      1) 因为有 next 数组：前后缀最大匹配长度
//      2) 假设 s1[2]...s1[e](作为头部) 可以和 s2 匹配上，可以推出 s2[j].next > 7
//         因为 next 为正确值 所以 s1[2]...s1[e](作为头部) 决不能和 s2 匹配上

// 三、求 next 数组：
//
// 1) 特殊：前三项
// next[0] = -1
// next[1] = 0 (不能含有自身)
// next[2] = str[0]==str[1] ? 1 : 0 (就看前两个字符是否相等)
//
// 2）一般：
//    1）不用跳：
//               对于 e 来说，直接看 s2[next[s]] =?= s2[index[e]-1]
//              
//               next[i] = next[i-1] + 1 (最多+1，不可能更大，可以用反证法举例说明)
//                                v               v
//               s: a b a t a b a s a b a t a b a s | e 
//            next: 0 1 2 3 4 5 6 7               7   7+1=8 
//
//    2）跳一次：
//              v <---- v <-----------  v
// s2:    a b a t a b a s a b a t a b a t | e
//        |     |                 |     |               
//        -------                 -------
// index: 0 1 2 3 4 5 6 7                  
// next:                3               7   4
//
//
//    2）跳两次：
//          v < v <-- v <-------------- v
// s2:    a b a t a b a s a b a t a b a b | e
//        | |                         | |               
//        ---                         ---
// index: 0 1 2 3 4 5 6 7                  
// next:        1       3               7   2
//
//    3）跳三次：
//        v<v < v <---- v <------------ v
// s2:    a b a t a b a s a b a t a b a a | e
//        |                             |               
//        -                             -
// index: 0 1 2 3 4 5 6 7                  
// next:    0   1       3               7   1
//
//
//    4）跳到头了：
//     <-- v<v < v <---- v <------------ v
// s2:     a b a t a b a s a b a t a b a f | e
// index:  0 1 2 3 4 5 6 7                  
// next:  -1 0   1       3               7   0
//
// 为什么可以往前跳？拿条一次举例：
// 跳一次：
//              v <---- v <-----------  v
// s2:    a b a t a b a s a b a t a b a t | e
//        |     |                 |     |               
//        -------                 -------
// index: i . a . b . j   k ..... c . l
// next:                3               7   4
//
// 当流程到达 e 位置时，为了求 next[index[e]] 首先肯定要看看前一个字符的next
// next[index[t]] == 7，说明在 t 之前有 7 个字符首尾相同，看看 t 的加入会不会让 next值变大
// 不幸的是，s[index[t]] != s[index[s]]，所以答案不可能为 8，看看有没有稍微短点的字符串可以对应
// 又因 s[i...j] == s[k...l]，所以想找短一些的对应字符串，变成了找 next[index[s]] 的对应字符串 s[i..a] 和 s[b..j] 和 s[c..l]
//
// 时间复杂度分析：
//                         i           i-cn
// 匹配成功：              增加          不变
// 匹配不成功，向前跳转：   不变          增加
// 跳到头了：              增加          增加
// i(m) + i-cn(m) = O(m)