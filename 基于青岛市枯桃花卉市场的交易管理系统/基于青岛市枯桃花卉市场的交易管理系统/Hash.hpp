//
//  Hash.hpp
//  基于青岛市枯桃花卉市场的交易管理系统
//
//  Created by 🍓XJK on 2019/12/7.
//  Copyright © 2019 🍓XJK. All rights reserved.
//

#ifndef Hash_hpp
#define Hash_hpp

#include <iostream>
#include <vector>
#include <cmath>

#include "Flower.hpp"
#include "Global.hpp"

using namespace std;

//哈希表链地址处理法结点
typedef struct node{
    Flower *flower;
    struct node *next;
}LNode;
//哈希表类
class HashTable {
 public:
    HashTable(); //默认构造函数;
    void InitHashTable(const string &file_name); //读取文件信息建立哈希表
    int Hash(const string &str); //哈希函数，返回一个哈希表的下标
    void AddChain(int index, string &f_name, string &s_name, string &p_color, float f_price, int yy, int mm, int dd); //同名不同商家的花卉采用链地址法处理冲突
    const int DetectSecond(const int index) const ; //不同名的花卉采用二次探测法处理冲突
    void SaveHashTable(); //程序结束时析构函数调用该函数将信息写回文件，实现信息保存
    ~HashTable(); //析构函数
 private:
    vector<LNode*> first;
    int length;
};


#endif /* Hash_hpp */
