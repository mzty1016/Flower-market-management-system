//
//  Flower.hpp
//  基于青岛市枯桃花卉市场的交易管理系统
//
//  Created by 🍓XJK on 2019/12/7.
//  Copyright © 2019 🍓XJK. All rights reserved.
//

#ifndef Flower_hpp
#define Flower_hpp

#include <stdio.h>
#include <string>

#include "FlowerDate.hpp"

using namespace std;

class Flower {
 public:
    Flower();
 private:
    string flower_name; //花卉名称
    string shop_name; //花卉所在的店名
    float price; //花卉价格
    FLowerDate flower_date; //花卉上架日期
    
};

#endif /* Flower_hpp */
