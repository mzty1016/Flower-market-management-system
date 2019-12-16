//
//  Menu.cpp
//  基于青岛市枯桃花卉市场的交易管理系统
//
//  Created by 🍓XJK on 2019/12/13.
//  Copyright © 2019 🍓XJK. All rights reserved.
//

#include "Menu.hpp"
#include "Hash.hpp"
extern HashTable hashtable;

//默认构造函数
MainMenu::MainMenu() { }
//输出菜单头部
void MainMenu::ShowMenuHead() {
    cout << "==" << endl;
}
//输出菜单底部
void MainMenu::ShowMenuBottom() {
    cout << "__" << endl;
}
void MainMenu::ShowError() {
    cout << "无效的输入，请重新输入" << endl;
}
//接收指令
char MainMenu::Input() {
    char ch;
    cin>>ch;
    fflush(stdin);
    return ch;
}
//输出主菜单信息
void MainMenu::ShowMenuInfo() {
    cout << "1.买家入口" <<endl;
    cout << "2.商家入口" <<endl;
    cout << "3.管理员入口" <<endl;
    cout << "4.退出系统" <<endl;
}
//主菜单运行
void MainMenu::MenuRun() {
    ShowMenuHead();
    ShowMenuInfo();
    ShowMenuBottom();
    char ch = Input();
    PurchaserLogMenu purchaser_log_menu;
    MerchantLogMenu merchant_log_menu;
    switch (ch) {
        case '1': //买家登录、注册入口
            purchaser_log_menu.MenuRun();
            break;
        case '2': //商家入驻、登录入口
            merchant_log_menu.MenuRun();
            MenuRun();
            break;
        case '3': //管理员入口
            cout << "管理员入口" << endl;
            break;
        case '4': //退出系统
            exit(0);
        default: //应对异常输入
            ShowError();
            MenuRun();
    }
}
//输出商家入驻、登录菜单
void MerchantLogMenu::ShowMenuInfo() {
    cout << "1.商家登录" <<endl;
    cout << "2.商家入驻" <<endl;
    cout << "3.返回" <<endl;
    cout << "4.退出系统" <<endl;
}
//商家入驻、登录菜单运行
void MerchantLogMenu::MenuRun() {
    ShowMenuHead();
    ShowMenuInfo();
    ShowMenuBottom();
    char ch = Input();
    Merchant merchant;
    MerchantDoMenu merchant_do_menu;
    switch (ch) {
        case '1': //商家登录
            merchant = merchant.Loggin();
            if (merchant.IsLogSuccess())
                merchant_do_menu.MenuRun(merchant);
            MenuRun();
            break;
        case '2': //商家入驻
            merchant.Logging();
            MenuRun();
            break;
        case '3': //返回主菜单
            return ;
        case '4': //退出系统
            exit(0);
        default: //应对异常输入
            ShowError();
            MenuRun();
    }
}
//输出商家操作菜单
void MerchantDoMenu::ShowMenuInfo() {
    cout << "1.查看上架花卉" <<endl;
    cout << "2.花卉上架" <<endl;
    cout << "3.花卉下架" <<endl;
    cout << "4.花卉信息修改" <<endl;
    cout << "5.花卉自动折扣" <<endl;
    cout << "6.返回" <<endl;
    cout << "7.退出系统" <<endl;
}
//商家操作菜单运行
void MerchantDoMenu::MenuRun(const Merchant &merchant) {
    ShowMenuHead();
    ShowMenuInfo();
    ShowMenuBottom();
    char ch = Input();
    switch (ch) {
        case '1': //查看上架花卉
            merchant.CheckFlower();
            MenuRun(merchant);
            break;
        case '2': //花卉上架
            merchant.AddFlower();
            MenuRun(merchant);
            break;
        case '3': //花卉下架
            merchant.DeleteFlower();
            MenuRun(merchant);
        case '4': //花卉信息修改
            merchant.ModifyFlowerInfo();
            MenuRun(merchant);
        case '5': //花卉自动折扣
            merchant.AutoDiscountFlower();
            MenuRun(merchant);
        case '6': //返回上级菜单
            return ;
        case '7': //退出系统
            exit(0);
        default: //应对异常输入
            ShowError();
            MenuRun(merchant);
    }
}
//输出买家注册、登录菜单
void PurchaserLogMenu::ShowMenuInfo() {
    cout << "1.买家登录" <<endl;
    cout << "2.买家注册" <<endl;
    cout << "3.返回" <<endl;
    cout << "4.退出系统" <<endl;
}
//商家入驻、登录菜单运行
void PurchaserLogMenu::MenuRun() {
    ShowMenuHead();
    ShowMenuInfo();
    ShowMenuBottom();
    char ch = Input();
    Purchaser purchaser;
    PurchaserDoMenu purchaser_do_menu;
    switch (ch) {
        case '1': //买家登录
            purchaser = purchaser.Loggin();
            if (purchaser.IsLogSuccess())
                purchaser_do_menu.MenuRun(purchaser);
            MenuRun();
            break;
        case '2': //买家注册
            purchaser.Logging();
            MenuRun();
            break;
        case '3': //返回主菜单
            return ;
        case '4': //退出系统
            exit(0);
        default: //应对异常输入
            ShowError();
            MenuRun();
    }
}
//输出买家操作菜单
void PurchaserDoMenu::ShowMenuInfo() {
    cout << "1.查看所有上架花卉" <<endl;
    cout << "2.查找花卉" <<endl;
    cout << "3.花卉预约" <<endl;
    cout << "4.查看预约" <<endl;
    cout << "5.花卉推荐" <<endl;
    cout << "6.花店地址导航" <<endl;
    cout << "7.返回" <<endl;
    cout << "8.退出系统" <<endl;
    
}
//买家操作菜单运行
void PurchaserDoMenu::MenuRun(const Purchaser &purchaser) {
    ShowMenuHead();
    ShowMenuInfo();
    ShowMenuBottom();
    char ch = Input();
    switch (ch) {
        case '1': //查看所有上架花卉
            purchaser.CheckALLFlower();
            MenuRun(purchaser);
            break;
        case '2': //查找花卉
            purchaser.SearchFlower();
            MenuRun(purchaser);
            break;
        case '3': //花卉预约
            purchaser.ReserveFlower();
            MenuRun(purchaser);
        case '4': //查看预约
            purchaser.CheckReservation();
            MenuRun(purchaser);
        case '5': //花卉推荐
            
            MenuRun(purchaser);
        case '6': //花店地址导航
            
            MenuRun(purchaser);
        case '7': //返回上级菜单
            return ;
        case '8': //退出系统
            exit(0);
        default: //应对异常输入
            ShowError();
            MenuRun(purchaser);
    }
}
