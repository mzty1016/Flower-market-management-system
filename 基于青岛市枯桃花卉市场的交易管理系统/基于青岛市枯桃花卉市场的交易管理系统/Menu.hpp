//
//  Menu.hpp
//  基于青岛市枯桃花卉市场的交易管理系统
//
//  Created by 🍓XJK on 2019/12/13.
//  Copyright © 2019 🍓XJK. All rights reserved.
//

#ifndef Menu_hpp
#define Menu_hpp

#include <iostream>

#include "Merchant.hpp"
#include "Purchaser.hpp"
#include "Admin.hpp"

//（主）菜单类
class MainMenu {
 public:
    MainMenu();
    void LoadAd(); //加载广告
    void LoadAnnouncement(); //加载公告
    void ShowMenuHead(); //输出菜单头部
    void ShowMenuInfo(); //输出菜单内容
    void ShowMenuBottom(); //输出菜单底部
    void ShowAd(char ad[]); //输出广告内容
    void ShowAnnouncement(char an[]); //输出公告
    void ShowError(); //输出异常信息
    void ShowVersion(); //输出版本信息
    void MenuRun(); //运行菜单
    char Input(); //从键盘接收指令
};

//商家登录注册菜单类，继承菜单类
class MerchantLogMenu : public MainMenu {
 public:
    void ShowMenuInfo(); //输出菜单内容
    void MenuRun(); //运行菜单
};
//商家操作菜单类，继承菜单类
class MerchantDoMenu : public MainMenu {
 public:
    void ShowMenuInfo(); //输出菜单内容
    void MenuRun(const Merchant &merchant); //运行菜单
};

//买家登录注册菜单类，继承菜单类
class PurchaserLogMenu : public MainMenu {
 public:
    int extracted();
    
    void ShowMenuInfo(); //输出菜单内容
    void MenuRun(); //运行菜单
};
//买家操作菜单类，继承菜单类
class PurchaserDoMenu : public MainMenu {
 public:
    void ShowMenuInfo(); //输出菜单内容
    void MenuRun(const Purchaser &purchaser); //运行菜单
};
//管理员登录菜单类，继承菜单类
class AdminLogMenu : public MainMenu {
public:
    void ShowMenuInfo(); //输出菜单内容
    void MenuRun(); //运行菜单
};
//管理员操作菜单类，继承菜单类
class AdminDoMenu : public MainMenu {
public:
    void ShowMenuInfo(); //输出菜单内容
    void MenuRun(); //运行菜单
};


#endif /* Menu_hpp */
