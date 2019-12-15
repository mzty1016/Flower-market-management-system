//
//  User.hpp
//  基于青岛市枯桃花卉市场的交易管理系统
//
//  Created by 🍓XJK on 2019/12/13.
//  Copyright © 2019 🍓XJK. All rights reserved.
//

#ifndef User_hpp
#define User_hpp

#include <iostream>
#include <string>

#include "Global.hpp"
#include "Flower.hpp"
#include "Hash.hpp"

using namespace std;

//用户类
class User {
 public:
    User(); //默认构造函数
    User(const string &user_name, const string &password); //构造函数
 private:
    string user_name; //用户名
    string password; //密码
};

//商家类，继承用户类
class Merchant : virtual public User {
 public:
    Merchant();  //默认构造函数
    Merchant(const string &user_name, const string &password);
    bool Logging(); //商家入驻,入驻成功返回true，失败返回false
    bool Loggin(); //商家登录,登陆成功返回true，失败返回false
    void CheckFlower(); //查看自家上架花卉
    void AddFlower(); //上架花卉
    void DeleteFlower(); //下架花卉
    void ModifyFlowerInfo(); //修改花卉信息
    void AutoDiscountFlower(); //花卉自动折扣
 private:
    string shop_name; //花店名
};

//买家类,继承用户类
class Purchaser : virtual public User {
 public:
    Purchaser();  //默认构造函数
    Purchaser(const string &user_name, const string &password);
    bool Logging(); //买家注册，注册成功返回true，失败返回false
    bool Loggin(); //买家登录，登录成功返回true，失败返回false
    void CheckFlower(); //查看所有商家花卉
    void SearchFlower(); //查找花卉
    void SortFlower(); //花卉排序
    void ReserveFlower(); //花卉预约
    void CheckReservation(); //查看预约
    void RecommendFlower(); //花卉推荐
    void NavigateShopAddress(); //花店地址导航
 private:
    LNode *LinkList; //存放预约的花卉的链表
};

//管理员类,可进行任何操作,方便对系统进行测试，继承买家、卖家类，此时买家卖家类要设置虚基类
class Admin : public Merchant, public Purchaser {
 public:
    Admin();
    bool Loggin(); //管理员登录，登录成功返回true，失败返回false
    void Announce(); //发布公告
    void SetAd(); //设置广告
    void RetrievePassword(); //找回密码
    void ClearLeftAd(); //清空左广告栏并显示: 广告位招租
    void ClearrightAd(); //清空右广告栏并显示: 广告位招租
    void ClearAnnouncement(); //清空公告
 private:
    const string admin_password = ADMINPASSERWORD; //管理员密码
};

#endif /* User_hpp */
