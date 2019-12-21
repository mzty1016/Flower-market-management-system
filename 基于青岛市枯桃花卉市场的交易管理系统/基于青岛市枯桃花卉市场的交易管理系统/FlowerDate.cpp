//
//  FlowerDate.cpp
//  基于青岛市枯桃花卉市场的交易管理系统
//
//  Created by 🍓XJK on 2019/12/7.
//  Copyright © 2019 🍓XJK. All rights reserved.
//

#include "FlowerDate.hpp"
//默认构造函数
FlowerDate::FlowerDate() {
    year = 0;
    month = 0;
    day = 0;
}
//进行初始化的构造函数
FlowerDate::FlowerDate(int year, int month, int day) {
    this->year = year;
    this->month = month;
    this->day = day;
}
//复制构造函数
FlowerDate::FlowerDate(const FlowerDate &flower_date) {
    year = flower_date.year;
    month = flower_date.month;
    day = flower_date.day;
}
//设置日期函数
void FlowerDate::SetDateInfo(int year, int month, int day) {
    this->year = year;
    this->month = month;
    this->day = day;
}
//返回年份信息
const int& FlowerDate::YearInfo() {
    return year;
}
//返回月份信息
const int& FlowerDate::MonthInfo() {
    return month;
}
//返回年份信息
const int& FlowerDate::DayInfo() {
    return day;
}
//重载<<运算符
ostream& operator << (ostream &out, FlowerDate flower_date) {
    out<<left<<setw(2)<<flower_date.YearInfo()<<"/"<<left<<setw(2)<<flower_date.MonthInfo()<<"/"<<left<<setw(2)<<flower_date.DayInfo()<<endl;
    return out;
}
