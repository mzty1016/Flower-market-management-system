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
#include <fstream>

#include "Flower.hpp"
#include "Global.hpp"

using namespace std;

//哈希表链地址处理法结点
typedef struct node{
    node() { next = NULL; };
    Flower *flower;
    struct node *next;
}LNode;
//哈希表类
class HashTable {
 public:
    HashTable(); //默认构造函数;
    void InitHashTable(); //读取文件信息建立哈希表
    const int Hash(const string &name) const; //哈希函数，返回一个哈希表的下标
    void AddFlower(LNode* &p, int times); //建立哈希表时向哈希表添加花卉,time为二次探测法探测次数
    void AddChain(int index, LNode* &p); //同名不同商家的花卉采用链地址法处理冲突
    bool DeleteFlower(string &flower_name, string &shop_name, int times); //下架花卉
    bool DeleteNode(int index, string &shop_name); //商家下架花卉时对同名花卉删除
    int SearchFlower(string &flower_name, int times); //在哈希表查找花卉并返回下标
    const int DetectSecond(const int index, int times) const; //不同名的花卉采用二次探测法处理冲突,time为二次探测法探测次数
    void SaveHashTable(); //程序结束时析构函数调用该函数将信息写回文件，实现信息保存
    ~HashTable(); //析构函数
    vector<LNode*> first;
 private:
    int length;
};

#endif /* Hash_hpp */
