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
    HashTable();
    void AddFlower();
 private:
    vector<LNode*> first;
    int length;
};


#endif /* Hash_hpp */
