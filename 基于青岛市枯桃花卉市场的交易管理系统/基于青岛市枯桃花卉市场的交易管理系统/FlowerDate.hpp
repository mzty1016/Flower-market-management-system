//
//  FlowerDate.hpp
//  基于青岛市枯桃花卉市场的交易管理系统
//
//  Created by 🍓XJK on 2019/12/7.
//  Copyright © 2019 🍓XJK. All rights reserved.
//

#ifndef FlowerDate_hpp
#define FlowerDate_hpp

#include <stdio.h>

//花卉上架日期
class FlowerDate {
public:
    FlowerDate();
    FlowerDate(int year, int month, int day);
private:
    int year; //花卉上架的年份
    int month; //花卉上架的月份
    int day; //花卉上架的日
};

#endif /* FlowerDate_hpp */
