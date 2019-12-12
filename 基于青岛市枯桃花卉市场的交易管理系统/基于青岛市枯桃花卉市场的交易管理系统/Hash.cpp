//
//  Hash.cpp
//  基于青岛市枯桃花卉市场的交易管理系统
//
//  Created by 🍓XJK on 2019/12/7.
//  Copyright © 2019 🍓XJK. All rights reserved.
//

#include "Hash.hpp"

//默认构造函数
HashTable::HashTable() : first(MAXSIZE) {
    length = 0; //哈希表长度初始化为0
    for (int i = 0; i < 500; i++) {
        first[i] = NULL; //将哈希表每个位置的结点指针都指向NULL
    }
}

void HashTable::AddFlower() {
    int frt, sed, sum;
    printf("请输入花卉名称");
    string f_name;
    cin>>f_name;
    string d;
    frt = f_name[0];
    sed = f_name[1];
    frt = abs(frt)%10;
    sed = abs(sed)%100;
    sum = (sed*10+frt)%500;
    if (first[sum] == NULL) {
        LNode *p = new LNode;
        first[sum] = p;
        p->flower = new Flower();
        p->flower->SetFlowerInfo(f_name, d, d, d, 66.88 ,1, 2, 3);
        p->next = NULL;
        
    }
}


