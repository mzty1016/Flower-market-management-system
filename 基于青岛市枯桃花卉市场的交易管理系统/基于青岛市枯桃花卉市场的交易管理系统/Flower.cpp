//
//  Flower.cpp
//  基于青岛市枯桃花卉市场的交易管理系统
//
//  Created by 🍓XJK on 2019/12/7.
//  Copyright © 2019 🍓XJK. All rights reserved.
//

#include "Flower.hpp"

//花类********************************************************************
//默认构造函数
Flower::Flower() {
    flower_name = "";
    shop_name = "";
    petal_color = "";
    flower_price = 0;
    //flower_date调用默认构造函数
}
//进行初始化的构造函数
Flower::Flower(string &f_name, string &s_name, string &p_color, float f_price, int yy, int mm, int dd) : flower_date(yy, mm ,dd) {
    flower_name = f_name;
    shop_name = s_name;
    petal_color = p_color;
//    leaf_color = l_color;
    flower_price = f_price;
}
//设置花卉信息
void Flower::SetFlowerInfo(string &f_name, string &s_name, string &p_color, float f_price, int yy, int mm, int dd) {
    flower_name = f_name;
    s_name = s_name;
    petal_color = p_color;
//    leaf_color = l_color;
    flower_price = f_price;
    flower_date.SetDateInfo(yy, mm, dd);
}
//修改花卉价格
void Flower::ModifyFlowerPrice(const float &f_p) {
    flower_price = f_p;
}
//修改花卉上架日期
void Flower::ModifyFlowerDate(const FlowerDate &f_date) {
    flower_date = f_date;
}
//修改花卉的花瓣颜色
void Flower::ModifyPetalColor(const string &p_color) {
    petal_color = p_color;
}
////修改花卉的叶子颜色
//void Flower::ModifyLeafColor(const string& l_color) {
//    leaf_color = l_color;
//}
//返回花卉名称
const string& Flower::FlowerNameInfo() const {
    return flower_name;
}
//返回花卉所在的店名
const string& Flower::ShopNameInfo() const {
    return shop_name;
}
//返回花卉价格
const float& Flower::FlowerPriceInfo() const {
    return flower_price;
}
//返回花卉上架日期
const FlowerDate& Flower::FlowerDateInfo() const {
    return flower_date;
}
//返回花卉的花瓣颜色
const string& Flower::PetalColorInfo() const {
    return petal_color;
}
////返回花卉的叶子颜色
//const string& Flower::LeafColorInfo() const {
//    return leaf_color;
//}
//花类********************************************************************


//观叶花类*****************************************************************
////默认构造函数
//FoliageFlower::FoliageFlower() {
//    leaf_color = "";
//    //其余初始化调用基类默认构造函数
//}
////进行初始化的构造函数
//FoliageFlower::FoliageFlower(string &f_name, string &s_name, float f_price, int yy, int mm, int dd, string &l_color) {
//    SetFlowerInfo1(f_name, s_name, f_price, yy, mm, dd, l_color);
//}
////设置花卉信息
//void FoliageFlower::SetFlowerInfo1(string &f_name, string &s_name, float f_price, int yy, int mm, int dd, string &l_color) {
//    Flower::SetFlowerInfo(f_name, s_name, f_price, yy, mm, dd);
//    leaf_color = l_color;
//}
////修改观叶植物叶子颜色
//void FoliageFlower::ModifyLeafColor(const string& l_color) {
//    leaf_color = l_color;
//}
////返回观叶植物叶子颜色
//const string& FoliageFlower::LeafColorInfo() const {
//    return leaf_color;
//}
//观叶花类*****************************************************************


//观花花类*****************************************************************
////默认构造函数
//PetalsFlower::PetalsFlower() {
//    petal_color = "";
//    //其余初始化调用基类默认构造函数
//}
////进行初始化的构造函数
//PetalsFlower::PetalsFlower(string &f_name, string &s_name, float f_price, int yy, int mm, int dd, string &p_color) {
//    SetFlowerInfo(f_name, s_name, f_price, yy, mm, dd, p_color);
//}
////设置花卉信息
//void PetalsFlower::SetFlowerInfo(string &f_name, string &s_name, float f_price, int yy, int mm, int dd, string &p_color) {
//    Flower::SetFlowerInfo(f_name, s_name, f_price, yy, mm, dd);
//    petal_color = p_color;
//}
////修改观花植物花瓣颜色
//void PetalsFlower::ModifyPetalColor(const string &p_color) {
//    petal_color = p_color;
//}
////返回观花植物花瓣颜色
//const string& PetalsFlower::PetalColorInfo() const {
//    return petal_color;
//}
//观花花类*****************************************************************


//既观花又观叶类************************************************************
////默认构造函数
//FPFlower::FPFlower() {
//    //初始化调用基类默认构造函数
//}
////进行初始化的构造函数
//FPFlower::FPFlower(string &f_name, string &s_name, float f_price, int yy, int mm, int dd, string &p_color, string &l_color) {
//    Flower::SetFlowerInfo(f_name, s_name, f_price, yy, mm, dd);
//    ModifyPetalColor(p_color);
//    ModifyLeafColor(l_color);
//}
////既观花又观叶类************************************************************
