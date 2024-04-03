#include<bits/stdc++.h>
using namespace std;

class AllOne 
{
public:
    // 桶结构
    typedef struct Bucket
    {
        int times; // 出现频率
        unordered_set<string> str; // 出现该频率的字符串
        struct Bucket* left;
        struct Bucket* right;
        Bucket(int t , string s) : times(t) , left(nullptr) , right(nullptr)
        {
            str.insert(s);
        }
    }Bucket , *P;

    void Insert(P Bucket_1 , P Bucket_2)
    {
        // 建立 Bucket_1->right 与 Bucket_2 的联系
        Bucket_2->right = Bucket_1->right;
        Bucket_1->right->left = Bucket_2;
        // 建立 Bucket_1 与 Bucket_2 的联系
        Bucket_2->left = Bucket_1;
        Bucket_1->right = Bucket_2;
    }   

    void Remove(P Bucket)
    {
        // 记录该桶的左右桶
        P Left_Bucket = Bucket->left;
        P Right_Bucket = Bucket->right;
        // 左右桶建立联系
        Left_Bucket->right = Right_Bucket;
        Right_Bucket->left = Left_Bucket;
        // 删除该桶
        delete Bucket;
    }

public:
    // 桶体系的首尾指针 --- 基石
    P H , T;
    unordered_map<string , P> Sft; // Sft：String Frequency Table
public:
    AllOne() 
    {
        // 创造基石(桶头 桶尾)
        H = new Bucket(0 , "");
        T = new Bucket(INT_MAX , "");
        // 建立联系
        H->right = T;
        T->left = H;
    }
    
    void inc(string key) 
    {
        // 没存过 key
        if(Sft.find(key) == Sft.end())
        {
            // 入桶
            //      1）有词频为 1 的桶
            if(H->right->times == 1)
            {
                // 入桶
                H->right->str.insert(key);
                // 更新词频统计表Sft
                Sft[key] = H->right;
            }
            // 没有词频为 1 的桶
            else
            {
                // 创建桶
                P New_Bucket = new Bucket(1 , key);
                // 插入桶体系
                Insert(H , New_Bucket);
                // 更新词频统计表Sft
                Sft[key] = New_Bucket;
            }
        }
        // 存过 key
        else
        {
            // 记录 key 所对应桶的位置
            P Key_Bucket = Sft[key];
            // key 所在的桶的右边有 key对应词频+1 的桶
            if(Key_Bucket->right->times == Key_Bucket->times+1)
            {
                // 将 key 从 Key_Bucket 移动到 Key_Bucket->right 中
                Key_Bucket->right->str.insert(key);
                // 更新词频统计表Sft
                Sft[key] = Key_Bucket->right;
                // 删除原桶的记录
                Key_Bucket->str.erase(key);
                // 如果 Key_Bucket 中没有元素了 -> 销毁原有的 Key_Bucket
                if(Key_Bucket->str.empty())
                {
                    Remove(Key_Bucket);
                }
            }
            // key 所在的桶的右边没有 key对应词频+1 的桶
            else
            {
                // 创建桶
                P New_Bucket = new Bucket(Key_Bucket->times+1 , key);
                // 插入桶体系
                Insert(Key_Bucket , New_Bucket);
                // 更新词频统计表Sft
                Sft[key] = New_Bucket;
                // 删除原桶的记录
                Key_Bucket->str.erase(key);
                // 如果 Key_Bucket 中没有元素了 -> 销毁原有的 Key_Bucket
                if(Key_Bucket->str.empty())
                {
                    Remove(Key_Bucket);
                }
            }
        }
    }
    
    void dec(string key) 
    {
        // 没存过 key
        if(Sft.find(key) == Sft.end())
        {
            return;
        }
        // 存过 key
        else
        {
            // 记录 key 所对应的桶 Key_Bucket
            P Key_Bucket = Sft[key];
            // key 的词频为 1
            if(Sft[key]->times == 1)
            {
                // 更新词频统计表Sft
                Sft.erase(key);
                // 删除原桶的记录
                Key_Bucket->str.erase(key);
                // 如果 Key_Bucket 中没有元素了 -> 销毁原有的 Key_Bucket
                if(Key_Bucket->str.empty())
                {
                    Remove(Key_Bucket);
                }
            }
            // key 的词频不为 1
            else
            {
                // key 所在的桶的左边有 key对应词频-1 的桶
                if(Key_Bucket->left->times == Key_Bucket->times-1)
                {
                    // 将 key 从 Key_Bucket 移动到 Key_Bucket->left 中
                    Key_Bucket->left->str.insert(key);
                    // 更新词频统计表Sft
                    Sft[key] = Key_Bucket->left;
                    // 删除原桶的记录
                    Key_Bucket->str.erase(key);
                    // 如果 Key_Bucket 中没有元素了 -> 销毁原有的 Key_Bucket
                    if(Key_Bucket->str.empty())
                    {
                        Remove(Key_Bucket);
                    }
                }
                // key 所在的桶的左边没有 key对应词频-1 的桶
                else
                {
                    // 创建桶
                    P New_Bucket = new Bucket(Key_Bucket->times-1 , key);
                    // 插入桶体系
                    Insert(Key_Bucket->left , New_Bucket);
                    // 更新词频统计表Sft
                    Sft[key] = New_Bucket;
                    // 删除原桶的记录
                    Key_Bucket->str.erase(key);
                    // 如果 Key_Bucket 中没有元素了 -> 销毁原有的 Key_Bucket
                    if(Key_Bucket->str.empty())
                    {
                        Remove(Key_Bucket);
                    }
                }
            }
        }
    }
    
    string getMaxKey() 
    {
        return *T->left->str.begin();
    }
    
    string getMinKey() 
    {
        return *H->right->str.begin();
    }
};