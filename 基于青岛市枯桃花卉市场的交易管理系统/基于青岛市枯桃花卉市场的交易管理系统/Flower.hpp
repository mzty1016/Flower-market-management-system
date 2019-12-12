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

//花类
class Flower {
 public:
    Flower(); //默认构造函数
    Flower(string &f_name, string &s_name, string &p_color, string &l_color, float f_price, int yy, int mm, int dd);//进行初始化的构造函数
    virtual void SetFlowerInfo(string &f_name, string &s_name, string &p_color, string &l_color, float f_price, int yy, int mm, int dd); //设置花卉信息
    void ModifyFlowerPrice(const float &f_price); //修改花卉价格
    void ModifyFlowerDate(const FlowerDate &f_date); //修改花卉上架日期
    void ModifyPetalColor(const string &p_color); //修改花卉的花瓣颜色
    void ModifyLeafColor(const string &l_color); //修改花卉的叶子颜色
    const string& FlowerNameInfo() const; //返回花卉名称
    const string& ShopNameInfo() const; //返回花卉所在的店名
    const string& PetalColorInfo() const; //返回花卉的花瓣颜色
    const string& LeafColorInfo() const; //返回花卉的叶子颜色
    const float& FlowerPriceInfo() const; //返回花卉价格
    const FlowerDate& FlowerDateInfo() const; //返回花卉上架日期
 private:
    string flower_name; //花卉名称
    string shop_name; //花卉所在的店名
    string petal_color; //花卉花瓣颜色
    string leaf_color; //花卉叶子颜色
    float flower_price; //花卉价格
    FlowerDate flower_date; //花卉上架日期
};


////花类派生出观叶花类
//class FoliageFlower : virtual public Flower {
// public:
//    FoliageFlower(); //默认构造函数
//    FoliageFlower(string &f_name, string &s_name, float f_price, int yy, int mm, int dd, string &l_color); //进行初始化的构造函数
//    void SetFlowerInfo1(string &f_name, string &s_name, float f_price, int yy, int mm, int dd, string &l_color); //设置花卉信息
//    void ModifyLeafColor(const string &l_color); //修改观叶植物叶子颜色
//    const string& LeafColorInfo() const; //返回观叶植物的叶子颜色
// private:
//    string leaf_color;
//};


////花类派生出观花花类
//class PetalsFlower : virtual public Flower {
// public:
//    PetalsFlower(); //默认构造函数
//    PetalsFlower(string &f_name, string &s_name, float f_price, int yy, int mm, int dd, string &p_color); //进行初始化的构造函数
//    void SetFlowerInfo(string &f_name, string &s_name, float f_price, int yy, int mm, int dd, string &p_color); //设置花卉信息
//    void ModifyPetalColor(const string &p_color); //修改观花植物花瓣颜色
//    const string& PetalColorInfo() const; //返回观花植物的花瓣颜色
// private:
//    string petal_color;
//};

////观花类和观叶类派生出既观花又观叶类，此时观花和观叶类要设置虚基类
//class FPFlower : public PetalsFlower, public FoliageFlower{
// public:
//    FPFlower();
//    FPFlower(string &f_name, string &s_name, float f_price, int yy, int mm, int dd, string &p_color, string &l_color);
//    void SetFlowerInfo(string &f_name, string &s_name, float f_price, int yy, int mm, int dd, string &l_color, string &p_color); //设置花卉信息
//};

#endif /* Flower_hpp */
