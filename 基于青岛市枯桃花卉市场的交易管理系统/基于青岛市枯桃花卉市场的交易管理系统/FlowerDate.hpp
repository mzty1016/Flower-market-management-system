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

//花卉上架日期类
class FlowerDate {
 public:
    FlowerDate(); //默认构造函数
    FlowerDate(int year, int month, int day); //进行初始化的构造函数
    FlowerDate(FlowerDate &flower_date); //复制构造函数
    void SetDateInfo(int year, int month, int day); //设置日期函数
    const int& YearInfo(); //返回年份信息
    const int& MonthInfo(); //返回月份信息
    const int& DayInfo(); //返回日信息
 private:
    int year; //花卉上架的年份
    int month; //花卉上架的月份
    int day; //花卉上架的日
};

#endif /* FlowerDate_hpp */
