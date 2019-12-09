//
//  Hash.hpp
//  基于青岛市枯桃花卉市场的交易管理系统
//
//  Created by 🍓XJK on 2019/12/7.
//  Copyright © 2019 🍓XJK. All rights reserved.
//

#ifndef Hash_hpp
#define Hash_hpp

#include <stdio.h>

class HashTable {
public:
  HashTable();
private:
  int length;
};

HashTable::HashTable() {
    length = 0;
}

#endif /* Hash_hpp */
